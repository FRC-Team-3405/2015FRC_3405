#ifndef MOVE_TO_LEVEL_2_H
#define MOVE_TO_LEVEL_2_H

#include "../CommandBase.h"
#include "WPILib.h"
#include "Robot.h"

class MoveToLevel2: public Command
{
private:
	int level;
	bool levelReached;
public:
	MoveToLevel2();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
