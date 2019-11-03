#pragma once

#include <string>

#include <boost/beast/core.hpp>
#include <boost/beast/http.hpp>

#include "HTTPResponse.h"

namespace beast	= boost::beast;				// From <boost/beast.hpp>
namespace http	= beast::http;				// From <boost/beast/http.hpp>

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

		HTTPRequest(const std::string hostname, const std::string port, const std::string target, const HTTPMethod method = HTTPMethod::GET, const int version = 11)
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

		};

		HTTPResponse Submit();

	private:

		std::string m_Hostname, m_Port, m_Target;
		HTTPMethod m_Method;
		int m_Version;

		void Init();

};
