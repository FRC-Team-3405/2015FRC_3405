#ifndef MOVE_TO_LEVEL_4_H
#define MOVE_TO_LEVEL_4_H

#include "../CommandBase.h"
#include "WPILib.h"
#include "Robot.h"

class MoveToLevel4: public Command
{
private:
	int level;
	bool levelReached;
public:
	MoveToLevel4();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
