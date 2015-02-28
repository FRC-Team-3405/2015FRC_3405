#include "MoveToLevel.h"
#include "../RobotMap.h"

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
//	//Get current encoder value
//	int encoderCurrent = Robot::elevator->GetEncoder(Elevator::k1);
//	int encoderGoal = LEVELS[level];
//	//Move elevator up or down to reach the desired level
//	if ((encoderCurrent < encoderGoal) && (abs(encoderCurrent - encoderGoal) < LEVEL_DEADZONE) && !levelReached)//if ((encoderCurrent < encoderGoal) && !levelReached)
//	{
//		Robot::elevator->MoveUp();
//	}
//	else if ((encoderCurrent > encoderGoal) && (abs(encoderCurrent - encoderGoal) > LEVEL_DEADZONE))
//	{
//		Robot::elevator->MoveDown();
//	}
//	else {
//		levelReached = true;
//	}
	if(Robot::oi->GetFlightstick()->GetY() > .15)
		Robot::elevator->MoveUp();
	else if(Robot::oi->GetFlightstick()->GetY() < -.15)
		Robot::elevator->MoveDown();
	else
		Robot::elevator->Hold();

	//levelReached = Robot::elevator->GoToLevel(1);
}

// Make this return true when this Command no longer needs to run execute()
bool MoveToLevel::IsFinished()
{
	return levelReached;
}

// Called once after isFinished returns true
void MoveToLevel::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void MoveToLevel::Interrupted()
{

}
