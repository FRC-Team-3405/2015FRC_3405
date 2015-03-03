#ifndef ROBOTMAP_H
#define ROBOTMAP_H

#include "WPILib.h"
#include "XboxMap.h"

/**
 * The RobotMap is a mapping from the ports sensors and actuators are wired into
 * to a variable name. This provides flexibility changing wiring, makes checking
 * the wiring easier and significantly reduces the number of magic numbers
 * floating around.
 */
const float PI = 3.14f;
// For example to map the left and right motors, you could define the
// following variables to use with your drivetrain subsystem.
//const int LEFTMOTOR = 1;
//const int RIGHTMOTOR = 2;

// PWM Channels for the Talon motor controllers for chassis
const int TALON_FRONTRIGHT = 0;
const int TALON_FRONTLEFT = 1;
const int TALON_BACKRIGHT = 2;
const int TALON_BACKLEFT = 3;

// PWM channels for elevator talon controllers
const int TALON_ELEVATOR_LEFT = 4;
const int TALON_ELEVATOR_RIGHT = 5;
// PWM channel for wormgear
const int TALON_WORMGEAR = 6;


// Digital IO channels for elevator quadrature encoders
const int ELEVATOR_ENC_1_A = 0;
const int ELEVATOR_ENC_1_B = 1;
const int ELEVATOR_ENC_2_A = 2;
const int ELEVATOR_ENC_2_B = 3;

// Digital IO channels for elevator limit switches
const int ELEVATOR_BOTTOM_SWITCH = 4;
const int ELEVATOR_TOP_SWITCH = 5;

// PWM Channels for the Camera's Servos
const int CAMERA_SERVO_TILT = 6;
const int CAMERA_SERVO_ROTATE = 7;

const float JOYSTICK_THRESHOLD = .20f;
const float TRIGGER_THRESHOLD = .001f;

const float DRIVE_POWER = .5f;

// Encoder values for elevator levels
// Bottom level is LEVELS[0], Sixth level is LEVELS[5]
const int LEVELS[] = {0, 300, 600, 900, 1200, 1500};
const int LEVEL_DEADZONE = 25;

// Speed values for talons (-1 to 1) for elevator
const float ELEVATOR_UPWARD_SPEED = 0.6;
const float ELEVATOR_DOWNWARD_SPEED = 0;
// Speed values for talons (-1 to 1) for wormgear
const float WORMGEAR_UP_SPEED = 1;
const float WORMGEAR_DOWN_SPEED = .25;

// If you are using multiple modules, make sure to define both the port
// number and the module. For example you with a rangefinder:
//const int RANGE_FINDER_PORT = 1;
//const int RANGE_FINDER_MODULE = 1;

#endif
