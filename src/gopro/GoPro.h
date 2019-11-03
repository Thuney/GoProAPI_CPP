#pragma once

#include "GoProCommand.h"

class GoPro
{

	public:

		GoPro()
		{
			this->Init();
		};

		~GoPro()
		{

		};

		const std::string GetCameraStatus();

		void ControlShutter(const GoProShutter::Shutter shutterProp);

		void SetResolution(const GoProResolution::Resolution resolutionProp);
		void SetFrameRate(const GoProFrameRate::FrameRate frameRateProp);
		void SetFOV(const GoProFOV::FOV fovProp);
		void SetOrientation(const GoProOrientation::Orientation orientationProp);
		void SetMode(const GoProMode::Mode modeProp);

		void SetLCDLock(const GoProLCDLock::LCDLock lcdLockProp);
		void SetLCDTimeout(const GoProLCDTimeout::LCDTimeout lcdTimeoutProp);
		void SetAutoOff(const GoProAutoOff::AutoOff autoOffProp);

		void SetLEDBlinkInterval(const GoProLEDBlinkInterval::LEDBlinkInterval ledBlinkIntervalProp);
		void SetBeeps(const GoProBeepProperty::Beep beepProp);
		
	private:

		void Init();

};