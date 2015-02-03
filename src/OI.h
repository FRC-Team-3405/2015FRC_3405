#ifndef OI_H
#define OI_H

#include "WPILib.h"

#include "Commands/RunCompressor.h"

class OI
{
private:
	Joystick* stick;

	JoystickButton* xboxA;
	JoystickButton* xboxB;
public:
	OI();
};

#endif
