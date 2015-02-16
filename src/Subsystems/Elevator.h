#ifndef ELEVATOR_H
#define ELEVATOR_H

#include "Commands/Subsystem.h"
#include "WPILib.h"

#include "../Commands/LogEncoders.h"

class Elevator: public Subsystem
{
private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities
	Encoder* enc_1;
	Encoder* enc_2;
public:
	Elevator();
	void InitDefaultCommand();
	int GetEncoder(int);
};

#endif
