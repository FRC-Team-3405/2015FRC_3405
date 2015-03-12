#ifndef MOVE_TO_LEVEL_3_H
#define MOVE_TO_LEVEL_3_H

#include "../CommandBase.h"
#include "WPILib.h"
#include "Robot.h"

class MoveToLevel3: public Command
{
private:
	int level;
	bool levelReached;
public:
	MoveToLevel3();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
