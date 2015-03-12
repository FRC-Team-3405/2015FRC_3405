#include "MoveToLevel2.h"
#include "../RobotMap.h"

MoveToLevel2::MoveToLevel2()
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
	//Requires(Robot::elevator);
	level = 2;
	levelReached = false;
}


// Called just before this Command runs the first time
void MoveToLevel2::Initialize()
{
}

// Called repeatedly when this Command is scheduled to run
void MoveToLevel2::Execute()
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
bool MoveToLevel2::IsFinished()
{
	//return levelReached;
	return true;
}

// Called once after isFinished returns true
void MoveToLevel2::End()
{
	//Robot::elevator->Hold();
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void MoveToLevel2::Interrupted()
{
	//Robot::elevator->Hold();
}
