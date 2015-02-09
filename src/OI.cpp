#include "OI.h"
#include "XboxMap.h"

OI::OI()
{
	// Define Joysticks here
	stick = new Joystick(0);
	// Define Buttons here
	xboxA = new JoystickButton(stick, XBOX_A);
	xboxB = new JoystickButton(stick, XBOX_B);

	// Assign actions here
	xboxA->WhenPressed(new RunCompressor());


}

Joystick* OI::GetJoystick()
{
	return stick;
}
