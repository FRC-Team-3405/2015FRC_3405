#include "MoveToLevel0.h"
#include "../RobotMap.h"

MoveToLevel0::MoveToLevel0()
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
	Requires(Robot::elevator);
	level = 0;
	levelReached = false;
}


// Called just before this Command runs the first time
void MoveToLevel0::Initialize()
{
}

// Called repeatedly when this Command is scheduled to run
void MoveToLevel0::Execute()
{
//	SmartDashboard::PutNumber("Encoder 1",Robot::elevator->GetEncoder(Elevator::k1));
//	SmartDashboard::PutNumber("Encoder 2",Robot::elevator->GetEncoder(Elevator::k2));
//
//	if(Robot::elevator->BottomLimitReached())
//		Robot::elevator->ResetEncoders();
//
//	levelReached = Robot::elevator->GoToLevel(level);
//
//	std::cout << "Attempting to reach level " << level << "\n";
//
//	if (levelReached) {
//		Robot::oi->GetGamepad()->SetOutput(GREEN_LED,true);
//		Robot::oi->GetGamepad()->SetOutput(RED_LED,false);
//	}
//	else {
//		Robot::oi->GetGamepad()->SetOutput(GREEN_LED,false);
//		Robot::oi->GetGamepad()->SetOutput(RED_LED,true);
//	}
	Robot::elevator->DESTINATION_LEVEL = level;
	Robot::elevator->DESTINATION_REACHED = false;

}

// Make this return true when this Command no longer needs to run execute()
bool MoveToLevel0::IsFinished()
{
	//return levelReached;
	return true;
}

// Called once after isFinished returns true
void MoveToLevel0::End()
{
	//Robot::elevator->Hold();
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void MoveToLevel0::Interrupted()
{
	//Robot::elevator->Hold();
}
