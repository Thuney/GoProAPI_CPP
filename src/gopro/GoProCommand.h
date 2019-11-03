#pragma once

#include <string>

class GoProCommand
{

	public:

		GoProCommand(const std::string& command_type, const std::string& control_type, const std::string& suffix)
					 : m_CommandType(command_type), m_ControlType(control_type), m_Suffix(suffix)
		{

		}

		~GoProCommand();

		void Submit();

	private:

		static const std::string& m_URL;
		static const std::string& m_Port;
		static const std::string& m_Prefix;

		const std::string& m_CommandType;
		const std::string& m_ControlType;
		const std::string& m_Suffix;
};