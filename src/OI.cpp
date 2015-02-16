#include "OI.h"
#include "XboxMap.h"

OI::OI()
{
	// Define Joysticks here
	xbox = new Joystick(0);
	gamepad = new Joystick(1);

	// Define Xbox Buttons here
	xboxA = new JoystickButton(xbox, XBOX_A);
	xboxB = new JoystickButton(xbox, XBOX_B);
	xboxX = new JoystickButton(xbox, XBOX_X);
	xboxY = new JoystickButton(xbox, XBOX_Y);
	xboxBumperLeft = new JoystickButton(xbox, XBOX_BUMPER_LEFT);
	xboxBumperRight = new JoystickButton(xbox, XBOX_BUMPER_RIGHT);
	xboxBack = new JoystickButton(xbox,XBOX_BACK);
	xboxStart = new JoystickButton(xbox, XBOX_START);

	// Assign xbox actions here
	xboxA->WhenPressed(new ClampArm());
	xboxB->WhenPressed(new OpenArm());

	xboxStart->WhenPressed(new RunCompressor());

	//Define gamepad buttons here
	gamepad1 = new JoystickButton(gamepad, 1);

	//Assign gamepad actions here
	gamepad1->WhenPressed(new CameraHomeCommand());

}

Joystick* OI::GetJoystick()
{
	return xbox;
}

Joystick* OI::GetGamepad()
{
	return gamepad;
}
