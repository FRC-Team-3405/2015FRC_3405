#include <Subsystems/Camera.h>
#include "../RobotMap.h"

Camera::Camera() :
		Subsystem("Camera")
{
	tilt = new Servo(CAMERA_SERVO_TILT);
	rotate = new Servo(CAMERA_SERVO_ROTATE);
}

void Camera::InitDefaultCommand()
{
	// Set the default command for a subsystem here.
	//SetDefaultCommand(new MySpecialCommand());
	SetDefaultCommand(new CameraMoveCommand());
}

// Put methods for controlling this subsystem
// here. Call these from Commands.
void Camera::MoveWithPOV(Joystick* stick)
{
	SmartDashboard::PutNumber("POV Angle:", stick->GetPOV());
}
