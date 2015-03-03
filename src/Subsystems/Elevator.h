#ifndef ELEVATOR_H
#define ELEVATOR_H

#include "Commands/Subsystem.h"
#include "WPILib.h"
#include <iostream>

#include "../Commands/LogEncoders.h"

class Elevator: public Subsystem
{
private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities
	Encoder* enc_1;
	Encoder* enc_2;

	DigitalInput* bottomLimitSwitch;
	DigitalInput* topLimitSwitch;

	Talon* leftTalon;
	Talon* rightTalon;
	Talon* wormgear;
public:
	typedef enum
	{
		k1, k2
	}EncoderIndex;

	Elevator();
	void InitDefaultCommand();
	int GetEncoder(EncoderIndex);
	void ResetEncoders();

	bool BottomLimitReached();
	bool TopLimitReached();

	bool GoToLevel(int);
	void MoveUp();
	void MoveDown();

	void MoveUpWithSpeed(float);
	void MoveDownWithSpeed(float);

	void Hold();
};

#endif
