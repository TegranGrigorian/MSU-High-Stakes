#include "main.h"
#include "pros/adi.hpp"
#include "pros/adi.h"
#include "pros/misc.h"

void setIntakes(){
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

void setHooks(){ 
	if (controller.get_digital(pros::E_CONTROLLER_DIGITAL_UP)) {
		hooks.move_velocity(600);
	} else if (controller.get_digital(pros::E_CONTROLLER_DIGITAL_DOWN)) { // i would do !input but I dont know if that works here
		hooks.move_velocity(-600);
	} else{
		hooks.move_velocity(0);
	}
}

void setBackPack() { //we can make this toggle to a certain angle but  for now im gonna just have it be a manual control
	if (controller.get_digital(pros::E_CONTROLLER_DIGITAL_A)) {
		backPack.move_velocity(600);
	} else if (controller.get_digital(pros::E_CONTROLLER_DIGITAL_B)) {
		backPack.move_velocity(-600);
	} else {
		backPack.move_velocity(0);
	}
}

