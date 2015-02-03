#include <Subsystems/Pneumatics.h>
#include "../RobotMap.h"

Pneumatics::Pneumatics() :
		Subsystem("Pneumatics")
{
	compressor = new Compressor(0);
	compressor->SetClosedLoopControl(true);
}

void Pneumatics::InitDefaultCommand()
{
	// Set the default command for a subsystem here.
	//SetDefaultCommand(new MySpecialCommand());
}

// Put methods for controlling this subsystem
// here. Call these from Commands.

void Pneumatics::StartCompressor()
{
	compressor->Start();
}

void Pneumatics::StopCompressor()
{
	compressor->Stop();
}

void Pneumatics::SetCompressorClosedLoopControl(bool on)
{
	compressor->SetClosedLoopControl(on);
}
