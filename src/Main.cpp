//#include <iostream>

#include "gopro/GoPro.h"

int main(int argc, char** argv)
{
	GoPro go_pro;

	go_pro.SetAutoOff(GoProAutoOff::NEVER);
	go_pro.SetLCDLock(GoProLCDLock::OFF);
	go_pro.SetLCDTimeout(GoProLCDTimeout::NEVER);
	go_pro.GetCameraStatus(GoProStatus::STATUS);

	go_pro.SetMode(GoProMode::VIDEO);
	go_pro.SetFrameRate(GoProFrameRate::FPS_60);
	go_pro.SetFOV(GoProFOV::NARROW);

	return 0;
}