#ifndef CHASSIS_H
#define CHASSIS_H

#include "Commands/Subsystem.h"
#include "Commands/DriveCommand.h"
#include "WPILib.h"

class Chassis: public Subsystem
{
private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities

public:
	Talon* frontLeft;
	Talon* frontRight;
	Talon* backLeft;
	Talon* backRight;

	RobotDrive* drive;

	Chassis();
	void DriveWithJoystick(Joystick* stick);

	void InitDefaultCommand();
};

#endif
