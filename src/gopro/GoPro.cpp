#include "GoPro.h"

#include <iostream>

void GoPro::Init()
{

}

const std::string GoPro::GetCameraStatus(const GoProStatus::Status statusProp)
{
	GoProStatus status_property;
	std::string response = GoProPropertyCommand(status_property, statusProp).Submit();

	std::cout << response << std::endl;

	return response;
}

void GoPro::ControlShutter(const GoProShutter::Shutter shutterProp)
{
	GoProShutter shutter_property;
	std::string response = GoProPropertyCommand(shutter_property, shutterProp).Submit();
}

void GoPro::SetResolution(const GoProResolution::Resolution resolutionProp)
{
	GoProResolution resolution_property;
	std::string response = GoProPropertyCommand(resolution_property, resolutionProp).Submit();
}

void GoPro::SetFrameRate(const GoProFrameRate::FrameRate frameRateProp)
{
	GoProFrameRate frame_rate_property;
	std::string response = GoProPropertyCommand(frame_rate_property, frameRateProp).Submit();
}

void GoPro::SetFOV(const GoProFOV::FOV fovProp)
{
	GoProFOV fov_property;
	std::string response = GoProPropertyCommand(fov_property, fovProp).Submit();
}

void GoPro::SetOrientation(const GoProOrientation::Orientation orientationProp)
{
	GoProOrientation orientation_property;
	std::string response = GoProPropertyCommand(orientation_property, orientationProp).Submit();
}

void GoPro::SetMode(const GoProMode::Mode new_mode)
{
	GoProMode mode_property;
	std::string response = GoProPropertyCommand(mode_property, new_mode).Submit();
}

void GoPro::SetLCDLock(const GoProLCDLock::LCDLock lcdLockProp)
{
	GoProLCDLock lcd_lock_property;
	std::string response = GoProPropertyCommand(lcd_lock_property, lcdLockProp).Submit();
}

void GoPro::SetLCDTimeout(const GoProLCDTimeout::LCDTimeout lcdTimeoutProp)
{
	GoProLCDTimeout lcd_timeout_property;
	std::string response = GoProPropertyCommand(lcd_timeout_property, lcdTimeoutProp).Submit();
}

void GoPro::SetAutoOff(const GoProAutoOff::AutoOff autoOffProp)
{
	GoProAutoOff auto_off_property;
	std::string response = GoProPropertyCommand(auto_off_property, autoOffProp).Submit();
}

void GoPro::SetLEDBlinkInterval(const GoProLEDBlinkInterval::LEDBlinkInterval ledBlinkIntervalProp)
{
	GoProLEDBlinkInterval led_blink_interval_property;
	std::string response = GoProPropertyCommand(led_blink_interval_property, ledBlinkIntervalProp).Submit();
}

void GoPro::SetBeeps(const GoProBeepProperty::Beep beepProp)
{
	GoProBeepProperty beep_property;
	std::string response = GoProPropertyCommand(beep_property, beepProp).Submit();
}
