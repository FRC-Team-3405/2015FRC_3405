#ifndef PNEUMATICS_H
#define PNEUMATICS_H

#include "Commands/Subsystem.h"
#include "WPILib.h"

class Pneumatics: public Subsystem
{
private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities
	Compressor* compressor;
public:
	Pneumatics();
	void InitDefaultCommand();
};

#endif
