#pragma once

#include <iostream>

class HTTPResponse
{
	public:

		HTTPResponse(std::ostream* response_stream)
		{
			this->m_ResponseStream = response_stream;
		};

		~HTTPResponse()
		{
			delete this->m_ResponseStream;
		};

	private:

		std::ostream* m_ResponseStream;


};