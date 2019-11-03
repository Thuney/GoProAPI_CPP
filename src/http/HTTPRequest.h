#pragma once

#include <string>
#include <iostream>

// boost::beast depends on boost::asio,
// so boost:asio headers must come first
#include <boost/asio/connect.hpp>
#include <boost/asio/ip/tcp.hpp>

#include <boost/beast/http.hpp>

#include "HTTPResponse.h"

namespace beast	= boost::beast;				// From <boost/beast.hpp>
namespace http	= beast::http;				// From <boost/beast/http.hpp>
namespace net	= boost::asio;				// From <boost/asio.hpp>
using tcp		= net::ip::tcp;				// From <boost/asio/ip/tcp.hpp>


// Forward declarations
net::io_context;
tcp::resolver;
tcp::socket;
http::request<http::empty_body>;


enum class HTTPMethod
{
	GET		= (int) http::verb::get,
	POST	= (int) http::verb::post,
	PUT		= (int) http::verb::put,
	HEAD	= (int) http::verb::head,
	DEL		= (int) http::verb::delete_,
	PATCH	= (int) http::verb::patch,
	OPTIONS = (int) http::verb::options
};

class HTTPRequest
{

	public:

		HTTPRequest(const std::string& hostname, const std::string& port, const std::string& target, const HTTPMethod method = HTTPMethod::GET, const int version = 11)
		{
			this->m_Hostname = hostname;
			this->m_Port	 = port;
			this->m_Target	 = target;

			this->m_Method   = method;

			this->m_Version  = version;

			Init();
		};

		~HTTPRequest()
		{
			delete this->m_Request;
		};
		
		// Submit this HTTPRequest and return 
		// the resulting HTTPResponse
		HTTPResponse Submit();

	private:

		std::string m_Hostname, m_Port, m_Target;
		HTTPMethod m_Method;
		int m_Version;

		http::request<http::empty_body>* m_Request;

		// The io_context is required for all I/O
		static net::io_context* m_IOContext;

		// These objects perform our I/O
		static tcp::resolver* m_Resolver;
		static tcp::socket* m_Socket;

		void Init();

};
