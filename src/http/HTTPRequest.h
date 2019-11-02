#pragma once

#include <string>

class HTTPRequest
{

	public:

		enum HTTPMethod
		{
			GET		= http::verb::get,
			POST	= http::verb::post,
			PUT		= http::verb::put,
			HEAD	= http::verb::head,
			DELETE	= http::verb::delete_,
			PATCH	= http::verb::patch,
			OPTIONS = http::verb::options
		};

		HTTPRequest(const std::string hostname, const std::string port, const std::string target, const HTTPMethod method, const const int version = 11)
		{
			this->m_Hostname = hostname;
			this->m_Port = port;
			this->m_Target = target;

			this->m_Method = method;

			Init();
		};

		~HTTPRequest()
		{

		};

		bool Send();

	private:

		std::string m_Hostname, m_Port, m_Target;
		HTTPMethod m_Method;

		void Init();

};
