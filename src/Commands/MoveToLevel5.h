#ifndef MOVE_TO_LEVEL_5_H
#define MOVE_TO_LEVEL_5_H

#include "../CommandBase.h"
#include "WPILib.h"
#include "Robot.h"

class MoveToLevel5: public Command
{
private:
	int level;
	bool levelReached;
public:
	MoveToLevel5();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
