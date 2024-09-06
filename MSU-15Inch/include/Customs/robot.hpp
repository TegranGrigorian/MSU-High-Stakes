#include "pros/adi.hpp"
#include "pros/imu.hpp"
#include "pros/motor_group.hpp"
#include "pros/rotation.hpp"
#include "lemlib/chassis/chassis.hpp"
#include "lemlib/chassis/trackingWheel.hpp"
#include "pros/distance.hpp"
#include "pros/optical.hpp"

using namespace pros;
using namespace lemlib;

extern Controller controller;

extern MotorGroup driveLeft;
extern MotorGroup driveRight;

extern Motor intake;
extern MotorGroup backPack;
extern MotorGroup hooks;

extern Imu imu;
extern Distance distance;
extern Optical color;

//booleans assoicated with the pneumatics
extern bool toggleClamp = false;
extern bool toggleLift = false;

//pneumatics externed
extern adi::DigitalOut Clamp;
extern adi::DigitalOut leftLift;
extern adi::DigitalOut rightLift;

extern Rotation latRot;
extern Rotation angRot;

extern Drivetrain drivetrain;

extern TrackingWheel horizontal_tracking_wheel;
extern TrackingWheel vertical_tracking_wheel;

extern Chassis chassis;