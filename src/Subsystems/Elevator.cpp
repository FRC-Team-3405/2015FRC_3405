#include <Subsystems/Elevator.h>
#include "../RobotMap.h"



Elevator::Elevator() :
		Subsystem("Elevator")
{
	enc_1 = new Encoder(ELEVATOR_ENC_1_A,ELEVATOR_ENC_1_B);
	enc_2 = new Encoder(ELEVATOR_ENC_2_A,ELEVATOR_ENC_2_B);

	bottomLimitSwitch = new DigitalInput(ELEVATOR_BOTTOM_SWITCH);
	topLimitSwitch = new DigitalInput(ELEVATOR_TOP_SWITCH);

	leftTalon = new Talon(TALON_ELEVATOR_LEFT);
	rightTalon = new Talon(TALON_ELEVATOR_RIGHT);
	wormgear = new Victor(VICTOR_WORMGEAR);
}

void Elevator::InitDefaultCommand()
{
	// Set the default command for a subsystem here.
	//SetDefaultCommand(new MySpecialCommand());
	//SetDefaultCommand(new HoldElevator());
	SetDefaultCommand(new AnalogElevatorMove());
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

bool Elevator::BottomLimitReached()
{
	// Switch reads at 0 when it is pressed so reverse the bool returned
	return !bottomLimitSwitch->Get();
}

bool Elevator::TopLimitReached()
{
	// Switch reads 0 when it is pressed, so reverse the bool returned
	return !topLimitSwitch->Get();
}

bool Elevator::GoToLevel(int _level = 0)
{
	int encoderCurrent = enc_1->Get();
	int encoderGoal = LEVELS[_level];

	if(encoderCurrent < encoderGoal && abs(encoderCurrent - encoderGoal) > LEVEL_DEADZONE)
	{
		SmartDashboard::PutString("Level", "less than");
		if (abs(encoderCurrent - encoderGoal) < LEVEL_SLOWZONE) {
			MoveUpWithSpeed(ELEVATOR_UPWARD_SPEED*0.3);
		} else {
			MoveUpWithSpeed(ELEVATOR_UPWARD_SPEED);
		}
		return false;
	}
	else if (encoderCurrent > encoderGoal && abs(encoderCurrent - encoderGoal) > LEVEL_DEADZONE)
	{
		SmartDashboard::PutString("Level", "greater than");
		if (abs(encoderCurrent - encoderGoal) < LEVEL_SLOWZONE) {
			MoveDownWithSpeed(ELEVATOR_DOWNWARD_SPEED*0.3);
		} else {
			MoveDownWithSpeed(ELEVATOR_DOWNWARD_SPEED);
		}
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
	if (!TopLimitReached()) {
		leftTalon->Set(ELEVATOR_UPWARD_SPEED);
		rightTalon->Set(-ELEVATOR_UPWARD_SPEED);
		wormgear->Set(-WORMGEAR_UP_SPEED);
	}
}

void Elevator::MoveDown() {
	if (!BottomLimitReached()) {
		leftTalon->Set(-ELEVATOR_DOWNWARD_SPEED);
		rightTalon->Set(ELEVATOR_DOWNWARD_SPEED);
		wormgear->Set(WORMGEAR_DOWN_SPEED);
	}
}

void Elevator::MoveUpWithSpeed(float _speed)
{
	if (!TopLimitReached()) {
		leftTalon->Set(_speed);
		rightTalon->Set(-_speed);
		wormgear->Set(-WORMGEAR_UP_SPEED);
	}
}

void Elevator::MoveDownWithSpeed(float _speed)
{
	if (!BottomLimitReached()) {
		leftTalon->Set(-_speed);
		rightTalon->Set(_speed);
		wormgear->Set(_speed);
	}
}

void Elevator::Hold()
{
	leftTalon->Set(0);
	rightTalon->Set(0);
	wormgear->Set(0);
}
