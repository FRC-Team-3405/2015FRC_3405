#include "MoveToLevel.h"
#include "../RobotMap.h"

MoveToLevel::MoveToLevel(int _level)
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
	Requires(Robot::elevator);
	level = _level;
	levelReached = false;
}

MoveToLevel::MoveToLevel()
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
	Requires(Robot::elevator);
	level = 1;
	levelReached = false;
}


// Called just before this Command runs the first time
void MoveToLevel::Initialize()
{
	levelReached = false;
}

// Called repeatedly when this Command is scheduled to run
void MoveToLevel::Execute()
{
	SmartDashboard::PutNumber("Encoder 1",Robot::elevator->GetEncoder(Elevator::k1));
	SmartDashboard::PutNumber("Encoder 2",Robot::elevator->GetEncoder(Elevator::k2));

	if(Robot::elevator->BottomLimitReached())
		Robot::elevator->ResetEncoders();

	levelReached = Robot::elevator->GoToLevel(level);

	if (levelReached) {
		Robot::oi->GetGamepad()->SetOutput(GREEN_LED,true);
		Robot::oi->GetGamepad()->SetOutput(RED_LED,false);
	}
	else {
		Robot::oi->GetGamepad()->SetOutput(GREEN_LED,false);
		Robot::oi->GetGamepad()->SetOutput(RED_LED,true);
	}
}

// Make this return true when this Command no longer needs to run execute()
bool MoveToLevel::IsFinished()
{
	return levelReached;
}

// Called once after isFinished returns true
void MoveToLevel::End()
{
	Robot::elevator->Hold();
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void MoveToLevel::Interrupted()
{
	Robot::elevator->Hold();
}
