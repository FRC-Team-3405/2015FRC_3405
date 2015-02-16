#include <Subsystems/Elevator.h>
#include "../RobotMap.h"

Elevator::Elevator() :
		Subsystem("Elevator")
{
	enc_1 = new Encoder(0,1);
	enc_2 = new Encoder(2,3);
}

void Elevator::InitDefaultCommand()
{
	// Set the default command for a subsystem here.
	//SetDefaultCommand(new MySpecialCommand());
	SetDefaultCommand(new LogEncoders());
}

// Put methods for controlling this subsystem
// here. Call these from Commands.
int Elevator::GetEncoder(int e = 1)
{
	if(e == 1)
		return enc_1->Get();
	else if(e == 2)
		return enc_2->Get();
	else
		return -1;
}
