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

	Talon *leftTalon;
	Talon *rightTalon;
public:
	typedef enum
	{
		k1, k2
	}EncoderIndex;

	Elevator();
	void InitDefaultCommand();
	int GetEncoder(EncoderIndex);
	void MoveUp();
	void MoveDown();
};

#endif
