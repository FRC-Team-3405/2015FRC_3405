#include "AnalogElevatorMove.h"
#include "../RobotMap.h"

AnalogElevatorMove::AnalogElevatorMove()
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
	Requires(Robot::elevator);
}

// Called just before this Command runs the first time
void AnalogElevatorMove::Initialize()
{

}

// Called repeatedly when this Command is scheduled to run
void AnalogElevatorMove::Execute()
{
	SmartDashboard::PutNumber("Encoder 1",Robot::elevator->GetEncoder(Elevator::k1));
	SmartDashboard::PutNumber("Encoder 2",Robot::elevator->GetEncoder(Elevator::k2));

	if(Robot::elevator->BottomLimitReached())
		Robot::elevator->ResetEncoders();
	std::cout << "Doing something\n";
	Joystick* flightstick = Robot::oi->GetFlightstick();
	if (flightstick->GetRawButton(1)) {
		float flightstick_Y = flightstick->GetY();
		if(flightstick_Y > .15 && flightstick->GetRawButton(1) && !Robot::elevator->TopLimitReached())
			Robot::elevator->MoveUpWithSpeed(flightstick_Y);
		else if(flightstick_Y < -.15 && flightstick->GetRawButton(1) && !Robot::elevator->BottomLimitReached())
			Robot::elevator->MoveDownWithSpeed(-flightstick_Y);
		else
			Robot::elevator->Hold();
	} else {
		Robot::elevator->Hold();
	}
}

// Make this return true when this Command no longer needs to run execute()
bool AnalogElevatorMove::IsFinished()
{
	return false;
}

// Called once after isFinished returns true
void AnalogElevatorMove::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void AnalogElevatorMove::Interrupted()
{

}
