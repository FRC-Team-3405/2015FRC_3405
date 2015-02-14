#ifndef ROBOT_H
#define ROBOT_H

#include "WPILib.h"
#include "Commands/Command.h"

#include "CommandBase.h"

#include <iostream>

class Chassis;
class OI;
class Arms;
class Elevator;
class Pneumatics;

class Robot : public IterativeRobot
{
private:
	Command *autonomousCommand;
	LiveWindow *lw;

	void RobotInit();
	void DisabledPeriodic();
	void AutonomousInit();
	void AutonomousPeriodic();
	void TeleopInit();
	void TeleopPeriodic();
	void TestPeriodic();

public:
	// Define static subsystems
	static Pneumatics* pneumatics;
	static Chassis* chassis;
	static Arms* arms;
	static Elevator* elevator;

	static OI* oi;
};

#endif
