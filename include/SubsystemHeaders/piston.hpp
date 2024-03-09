#include "main.h"



extern bool isWingPistonLeft;
extern bool isWingPistonRight;

extern bool isHangExtended;

extern bool isGrabberExtended;


extern pros::ADIDigitalOut hangPiston;
extern pros::ADIDigitalOut wingPistonLeft;
extern pros::ADIDigitalOut wingPistonRight;
extern pros::ADIDigitalOut GrabberPiston1;
extern pros:: ADIDigitalOut GrabberPiston2;

void updatePistons();