#ifndef OI_H
#define OI_H

#include "WPILib.h"

#include "Commands/RunCompressor.h"
#include "Commands/ClampArm.h"
#include "Commands/OpenArm.h"

class OI
{
private:
	Joystick* stick;

	JoystickButton* xboxA;
	JoystickButton* xboxB;
	JoystickButton* xboxX;
	JoystickButton* xboxY;
	JoystickButton* xboxBumperLeft;
	JoystickButton* xboxBumperRight;
	JoystickButton* xboxBack;
	JoystickButton* xboxStart;

public:
	OI();
	Joystick* GetJoystick();
};

#endif
