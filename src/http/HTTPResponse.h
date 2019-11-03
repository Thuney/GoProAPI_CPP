#pragma once

#include <iostream>

class HTTPResponse
{
	public:

		HTTPResponse(const std::string& response_data)
		{
			this->m_ResponseData = response_data;
		};

		~HTTPResponse()
		{

		};

		std::string GetResponseData()
		{
			return this->m_ResponseData;
		}

	private:

		std::string m_ResponseData;


};