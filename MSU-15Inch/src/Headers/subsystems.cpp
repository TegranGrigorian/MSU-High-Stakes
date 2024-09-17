#include "main.h"
#include "pros/adi.hpp"
#include "pros/adi.h"
#include "pros/misc.h"
// #include "automatedDetection.hpp" //import the autonomous detectiion so we can use determines
/*
*Welcome to Subsytems.cpp!
*This file will contain all the movment instructions for the robot, they are all seperated into classes to make it neat, clean and user friendly. Eventualy this code will go public so this should help begineers to understand what all of this means
*but anything that moves and has backend logic like detecting a ring or controller inputs will most have a connection to this file. This means simple move comands like intake spin to 600 rpm will not be in this file or in the class system
*which means you will need to just call the intake how you normally do it like intake.move_velocity(600);
 */

//wow seting everything to class so luke cant mess this up

//setup class defintions in the subsystems.cpp file in order to include subsytems.hpp to the main so it can be accsesed any where
intakeClass Intake;
backPackClass BackPack;
pneumaticsClass Pnu;
hookClass Hooks;

void intakeClass::driveIntakes() { 
    if(controller.get_digital(pros::E_CONTROLLER_DIGITAL_L1)){
        intake.move_velocity(-200);
        hooks.move_velocity(-200);
    } else if(controller.get_digital(pros::E_CONTROLLER_DIGITAL_L2)){
        intake.move_velocity(200);
        hooks.move_velocity(200);
    } else {
        intake.move_velocity(0);
        hooks.move_velocity(0);
    }
}

// Implement hookClass methods
void hookClass::driveHooks() { 
    if (controller.get_digital(pros::E_CONTROLLER_DIGITAL_UP)) {
        hooks.move_velocity(600);
    } else if (controller.get_digital(pros::E_CONTROLLER_DIGITAL_DOWN)) {
        hooks.move_velocity(-600);
    } else {
        hooks.move_velocity(0);
    }
}

void hookClass::teamScoring() {
    hooks.move_velocity(600);
    while (color.get_proximity() < 100) {
        // if ((char)autoDetection.detectRingColor != autoDetection.teamColor[1]) {
        //     hooks.brake();
        //     hooks.move_relative(200, 600);
        //     hooks.move(600);
        // } else {
        //     hooks.move_velocity(600);
        // }
    }
}

// Implement pneumaticsClass methods
bool pneumaticsClass::toggleLift;
void pneumaticsClass::driveLift() {
    leftLift.set_value(toggleLift);
    rightLift.set_value(toggleLift);
    if (controller.get_digital_new_press(DIGITAL_R1)) {
        toggleLift = !toggleLift;
    }
}
bool pneumaticsClass::toggleClamp;
void pneumaticsClass::driveClamp() {
	Clamp.set_value(toggleClamp);
    if (controller.get_digital_new_press(DIGITAL_R2)) {
        toggleClamp = !toggleClamp;
    }
}

void pneumaticsClass::setLift(bool setLift) {
    leftLift.set_value(setLift);
    rightLift.set_value(setLift);
}

void pneumaticsClass::autonLift() {
    // Autonomous lift logic here
}

// Implement backPackClass methods
void backPackClass::driveBackPack() {
    if (controller.get_digital(pros::E_CONTROLLER_DIGITAL_A)) {
        backPack.move_velocity(600);
    } else if (controller.get_digital(pros::E_CONTROLLER_DIGITAL_B)) {
        backPack.move_velocity(-600);
    } else {
        backPack.move_velocity(0);
    }
}
