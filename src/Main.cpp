#include <iostream>

#include "gopro/GoPro.h"

int main(int argc, char** argv)
{
	GoPro go_pro;

	char c;
	std::cin >> c;

	while (c != 'q')
	{
		switch (c)
		{
			case 'p':
				go_pro.SetMode(GoProMode::PHOTO);
				break;

			case 'v':
				go_pro.SetMode(GoProMode::VIDEO);
				break;

			case 'c':
				go_pro.ControlShutter(GoProShutter::TRIGGER);
				break;

			case 'e':
				go_pro.ControlShutter(GoProShutter::STOP_RECORDING);
				break;

			case 'o':
				go_pro.SetLCDLock(GoProLCDLock::ON);
				break;

			case 's':
				go_pro.GetCameraStatus(GoProStatus::STATUS);
				break;

			case 'n':
				go_pro.SetResolution(GoProResolution::RESOLUTION_720P);
				break;

			case 'm':
				go_pro.SetResolution(GoProResolution::RESOLUTION_1080P);
				break;

			default:
				break;
		}
		std::cin >> c;
	}

	return 0;
}