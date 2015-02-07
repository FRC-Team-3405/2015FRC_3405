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
	float power = DRIVE_POWER;
	float trigger = stick->GetRawAxis(UINT32_C(3));

	float x = -1 * stick->GetX(GenericHID::kLeftHand);
	float y = stick->GetY(GenericHID::kLeftHand);
	float rotation = stick->GetRawAxis(UINT32_C(4));

	//std::cout << "X: " << x << " Y: " << y << " R: " << rotation << "\n";

	if(fabs(x) < JOYSTICK_THRESHOLD)
		x = 0.0;
	if(fabs(y) < JOYSTICK_THRESHOLD)
		y = 0.0;
	if(fabs(rotation) < JOYSTICK_THRESHOLD)
		rotation = 0.0;

	if(trigger < -.001)
		power *= (1 + (trigger * -1));

	float FR = (y + rotation + x) * power;
	float BR = (y + rotation - x) * power;
	float FL = (-1.0 * (y - rotation - x)) * power;
	float BL = (-1.0 * (y - rotation + x)) * power;

	Robot::chassis->frontRight->Set(FR);
	Robot::chassis->frontLeft->Set(FL);
	Robot::chassis->backRight->Set(BR);
	Robot::chassis->backLeft->Set(BL);

	//std::cout << "X0: " << x << " Y0: " << y << " R0: " << rotation << "\n";

}
// Put methods for controlling this subsystem
// here. Call these from Commands.

