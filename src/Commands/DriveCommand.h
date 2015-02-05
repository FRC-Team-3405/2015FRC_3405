#ifndef DRIVE_COMMAND_H
#define DRIVE_COMMAND_H

#include "../CommandBase.h"
#include "../OI.h"
#include "WPILib.h"

class DriveCommand : public Command
{
public:
	DriveCommand();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif

