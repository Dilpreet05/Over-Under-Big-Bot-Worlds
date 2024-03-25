#include "main.h"

int isRatchetPistonExtended = 0;
pros::ADIDigitalOut ratchetPistonLeft('D');
pros::ADIDigitalOut ratchetPistonRight('E');


int isGrabberElasticExtended = 1;
pros::ADIDigitalOut grabberElasticPiston('F');


int isGrabberExtended = 0;
pros::ADIDigitalOut GrabberPiston1('H');
pros:: ADIDigitalOut GrabberPiston2('G');


void updatePistons(){

        // /* HANG CONTROLS */
        // if(master.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_DOWN)){
        //         isGrabberElasticExtended = !isGrabberElasticExtended;
        //         hangPiston.set_value(isGrabberElasticExtended);
        // }

        
        /* RATCHET CONTROLS */
        if(master.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_A)){
                isRatchetPistonExtended = !isRatchetPistonExtended;
                ratchetPistonLeft.set_value(isRatchetPistonExtended);
                ratchetPistonRight.set_value(isRatchetPistonExtended);  
        }





        /* GRABBER CONTROLS */
        if(master.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_R2)){
                isGrabberExtended = !isGrabberExtended;
                GrabberPiston1.set_value(isGrabberExtended);
                GrabberPiston2.set_value(isGrabberExtended);
        }

        pros::delay(20);

}
