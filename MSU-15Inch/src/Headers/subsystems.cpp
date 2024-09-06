#include "main.h"
#include "pros/adi.hpp"
#include "pros/adi.h"
#include "pros/misc.h"

//wow seting everything to class so luke cant mess this up
class intakeClass{
	public:
	static void setIntakes(){ // make a function called setIntakes but have it static so it cant be manipulated
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
	static void setHooks(){ 
	if (controller.get_digital(pros::E_CONTROLLER_DIGITAL_UP)) {
		hooks.move_velocity(600);
	} else if (controller.get_digital(pros::E_CONTROLLER_DIGITAL_DOWN)) { // i would do !input but I dont know if that works here
		hooks.move_velocity(-600);
	} else{
		hooks.move_velocity(0);
	}
}
};

namespace pros::adi{
class pneumaticsClass{
	public:
    static void setLift() {
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
	static void setClamp() {
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
	static void setBackPack() { //we can make this toggle to a certain angle but  for now im gonna just have it be a manual control
		if (controller.get_digital(pros::E_CONTROLLER_DIGITAL_A)) {
			backPack.move_velocity(600);
		} else if (controller.get_digital(pros::E_CONTROLLER_DIGITAL_B)) {
			backPack.move_velocity(-600);
		} else {
			backPack.move_velocity(0);
		}
	}

};

