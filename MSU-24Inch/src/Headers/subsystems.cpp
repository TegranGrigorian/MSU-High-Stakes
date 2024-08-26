#include "main.h"
#include "pros/adi.hpp"
#include "pros/adi.h"
#include "pros/misc.h"
using namespace pros;
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
void setLift() {
	bool toggle = false;
	leftLift.set_value(toggle);
	rightLift.set_value(toggle);
	if (controller.get_digital_new_press(E_CONTROLLER_DIGITAL_R1)) {
		toggle != toggle;
	}
}

