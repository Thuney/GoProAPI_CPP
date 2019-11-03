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

		void TakePicture();

		void SetResolution(GoProResolution::Resolution new_resolution);
		void SetFrameRate();
		void SetFOV();
		void SetOrientation();
		void SetMode(GoProMode::Mode new_mode);

		void SetLCDLock();
		void SetLCDTimeout();
		void SetAutoOff();

		void SetLEDBlinkInterval();
		void SetBeeps();
		
	private:

		void Init();

};