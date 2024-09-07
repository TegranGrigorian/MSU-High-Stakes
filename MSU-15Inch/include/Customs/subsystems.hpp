#ifndef SUBSYSTEMS_H
#define SUBSYSTEMS_H

class intakeClass {
    public:
    static void driveIntakes();
};

intakeClass Intake; // call the objects so we dont have to do it in our files!
class hookClass {
    public:
    static void driveHooks();
};
hookClass Hooks; 

class pneumaticsClass{
	public:
    static bool toggleClamp;  // Declaration
    static bool toggleLift;   // Declaration
    static void driveLift();
	static void driveClamp();
};
pneumaticsClass Pnu;

class backPackClass{
	public:
	static void driveBackPack();
    
};
backPackClass BackPack;
#endif // SUBSYSTEMS_H