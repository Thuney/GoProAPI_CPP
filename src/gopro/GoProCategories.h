#pragma once

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

class GoProStatus : public GoProProperty
{
	public:

		enum Status
		{
			STATUS
		};

		GoProStatus()
		{
			this->m_CommandType = GoPro_CommandType::CommandType::CameraControl;
			this->m_ControlType = GoPro_ControlType::ControlType::CameraStatus;
		}

		virtual const std::string AsCommandSuffix(const int prop) override
		{
			std::string command_suffix;

			switch ((Status) prop)
			{
			case STATUS:
				command_suffix = "";
				break;
			default:
				command_suffix = nullptr;
			}

			return command_suffix;
		}
};

class GoProShutter : public GoProProperty
{
	public:

		enum Shutter
		{
			TRIGGER,
			STOP_RECORDING
		};

		GoProShutter()
		{
			this->m_CommandType = GoPro_CommandType::CommandType::CameraControl;
			this->m_ControlType = GoPro_ControlType::ControlType::CameraShutterControl;
		}

		virtual const std::string AsCommandSuffix(const int prop) override
		{
			std::string command_suffix;

			switch ((Shutter) prop)
			{
				case TRIGGER:
					command_suffix = "?p=1";
					break;
				case STOP_RECORDING:
					command_suffix = "?p=0";
					break;
				default:
					command_suffix = nullptr;
			}

			return command_suffix;
		}
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

class GoProFrameRate : public GoProProperty
{
	public:

		enum FrameRate
		{
			FPS_120,		// 120fps
			FPS_90,			// 90fps
			FPS_60,			// 60fps
			FPS_48,			// 48fps
			FPS_30			// 30fps
		};

		GoProFrameRate()
		{
			this->m_CommandType = GoPro_CommandType::CommandType::CameraControl;
			this->m_ControlType = GoPro_ControlType::ControlType::CameraDisplaySettings;
		}

		virtual const std::string AsCommandSuffix(const int prop) override
		{
			std::string command_suffix;

			switch ((FrameRate) prop)
			{
				case FPS_120:
					command_suffix = "/3/1";
					break;
				case FPS_90:
					command_suffix = "/3/3";
					break;
				case FPS_60:
					command_suffix = "/3/5";
					break;
				case FPS_48:
					command_suffix = "/3/7";
					break;
				case FPS_30:
					command_suffix = "/3/8";
					break;
				default:
					command_suffix = nullptr;
			}

			return command_suffix;
		}
};

class GoProOrientation : public GoProProperty
{
	public:

		enum Orientation
		{
			UP,
			DOWN,
			GYRO_BASED
		};

		GoProOrientation()
		{
			this->m_CommandType = GoPro_CommandType::CommandType::CameraControl;
			this->m_ControlType = GoPro_ControlType::ControlType::CameraDisplaySettings;
		}

		virtual const std::string AsCommandSuffix(const int prop) override
		{
			std::string command_suffix;

			switch ((Orientation) prop)
			{
				case UP:
					command_suffix = "/52/1";
					break;
				case DOWN:
					command_suffix = "/52/2";
					break;
				case GYRO_BASED:
					command_suffix = "/52/0";
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

class GoProFOV : public GoProProperty
{
	public:

		enum FOV
		{
			WIDE,						
			MEDIUM,						
			NARROW,
			LINEAR						
		};

		GoProFOV()
		{
			this->m_CommandType = GoPro_CommandType::CommandType::CameraControl;
			this->m_ControlType = GoPro_ControlType::ControlType::CameraDisplaySettings;
		}

		virtual const std::string AsCommandSuffix(const int prop) override
		{
			std::string command_suffix;

			switch ((FOV) prop)
			{
				case WIDE:
					command_suffix = "/4/0";
					break;
				case MEDIUM:
					command_suffix = "/4/1";
					break;
				case NARROW:
					command_suffix = "/4/2";
					break;
				case LINEAR:
					command_suffix = "/4/4";
					break;
				default:
					command_suffix = nullptr;
			}

			return command_suffix;
		}
};


class GoProLCDTimeout : public GoProProperty
{
	public:

		enum LCDTimeout
		{
			NEVER,
			ONE_MIN,
			TWO_MIN,
			THREE_MIN
		};

		GoProLCDTimeout()
		{
			this->m_CommandType = GoPro_CommandType::CommandType::CameraControl;
			this->m_ControlType = GoPro_ControlType::ControlType::CameraDisplaySettings;
		}

		virtual const std::string AsCommandSuffix(const int prop) override
		{
			std::string command_suffix;

			switch ((LCDTimeout) prop)
			{
				case NEVER:
					command_suffix = "/51/0";
					break;
				case ONE_MIN:
					command_suffix = "/51/1";
					break;
				case TWO_MIN:
					command_suffix = "/51/2";
					break;
				case THREE_MIN:
					command_suffix = "/51/3";
					break;
				default:
					command_suffix = nullptr;
			}

			return command_suffix;
		}
};

class GoProLCDLock : public GoProProperty
{
	public:

		enum LCDLock
		{
			ON,
			OFF
		};

		GoProLCDLock()
		{
			this->m_CommandType = GoPro_CommandType::CommandType::CameraControl;
			this->m_ControlType = GoPro_ControlType::ControlType::CameraDisplaySettings;
		}

		virtual const std::string AsCommandSuffix(const int prop) override
		{
			std::string command_suffix;

			switch ((LCDLock) prop)
			{
				case ON:
					command_suffix = "/50/1";
					break;
				case OFF:
					command_suffix = "/50/0";
					break;
				default:
					command_suffix = nullptr;
			}

			return command_suffix;
		}
};

class GoProAutoOff : public GoProProperty
{
	public:

		enum AutoOff
		{
			NEVER,
			ONE_MIN,
			TWO_MIN,
			THREE_MIN,
			FIVE_MIN
		};

		GoProAutoOff()
		{
			this->m_CommandType = GoPro_CommandType::CommandType::CameraControl;
			this->m_ControlType = GoPro_ControlType::ControlType::CameraDisplaySettings;
		}

		virtual const std::string AsCommandSuffix(const int prop) override
		{
			std::string command_suffix;

			switch ((AutoOff) prop)
			{
				case NEVER:
					command_suffix = "/59/0";
					break;
				case ONE_MIN:
					command_suffix = "/59/1";
					break;
				case TWO_MIN:
					command_suffix = "/59/2";
					break;
				case THREE_MIN:
					command_suffix = "/59/3";
					break;
				case FIVE_MIN:
					command_suffix = "/59/4";
					break;
				default:
					command_suffix = nullptr;
			}

			return command_suffix;
		}
};

class GoProLEDBlinkInterval : public GoProProperty
{
	public:

		enum LEDBlinkInterval
		{
			TWO,
			FOUR,
			OFF
		};

		GoProLEDBlinkInterval()
		{
			this->m_CommandType = GoPro_CommandType::CommandType::CameraControl;
			this->m_ControlType = GoPro_ControlType::ControlType::CameraDisplaySettings;
		}

		virtual const std::string AsCommandSuffix(const int prop) override
		{
			std::string command_suffix;

			switch ((LEDBlinkInterval) prop)
			{
				case TWO:
					command_suffix = "/55/1";
					break;
				case FOUR:
					command_suffix = "/55/2";
					break;
				case OFF:
					command_suffix = "/55/0";
					break;
				default:
					command_suffix = nullptr;
			}

			return command_suffix;
		}
};

class GoProBeepProperty : public GoProProperty
{
	public:

		enum Beep
		{
			OFF,
			POINT_SEVEN,
			FULL
		};

		GoProBeepProperty()
		{
			this->m_CommandType = GoPro_CommandType::CommandType::CameraControl;
			this->m_ControlType = GoPro_ControlType::ControlType::CameraDisplaySettings;
		}

		virtual const std::string AsCommandSuffix(const int prop) override
		{
			std::string command_suffix;

			switch ((Beep) prop)
			{
				case OFF:
					command_suffix = "/56/2";
					break;
				case POINT_SEVEN:
					command_suffix = "/56/1";
					break;
				case FULL:
					command_suffix = "/56/0";
					break;
				default:
					command_suffix = nullptr;
			}

			return command_suffix;
		}
};