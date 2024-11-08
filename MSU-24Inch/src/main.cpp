#include "main.h"
#include "robodash/api.h"

rd::Selector selector({
   {"Solo WP", &soloWP},
   {"Half WP", &halfWP},
   {"Skills", &skills},
});
rd::Console console;

void initialize() {
	console.println("Initializing robot...");
	chassis.calibrate(); // calibrate sensors
}

void disabled() {

}

void competition_initialize() {
  selector.focus();
}

void autonomous() {
	console.println("Running auton...");
	selector.run_auton();
}
void opcontrol() {
	console.clear();
	console.println("Driving...");
	while (true) {
  
		// get left y and right x positions
        int leftY = controller.get_analog(pros::E_CONTROLLER_ANALOG_LEFT_Y);
        int rightX = controller.get_analog(pros::E_CONTROLLER_ANALOG_RIGHT_X);

        // move the robot
        // prioritize steering slightly
        chassis.arcade(leftY, rightX, false, 0.75);

		//setting the user controls from subsystems
		//classes 🥵🥵🥵🥵🥵🥵🥵🥵🥵
		// Function heirarchy expalained so ex.) Pnu.drivelift(); -> Pnu = parent, driveLift = Child. so parent  is Pnu and the child is driveClamp()
	
		Pnu.driveLift(); //the drive keyword at the start of the child function means that the function will be assoicated with driver control, i.e it uses the controller most likley.
		Pnu.driveClamp();
		Hooks.driveHooks();
		BackPack.driveBackPack();
		Intake.driveIntakes();
		
		pros::delay(10);          // Run for 10 ms then update
	}
}
//stinky smelly