#include "GoPro.h"

#include <iostream>

void GoPro::Init()
{

}

const std::string GoPro::GetCameraStatus()
{
	return std::string();
}

void GoPro::TakePicture()
{

}

void GoPro::SetResolution(GoProResolution::Resolution new_resolution)
{
	GoProResolution resolution_property;
	GoProPropertyCommand(resolution_property, new_resolution).Submit();
}

void GoPro::SetFrameRate()
{
}

void GoPro::SetFOV()
{
}

void GoPro::SetOrientation()
{
}

void GoPro::SetMode(GoProMode::Mode new_mode)
{
	GoProMode mode_property;
	std::string response = GoProPropertyCommand(mode_property, new_mode).Submit();
	std::cout << response << std::endl;

}

void GoPro::SetLCDLock()
{
}

void GoPro::SetLCDTimeout()
{
}

void GoPro::SetAutoOff()
{
}

void GoPro::SetLEDBlinkInterval()
{
}

void GoPro::SetBeeps()
{
}
