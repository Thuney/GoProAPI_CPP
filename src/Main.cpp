//#include <iostream>

#include "gopro/GoPro.h"

int main(int argc, char** argv)
{
	GoPro go_pro;
	go_pro.SetMode(GoProMode::VIDEO);

	return 0;
}