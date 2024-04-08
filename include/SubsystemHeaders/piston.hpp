#include "main.h"



// extern bool istrussPistonLeft;
// extern bool istrussPistonRight;

// extern bool isGrabberElasticExtended;

// extern bool isGrabberExtended;


extern pros::ADIDigitalOut grabberElasticPiston;
extern pros::ADIDigitalOut trussPistonLeft;
extern pros::ADIDigitalOut trussPistonRight;
extern pros::ADIDigitalOut HangPistonLeft;
extern pros:: ADIDigitalOut HangPistonRight;

void updatePistons();