#ifndef OI_H
#define OI_H

#include "WPILib.h"

#include "CommandList.h"

class OI
{
private:
	Joystick* xbox;
	Joystick* gamepad;
	Joystick* flightstick;

	JoystickButton* xboxA;
	JoystickButton* xboxB;
	JoystickButton* xboxX;
	JoystickButton* xboxY;
	JoystickButton* xboxBumperLeft;
	JoystickButton* xboxBumperRight;
	JoystickButton* xboxBack;
	JoystickButton* xboxStart;

	JoystickButton *gamepad1;
	JoystickButton *gamepad2;
	JoystickButton *gamepad3;
	JoystickButton *gamepad4;
	JoystickButton *gamepad5;
	JoystickButton *gamepad6;
	JoystickButton *gamepad7;
	JoystickButton *gamepad8;
	JoystickButton *gamepad9;
	JoystickButton *gamepad10;
	JoystickButton *gamepad11;
	JoystickButton *gamepad12;

public:
	OI();
	Joystick* GetJoystick();
	Joystick* GetGamepad();
	Joystick* GetFlightstick();
};

#endif
