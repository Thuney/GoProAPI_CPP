#pragma once

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

		std::string ToString()
		{
			return this->m_ResponseData;
		}

	private:

		std::string m_ResponseData;

};