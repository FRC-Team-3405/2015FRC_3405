#include <Subsystems/Elevator.h>
#include "../RobotMap.h"



Elevator::Elevator() :
		Subsystem("Elevator")
{
	enc_1 = new Encoder(ELEVATOR_ENC_1_A,ELEVATOR_ENC_1_B);
	enc_2 = new Encoder(ELEVATOR_ENC_2_A,ELEVATOR_ENC_2_B);

	leftTalon = new Talon(TALON_ELEVATOR_LEFT);
	rightTalon = new Talon(TALON_ELEVATOR_RIGHT);
	wormgear = new Talon(TALON_WORMGEAR);
}

void Elevator::InitDefaultCommand()
{
	// Set the default command for a subsystem here.
	//SetDefaultCommand(new MySpecialCommand());
	//SetDefaultCommand(new HoldElevator());
	SetDefaultCommand(new MoveToLevel());
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

void Elevator::ResetEncoders()
{
	enc_1->Reset();
	enc_2->Reset();
}

bool Elevator::GoToLevel(int _level = 0)
{
	int encoderCurrent = enc_1->Get();
	int encoderGoal = LEVELS[_level];

	if(encoderCurrent < encoderGoal && abs(encoderCurrent - encoderGoal) > LEVEL_DEADZONE)
	{
		SmartDashboard::PutString("Level", "less than");
		MoveUp();
		return false;
	}
	else if (encoderCurrent > encoderGoal && abs(encoderCurrent - encoderGoal) > LEVEL_DEADZONE)
	{
		SmartDashboard::PutString("Level", "greater than");
		MoveDown();
		return false;
	}
	else if(abs(encoderCurrent - encoderGoal) < LEVEL_DEADZONE)
	{
		SmartDashboard::PutString("Level", "reached");
		Hold();
		return true;
	}
	else
	{
		SmartDashboard::PutString("Level", "error");
		return true;
	}
}

void Elevator::MoveUp() {
	leftTalon->Set(ELEVATOR_UPWARD_SPEED);
	rightTalon->Set(-ELEVATOR_UPWARD_SPEED);
	wormgear->Set(-WORMGEAR_UP_SPEED);
}

void Elevator::MoveDown() {
	leftTalon->Set(-ELEVATOR_DOWNWARD_SPEED);
	rightTalon->Set(ELEVATOR_DOWNWARD_SPEED);
	wormgear->Set(WORMGEAR_DOWN_SPEED);
}

void Elevator::Hold()
{
	leftTalon->Set(0);
	rightTalon->Set(0);
	wormgear->Set(0);
}
