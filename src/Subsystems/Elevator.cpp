#include <Subsystems/Elevator.h>
#include "../RobotMap.h"



Elevator::Elevator() :
		Subsystem("Elevator")
{
	enc_1 = new Encoder(ELEVATOR_ENC_1_A,ELEVATOR_ENC_1_B);
	enc_2 = new Encoder(ELEVATOR_ENC_2_A,ELEVATOR_ENC_2_B);

	leftTalon = new Talon(TALON_ELEVATOR_LEFT);
	rightTalon = new Talon(TALON_ELEVATOR_RIGHT);
}

void Elevator::InitDefaultCommand()
{
	// Set the default command for a subsystem here.
	//SetDefaultCommand(new MySpecialCommand());
	SetDefaultCommand(new LogEncoders());
}

// Put methods for controlling this subsystem
// here. Call these from Commands.
int Elevator::GetEncoder(EncoderIndex e = k1)
{
	if(e == k1)
		return enc_1->Get();
	else if(e == k2)
		return enc_2->Get();
	else
		throw 0;
}

void Elevator::MoveUp() {
	leftTalon->Set(ELEVATOR_UPWARD_SPEED);
	rightTalon->Set(-ELEVATOR_UPWARD_SPEED);
}

void Elevator::MoveDown() {
	leftTalon->Set(-ELEVATOR_DOWNWARD_SPEED);
	rightTalon->Set(ELEVATOR_DOWNWARD_SPEED);
}
