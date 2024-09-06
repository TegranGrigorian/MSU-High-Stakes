#ifndef SUBSYSTEMS_H
#define SUBSYSTEMS_H

class intakeClass {
    public:
    static void setIntakes();
};

intakeClass Intake; // call the objects so we dont have to do it in our files!
class hookClass {
    public:
    static void setHooks();
};
hookClass Hooks; 

class pneumaticsClass{
	public:
    static void setLift();
	static void setClamp();
};
pneumaticsClass Pnu;

class backPackClass{
	public:
	static void setBackPack();
    
};
backPackClass BackPack;
#endif // SUBSYSTEMS_H