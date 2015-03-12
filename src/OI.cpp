#include "OI.h"
#include "XboxMap.h"

OI::OI()
{
	// Define Joysticks here
	xbox = new Joystick(0);
	gamepad = new Joystick(1);
	flightstick = new Joystick(2);

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
	xboxX->WhenPressed(new MoveToLevel());
	xboxY->WhenPressed(new MoveToLevel());

	xboxStart->WhenPressed(new RunCompressor());

	//Define gamepad buttons here
	gamepad1 = new JoystickButton(gamepad, 1);
	gamepad2 = new JoystickButton(gamepad, 2);
	gamepad3 = new JoystickButton(gamepad, 3);
	gamepad4 = new JoystickButton(gamepad, 4);
	gamepad5 = new JoystickButton(gamepad, 5);
	gamepad6 = new JoystickButton(gamepad, 6);
	gamepad7 = new JoystickButton(gamepad, 7);
	gamepad8 = new JoystickButton(gamepad, 8);
	gamepad9 = new JoystickButton(gamepad, 9);
	gamepad10 = new JoystickButton(gamepad, 10);
	gamepad11 = new JoystickButton(gamepad, 11);
	gamepad12 = new JoystickButton(gamepad, 12);

	//Assign gamepad actions here
	gamepad1->WhenPressed(new MoveToLevel(0));
	gamepad2->WhenPressed(new MoveToLevel(1));
	gamepad3->WhenPressed(new MoveToLevel(2));
	gamepad4->WhenPressed(new MoveToLevel(3));
	gamepad5->WhenPressed(new MoveToLevel(4));
	gamepad6->WhenPressed(new MoveToLevel(5));
	gamepad7->WhenPressed(new OpenArm());
	gamepad8->WhenPressed(new ClampArm());
	gamepad9->WhenPressed(new ReleaseDriveReverse());
	gamepad10->WhenPressed(new CameraHomeCommand());
	gamepad11->WhenPressed(new CameraHomeCommand());
	gamepad12->WhenPressed(new CameraHomeCommand());


}

Joystick* OI::GetJoystick()
{
	return xbox;
}

Joystick* OI::GetGamepad()
{
	return gamepad;
}

Joystick* OI::GetFlightstick()
{
	return flightstick;
}
