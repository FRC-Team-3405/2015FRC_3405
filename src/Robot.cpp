#include "Robot.h"

Pneumatics* Robot::pneumatics = NULL;
Chassis* Robot::chassis = NULL;
Arms* Robot::arms = NULL;
Elevator* Robot::elevator = NULL;

void Robot::RobotInit()
{
	CommandBase::init();

	chassis = new Chassis();
	arms = new Arms();
	elevator = new Elevator();
	pneumatics = new Pneumatics();

	//autonomousCommand = new ExampleCommand();
	lw = LiveWindow::GetInstance();
}

void Robot::DisabledPeriodic()
{
	Scheduler::GetInstance()->Run();
}

void Robot::AutonomousInit()
{
	if (autonomousCommand != NULL)
		autonomousCommand->Start();
}

void Robot::AutonomousPeriodic()
{
	Scheduler::GetInstance()->Run();
}

void Robot::TeleopInit()
{
	// This makes sure that the autonomous stops running when
	// teleop starts running. If you want the autonomous to
	// continue until interrupted by another command, remove
	// this line or comment it out.
	if (autonomousCommand != NULL)
		autonomousCommand->Cancel();

}

void Robot::TeleopPeriodic()
{
	Scheduler::GetInstance()->Run();
}

void Robot::TestPeriodic()
{
	lw->Run();
}

START_ROBOT_CLASS(Robot);

