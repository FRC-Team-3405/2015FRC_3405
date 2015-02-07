#include <Subsystems/Chassis.h>
#include "../RobotMap.h"

Chassis::Chassis() :
		Subsystem("Chassis")
{
	frontLeft = new Talon(TALON_FRONTLEFT);
	backLeft = new Talon(TALON_BACKLEFT);
	frontRight = new Talon(TALON_FRONTRIGHT);
	backRight = new Talon(TALON_BACKRIGHT);


	drive = new RobotDrive(frontLeft, backLeft, frontRight, backRight);
}

void Chassis::InitDefaultCommand()
{
	// Set the default command for a subsystem here.
	//SetDefaultCommand(new MySpecialCommand());
	std::cout << "Setting default command";
	SetDefaultCommand(new DriveCommand());
}

void Chassis::DriveWithJoystick(Joystick* stick)
{

	float x = stick->GetX(GenericHID::kLeftHand);
	float y = stick->GetY(GenericHID::kLeftHand);

	std::cout << "X: " << x << " Y: " << y << "\n";
	float rotation = stick->GetX(GenericHID::kRightHand);

	if(fabs(x) < JOYSTICK_THRESHOLD)
		x = 0.0;
	if(fabs(y) < JOYSTICK_THRESHOLD)
		y = 0.0;
	if(rotation < JOYSTICK_THRESHOLD)
		rotation = 0.0;

	float FR = y + rotation + x;
	float BR = y + rotation - x;
	float FL = -1.0 * (y - rotation - x);
	float BL = -1.0 * (y - rotation + x);

	Robot::chassis->frontRight->Set(FR);
	Robot::chassis->frontLeft->Set(FL);
	Robot::chassis->backRight->Set(BR);
	Robot::chassis->backLeft->Set(BL);
//	if(abs(x) < JOYSTICK_DEADZONE)
//		x = 0;
//	if(abs(y) < JOYSTICK_DEADZONE)
//		y = 0;

//	float r = sqrt((x*x) + (y*y));
//	// Scale down the magnitude
//	r *= DRIVE_SCALE;
//
//	float direction;
//	if(abs(x) < .0001)
//	{
//		if(y < 0)
//			direction = -90.0f;
//		else
//			direction = 90.0f;
//	}
//	else
//		direction = atan(y / x);
//
std::cout << "X0: " << x << " Y0: " << y << "\n";
//	drive->MecanumDrive_Polar(r,direction, 0.0f);
}
// Put methods for controlling this subsystem
// here. Call these from Commands.

