#ifndef ARMS_H
#define ARMS_H

#include "Commands/Subsystem.h"
#include "WPILib.h"

class Arms: public Subsystem
{
private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities
public:
	Arms();
	void InitDefaultCommand();
};

#endif
