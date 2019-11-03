#include "GoProCommand.h"

#include "http/HTTPRequest.h"

const std::string& GoProCommand::m_URL		= "10.5.5.9";
const std::string& GoProCommand::m_Port		= "80";
const std::string& GoProCommand::m_Prefix	= "/gp";

GoProCommand::~GoProCommand()
{

}

void GoProCommand::Submit()
{
	const std::string hostname  = this->m_URL;
	const std::string port		= this->m_Port;
	const std::string target	= this->m_Prefix + this->m_CommandType + this->m_ControlType + this->m_Suffix;

	HTTPRequest  command_request(hostname, port, target);
	HTTPResponse command_response = command_request.Submit();
}
