#pragma once
#include "main.h"

// #include "EZ-Template/drive/drive.hpp"

// extern Drive chassis;
extern float valLeft;
extern float valRight;



void tuneForwardBackward();
void tuneHeading();
void tuneTurn();
void tuneSwing();


void default_constants();


void qualificationMatchAuto();
void eliminationMatchAuto();



/* Methods that control subsystems */

void intakeSpin();
void outtake();
void stopIntake();




void scoreAllianceTriball();
void matchCycleClose();
void matchCycleFar();
void touchHangBar();

void skillsCycle();
void endOfSkills();
void startOfSkills();


/* misc */
void reset();
void opcontrolCycle();

