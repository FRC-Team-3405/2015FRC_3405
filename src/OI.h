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
public:
	OI();
	Joystick* GetJoystick();
};

#endif
