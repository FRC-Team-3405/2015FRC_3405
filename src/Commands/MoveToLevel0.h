#ifndef MOVE_TO_LEVEL_0_H
#define MOVE_TO_LEVEL_0_H

#include "../CommandBase.h"
#include "WPILib.h"
#include "Robot.h"

class MoveToLevel0: public Command
{
private:
	int level;
	bool levelReached;
public:
	MoveToLevel0();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
