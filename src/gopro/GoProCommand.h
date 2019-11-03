#pragma once

#include "GoProCategories.h"

class GoProCommand
{

	public:

		GoProCommand()
		{
			
		}

		~GoProCommand();

		std::string Submit();

	protected:

		GoPro_CommandType::CommandType m_CommandType = GoPro_CommandType::None;
		GoPro_ControlType::ControlType m_ControlType = GoPro_ControlType::None;
		std::string m_Suffix = "";

	private:

		static const std::string& m_URL;
		static const std::string& m_Port;
		static const std::string& m_Prefix;
};

// Generic command for executing a command on any GoProProperty,
// given an instance of that property and an enum value that allows
// the command suffix to be determined

class GoProPropertyCommand : public GoProCommand
{
	public:

		GoProPropertyCommand(GoProProperty& prop_obj, const int prop)
		{
			this->m_CommandType = prop_obj.m_CommandType;
			this->m_ControlType = prop_obj.m_ControlType;
			this->m_Suffix		= prop_obj.AsCommandSuffix(prop);
		}
};