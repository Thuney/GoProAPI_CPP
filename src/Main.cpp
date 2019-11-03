#include <iostream>

#include "http/HTTPRequest.h"

int main(int argc, char** argv)
{
	std::string host = "10.5.5.9";
	std::string port = "80";
	std::string target = "/gp/gpControl/status";
	int version = 11;

	HTTPRequest request(host, port, target, HTTPMethod::GET, version);
	HTTPResponse response = request.Submit();

	std::cout << response.ToString() << std::endl;

	return 0;
}