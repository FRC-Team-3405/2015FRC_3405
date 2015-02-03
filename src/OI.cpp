#include "OI.h"

const int XBOX_A = 1;
const int XBOX_B = 2;

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
