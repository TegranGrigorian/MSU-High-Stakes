#ifndef SUBSYSTEMS_HPP
#define SUBSYSTEMS_HPP
#pragma once
class intakeClass {
    public:
    static void driveIntakes();
};


extern intakeClass Intake; // call the objects so we dont have to do it in our files!
class hookClass {
    public:
    static void driveHooks();
    static void teamScoring();
};
extern hookClass Hooks; //extern the class assingments so it can be referenced in multiple files without redefinition/ redefinition errors 

class pneumaticsClass{
	public:
    static bool toggleClamp;
    static bool toggleLift;
    static void driveLift();
	static void driveClamp();
    static void setLift(bool setLift);
    static void autonLift();
};
extern pneumaticsClass Pnu;

class backPackClass{
	public:
	static void driveBackPack();
    
};
extern backPackClass BackPack;

#endif // SUBSYSTEMS_HPP
