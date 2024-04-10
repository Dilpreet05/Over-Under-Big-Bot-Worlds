#include "main.h"

int isTrussExtended = 0;
pros::ADIDigitalOut trussPistonLeft('E');

int isWingExtended = 0;
pros::ADIDigitalOut wingPistonRight('D');


int isHangExtended = 0;
pros::ADIDigitalOut HangPistonLeft('H');
pros:: ADIDigitalOut HangPistonRight('G');


void updatePistons(){


        
        /* WING/TRUSS CONTROLS */
        if(master.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_R1)){
                isTrussExtended = !isTrussExtended;
                trussPistonLeft.set_value(isTrussExtended);
        }

        if(master.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_B)){
                isWingExtended=!isWingExtended;
                wingPistonRight.set_value(isWingExtended);
        }




        /* HANG CONTROLS */
        if(master.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_R2) ){
                isHangExtended = !isHangExtended;
                HangPistonLeft.set_value(isHangExtended);
                HangPistonRight.set_value(isHangExtended);
        }

        pros::delay(20);

}
