#include "AutonomousDrive.h"

AutonomousDrive::AutonomousDrive()
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
	Requires(Robot::chassis);
}

// Called just before this Command runs the first time
void AutonomousDrive::Initialize()
{

}

// Called repeatedly when this Command is scheduled to run
void AutonomousDrive::Execute()
{
	//Drive forward
	Robot::chassis->DriveDirectional(0,1,0);
	//Drive to the right
}

// Make this return true when this Command no longer needs to run execute()
bool AutonomousDrive::IsFinished()
{
	return false;
}
//
// Called once after isFinished returns true
void AutonomousDrive::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void AutonomousDrive::Interrupted()
{

}
