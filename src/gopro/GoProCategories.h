#include <string>

class GoPro_CommandType
{

	public:

		enum CommandType
		{
			None,						// No command type
			CameraControl				// Command affects camera settings
		};

		static std::string AsCommandFragment(CommandType c)
		{
			std::string command_fragment;

			switch (c)
			{
			case None:
				command_fragment = "";
				break;
			case CameraControl:
				command_fragment = "/gpControl";
				break;
			default:
				command_fragment = nullptr;
			}

			return command_fragment;
		};
};

class GoPro_ControlType
{

	public:

		enum ControlType
		{
			None,						// No control type
			CameraStatus,				// Current camera settings, etc.
			CameraDisplaySettings,		// Settings affecting display. E.G. Resolution, Frame Rate, FOV
			CameraModeControl,			// Switching between Video, Photo, Multishot, etc.
			CameraShutterControl		// Shutter control. Taking photos / Stopping recording
		};

		static std::string AsCommandFragment(ControlType c)
		{
			std::string command_fragment;

			switch (c)
			{
			case None:
				command_fragment = "";
				break;
			case CameraStatus:
				command_fragment = "/status";
				break;
			case CameraDisplaySettings:
				command_fragment = "/setting";
				break;
			case CameraModeControl:
				command_fragment = "/command/mode";
				break;
			case CameraShutterControl:
				command_fragment = "/command/shutter";
				break;
			default:
				command_fragment = nullptr;
			}

			return command_fragment;
		};
};




class GoProProperty
{
	public:

		GoProProperty()
		{

		};

		virtual const std::string AsCommandSuffix(const int prop)
		{
			return "";
		};

		GoPro_CommandType::CommandType m_CommandType = GoPro_CommandType::None;
		GoPro_ControlType::ControlType m_ControlType = GoPro_ControlType::None;
};

class GoProResolution : public GoProProperty
{
	public:

		enum Resolution
		{
			RESOLUTION_4K,				// 4K
			RESOLUTION_2_7K,			// 2.7K
			RESOLUTION_1440P,			// 1440P
			RESOLUTION_1080P,			// 1080P
			RESOLUTION_720P				// 720P
		};

		GoProResolution()
		{
			this->m_CommandType = GoPro_CommandType::CommandType::CameraControl;
			this->m_ControlType = GoPro_ControlType::ControlType::CameraDisplaySettings;
		}

		virtual const std::string AsCommandSuffix(const int prop) override
		{
			std::string command_suffix;

			switch ( (Resolution) prop )
			{
				case RESOLUTION_4K:
					command_suffix = "/2/1";
					break;
				case RESOLUTION_2_7K:
					command_suffix = "/2/4";
					break;
				case RESOLUTION_1440P:
					command_suffix = "/2/7";
					break;
				case RESOLUTION_1080P:
					command_suffix = "/2/9";
					break;
				case RESOLUTION_720P:
					command_suffix = "/2/12";
					break;
				default:
					command_suffix = nullptr;
			}

			return command_suffix;
		}
};

class GoProMode : public GoProProperty
{
	public:

		enum Mode
		{
			VIDEO,						// Video recording mode
			PHOTO,						// Still photo mode
			MULTISHOT					// Multishot (Timelapse, etc.)
		};

		GoProMode()
		{
			this->m_CommandType = GoPro_CommandType::CommandType::CameraControl;
			this->m_ControlType = GoPro_ControlType::ControlType::CameraModeControl;
		}

		virtual const std::string AsCommandSuffix(const int prop) override
		{
			std::string command_suffix;

			switch ( (Mode) prop )
			{
				case VIDEO:
					command_suffix = "?p=0";
					break;
				case PHOTO:
					command_suffix = "?p=1";
					break;
				case MULTISHOT:
					command_suffix = "?p=2";
					break;
				default:
					command_suffix = nullptr;
			}

			return command_suffix;
		}
};