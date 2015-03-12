#include "AutonomousCommandGroup.h"

const float TIME_TO_BACK = .5;

AutonomousCommandGroup::AutonomousCommandGroup()
{
	//Drive forward for 1 second
	AddSequential(new DriveDirectionalCommand(0, 1, 0), 1);
	//Drive to the right for half a second
	AddSequential(new DriveDirectionalCommand(1, 0, 0), 0.5);

	AddSequential(new OpenArm());
	AddSequential(new DriveDirectionalCommand(0, -1, 0), TIME_TO_BACK);
}
