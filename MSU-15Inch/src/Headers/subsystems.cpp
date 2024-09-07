#include "main.h"
#include "pros/adi.hpp"
#include "pros/adi.h"
#include "pros/misc.h"
#include "automatedDetection.hpp" //import the autonomous detectiion so we can use determines
/*
*Welcome to Subsytems.cpp!
*This file will contain all the movment instructions for the robot, they are all seperated into classes to make it neat, clean and user friendly. Eventualy this code will go public so this should help begineers to understand what all of this means
*but anything that moves and has backend logic like detecting a ring or controller inputs will most have a connection to this file. This means simple move comands like intake spin to 600 rpm will not be in this file or in the class system
*which means you will need to just call the intake how you normally do it like intake.move_velocity(600);
 */

//wow seting everything to class so luke cant mess this up
class intakeClass{
	public:
	static void driveIntakes(){ // make a function called setIntakes but have it static so it cant be manipulated
	if(controller.get_digital(pros::E_CONTROLLER_DIGITAL_L1)){
		intake.move_velocity(-200);
		hooks.move_velocity(-200);
	}
	else if(controller.get_digital(pros::E_CONTROLLER_DIGITAL_L2)){
		intake.move_velocity(200);
		hooks.move_velocity(200);
	}
	else {
		intake.move_velocity(0);
		hooks.move_velocity(0);
	}
} 
};

class hookClass{
	public:
	static void driveHooks(){ 
		if (controller.get_digital(pros::E_CONTROLLER_DIGITAL_UP)) {
			hooks.move_velocity(600);
		} else if (controller.get_digital(pros::E_CONTROLLER_DIGITAL_DOWN)) { // i would do !input but I dont know if that works here
			hooks.move_velocity(-600);
		} else{
			hooks.move_velocity(0);
		}	
	}
	static void teamScoring() { //simple hook movement determiner
        hooks.move_velocity(600); //spin the hooks 
        while (color.get_proximity() < 100){ //loop a scan of sensors
            if ((char)autoDetection.detectRingColor != autoDetection.teamColor[1]) { //if we detect a ring color that isnt the same color as our team then we eject it by stoping the hooks at the top of its belt. the [1] checks for the first character in the string
                hooks.brake(); //stop the motor to eject
                hooks.move_relative(200,600); //move the belt so we can get rid of any objet in teh sensors path
                hooks.move(600); //restart the belts forward movement to check for objects
            } else {
                hooks.move_velocity(600); // unless then run this, if the color of the ring is our color
            }
        }
        
    }

};

namespace pros::adi{
class pneumaticsClass{
	public:
    static void driveLift() {
		leftLift.set_value(toggleLift); // we must declare the boolean else where than this function since the function is ran inside of a while loop.
		rightLift.set_value(toggleLift);
        if (controller.get_digital_new_press(DIGITAL_R1)) { //if a new press is detected flip the boolean 
            if (!toggleLift) {
                toggleLift = !toggleLift;
            } else {
                toggleLift = !toggleLift;
            }
        }
    }
	static void driveClamp() {
		Clamp.set_value(toggleClamp);
		if (controller.get_digital_new_press(DIGITAL_R2)) { //if a new press is detected flip the boolean 
            if (!toggleLift) {
                toggleLift = !toggleLift;
            } else {
                toggleLift = !toggleLift;
            }
        }
	}
};
}

class backPackClass{
	public:
	static void driveBackPack() { //we can make this toggle to a certain angle but  for now im gonna just have it be a manual control
		if (controller.get_digital(pros::E_CONTROLLER_DIGITAL_A)) {
			backPack.move_velocity(600);
		} else if (controller.get_digital(pros::E_CONTROLLER_DIGITAL_B)) {
			backPack.move_velocity(-600);
		} else {
			backPack.move_velocity(0);
		}
	}

};

