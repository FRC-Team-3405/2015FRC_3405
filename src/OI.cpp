#include "OI.h"
#include "XboxMap.h"

OI::OI()
{
	// Define Joysticks here
	stick = new Joystick(0);

	// Define Buttons here
	xboxA = new JoystickButton(stick, XBOX_A);
	xboxB = new JoystickButton(stick, XBOX_B);
	xboxX = new JoystickButton(stick, XBOX_X);
	xboxY = new JoystickButton(stick, XBOX_Y);
	xboxBumperLeft = new JoystickButton(stick, XBOX_BUMPER_LEFT);
	xboxBumperRight = new JoystickButton(stick, XBOX_BUMPER_RIGHT);
	xboxBack = new JoystickButton(stick,XBOX_BACK);
	xboxStart = new JoystickButton(stick, XBOX_START);

	// Assign actions here
	xboxA->WhenPressed(new ClampArm());
	xboxB->WhenPressed(new OpenArm());

	xboxStart->WhenPressed(new RunCompressor());


}

Joystick* OI::GetJoystick()
{
	return stick;
}
