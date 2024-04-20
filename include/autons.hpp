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
    void disrupt();
    void scoreAllianceTriball();
    void matchLoad();
    void slam();

void eliminationMatchAuto();
    void eliminationDisrupt();
    void eliminationLineUp();
    void eliminationMatchLoad();
    void eliminationSlam();

void skills();
    void skillsLineUp();
    void skillsMatchLoad();
    void skillsSlam();


void swing(ez::e_swing,double, int speed = 90);
void turn(double, int speed = 90);
void drive(double,bool slew = false, int speed = 101);
/* Methods that control subsystems */

void intake();
void outtake();
void stopIntake();
void rightWingOut();
void rightWingIn();
void leftWingOut();
void leftWingIn();

void matchCycleClose();
void matchCycleFar();
void touchHangBar();

void skillsCycle();
void endOfSkills();
void startOfSkills();


/* misc */
void reset();
void opcontrolCycle();

