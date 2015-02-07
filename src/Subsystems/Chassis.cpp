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
	float y = stick->GetX(GenericHID::kLeftHand);
//	if(abs(x) < JOYSTICK_DEADZONE)
//		x = 0;
//	if(abs(y) < JOYSTICK_DEADZONE)
//		y = 0;



	float r = sqrt((x*x) + (y*y));
	// Scale down the magnitude
	r *= DRIVE_SCALE;

	float direction;
	if(abs(x) < .0001)
	{
		if(y < 0)
			direction = -90.0f;
		else
			direction = 90.0f;
	}
	else
		direction = atan(y / x);

	std::cout << "X: " << x << " Y: " << y << "\n";
	drive->MecanumDrive_Polar(r,direction, 0.0f);
}
// Put methods for controlling this subsystem
// here. Call these from Commands.

