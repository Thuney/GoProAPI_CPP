#include "HTTPRequest.h"

#include <iostream>
#include <string>

// boost::beast depends on boost::asio,
// so boost:asio headers must come first
#include <boost/asio/connect.hpp>

#include <boost/beast/version.hpp>
#include <boost/beast/core.hpp>

net::io_context* HTTPRequest::m_IOContext	= new net::io_context;

tcp::resolver* HTTPRequest::m_Resolver		= new tcp::resolver(*(HTTPRequest::m_IOContext));
tcp::socket* HTTPRequest::m_Socket			= new tcp::socket(*(HTTPRequest::m_IOContext));

void HTTPRequest::Init()
{
	// Look up the domain name
	auto const results = this->m_Resolver->resolve(this->m_Hostname, this->m_Port);

	// Make the connection on the IP address we get from a lookup
	net::connect(*(this->m_Socket), results.begin(), results.end());

	// Set up an HTTP GET request message
	// I use an enum wrapper around http:verb to denote HTTP Methods. Since boost::beast functions require http::verb, 
	// we cast the local instance of the HTTPMethod back to that type
	m_Request = new http::request<http::empty_body>((http::verb)(this->m_Method), this->m_Target.c_str(), this->m_Version);

	// Set hostname and 'user agent' of the request
	m_Request->set(http::field::host, this->m_Hostname);
	m_Request->set(http::field::user_agent, BOOST_BEAST_VERSION_STRING);
}

HTTPResponse HTTPRequest::Submit()
{
	try
	{
		// Send the HTTP request to the remote host
		http::write(*(this->m_Socket), *(this->m_Request));

		// This buffer is used for reading and must be persisted <-- From boost::beast example documentation
		// Since I plan to just do simple requests, this buffer is read once and then thrown away, and I
		// can construct it each time without much consequence.
		beast::flat_buffer response_buffer;

		// Declare a container to hold the response
		http::response<http::string_body> response;

		// Receive the HTTP response
		boost::system::error_code read_ec;
		http::read(*(this->m_Socket), response_buffer, response, read_ec);

		// If any error occurs in the read process, log it
		if(read_ec)
			std::cerr << "Error: " << read_ec.message() << std::endl;

		// Convert the buffer contents to a std::string for passing around
		// Can probably replace response_buffer with a string_buffer, but not going to try at the moment
		std::string response_data = beast::buffers_to_string(response_buffer.data());

		// Gracefully close the socket
		boost::system::error_code ec;
		this->m_Socket->shutdown(tcp::socket::shutdown_both, ec);

		// not_connected happens sometimes,
		// so don't bother reporting it
		if (ec && ec != boost::system::errc::not_connected)
			throw boost::system::system_error{ ec };


		// If we get here then the connection is closed gracefully, and the response from the server is returned
		return HTTPResponse(response_data);
	}
	//Generic log of caught exceptions
	catch (std::exception const& e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
	}
}