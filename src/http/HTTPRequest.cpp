#include "HTTPRequest.h"

#include <boost/beast/version.hpp>
#include <boost/asio/connect.hpp>
#include <boost/asio/ip/tcp.hpp>

#include <iostream>

namespace net	= boost::asio;				// From <boost/asio.hpp>
using tcp		= net::ip::tcp;				// from <boost/asio/ip/tcp.hpp>


void HTTPRequest::Init()
{
	
}

HTTPResponse HTTPRequest::Submit()
{
	try
	{

		// The io_context is required for all I/O
		boost::asio::io_context ioc;

		// These objects perform our I/O
		tcp::resolver resolver
		{ 
			ioc
		};
		tcp::socket socket
		{
			ioc
		};

		// Look up the domain name
		auto const results = resolver.resolve(this->m_Hostname, this->m_Port);

		// Make the connection on the IP address we get from a lookup
		net::connect(socket, results.begin(), results.end());

		// Set up an HTTP GET request message
		// I use an enum wrapper around http:verb to denote HTTP Methods. Since boost::beast functions require http::verb, 
		// we cast the local instance of the HTTPMethod back to that type
		http::request<http::empty_body> req { (http::verb) (this->m_Method), this->m_Target.c_str(), this->m_Version };

		req.set(http::field::host, this->m_Hostname);
		req.set(http::field::user_agent, BOOST_BEAST_VERSION_STRING);

		// Send the HTTP request to the remote host
		http::write(socket, req);

		// This buffer is used for reading and must be persisted
		beast::flat_buffer responseBuffer;

		// Declare a container to hold the response
		http::response<http::string_body> res;

		// Receive the HTTP response
		boost::system::error_code read_ec;
		http::read(socket, responseBuffer, res, read_ec);

		std::string response_data = beast::buffers_to_string(responseBuffer.data());

		// Gracefully close the socket
		boost::system::error_code ec;
		socket.shutdown(tcp::socket::shutdown_both, ec);

		// not_connected happens sometimes
		// so don't bother reporting it.
		//
		if (ec && ec != boost::system::errc::not_connected)
			throw boost::system::system_error{ ec };

		// If we get here then the connection is closed gracefully

		return HTTPResponse(response_data);
	}
	catch (std::exception const& e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
	}
}