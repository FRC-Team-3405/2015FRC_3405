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
	SetDefaultCommand(new DriveCommand());
}

void Chassis::DriveWithJoystick(Joystick* stick)
{
	float x = stick->GetX();
	float y = stick->GetY();
	std::cout << "X: " << x << " Y: " << y << "\n";
	drive->MecanumDrive_Polar(.5f,0.0f,1.0f);
}
// Put methods for controlling this subsystem
// here. Call these from Commands.

