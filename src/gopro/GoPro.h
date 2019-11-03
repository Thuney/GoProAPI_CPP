#pragma once

class GoPro
{

	public:

		GoPro();
		~GoPro();


		void TakePicture();

		void SetResolution();
		void SetFrameRate();
		void SetFOV();
		void SetOrientation();
		void SetMode();

		void SetLCDLock();
		void SetLCDTimeout();
		void SetAutoOff();

		void SetLEDBlinkInterval();
		void SetBeeps();
		
	private:

		void Init();

};