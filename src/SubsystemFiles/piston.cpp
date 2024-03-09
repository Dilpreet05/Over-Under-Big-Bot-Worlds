#include "main.h"

bool isWingPistonLeft = false;
pros::ADIDigitalOut wingPistonLeft('D');


bool isWingPistonRight = false;
pros::ADIDigitalOut wingPistonRight('E');


bool isHangExtended = false;
pros::ADIDigitalOut hangPiston('C');


bool isGrabberExtended = false;
pros::ADIDigitalOut GrabberPiston1('A');
pros:: ADIDigitalOut GrabberPiston2('B');


void updatePistons(){

        /* HANG CONTROLS */
        if(master.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_DOWN)){
                isHangExtended = !isHangExtended;
                hangPiston.set_value(isHangExtended);
        }

        
        /* RIGHT WING CONTROLS */
        if(master.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_A)){
                isWingPistonRight = !isWingPistonRight;
                wingPistonRight.set_value(isWingPistonRight);
        }


        /* LEFT WING CONTROLS */
        if(master.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_RIGHT)){
                isWingPistonLeft = !isWingPistonLeft;
                wingPistonLeft.set_value(isWingPistonLeft);
        }


        /* GRABBER CONTROLS */
        if(master.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_R2)){
                isGrabberExtended = !isGrabberExtended;
                GrabberPiston1.set_value(isGrabberExtended);
                GrabberPiston2.set_value(isGrabberExtended);
        }

        pros::delay(20);

}
