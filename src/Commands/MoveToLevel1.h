#ifndef MOVE_TO_LEVEL_1_H
#define MOVE_TO_LEVEL_1_H

#include "../CommandBase.h"
#include "WPILib.h"
#include "Robot.h"

class MoveToLevel1: public Command
{
private:
	int level;
	bool levelReached;
public:
	MoveToLevel1();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
