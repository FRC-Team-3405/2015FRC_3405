#ifndef OI_H
#define OI_H

#include "WPILib.h"

#include "CommandList.h"

class OI
{
private:
	Joystick* xbox;
	Joystick* gamepad;

	JoystickButton* xboxA;
	JoystickButton* xboxB;
	JoystickButton* xboxX;
	JoystickButton* xboxY;
	JoystickButton* xboxBumperLeft;
	JoystickButton* xboxBumperRight;
	JoystickButton* xboxBack;
	JoystickButton* xboxStart;

	JoystickButton *gamepad1;

public:
	OI();
	Joystick* GetJoystick();
	Joystick* GetGamepad();
};

#endif
