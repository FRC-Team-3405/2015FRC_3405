#include "Robot.h"

Pneumatics* Robot::pneumatics = NULL;
Chassis* Robot::chassis = NULL;
Arms* Robot::arms = NULL;
Elevator* Robot::elevator = NULL;

OI* Robot::oi = NULL;

void Robot::RobotInit()
{
	CommandBase::init();

	chassis = new Chassis();
	arms = new Arms();
	elevator = new Elevator();
	pneumatics = new Pneumatics();

	oi = new OI();
	//autonomousCommand = new ExampleCommand();
	lw = LiveWindow::GetInstance();
	//Display currently running commands on the dashboard
	SmartDashboard::PutData(Scheduler::GetInstance());
	//Adds buttons to the dashboard to run particular commands
	SmartDashboard::PutData("Clamp Arms", new ClampArm());
	SmartDashboard::PutData("Open Arms", new OpenArm());
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

