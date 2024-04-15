#include "main.h"


int isRightWingExtended = 0;
pros::ADIDigitalOut wingPistonRight('D');

int isLeftWingExtended = 0;
pros::ADIDigitalOut wingPistonLeft('F');


int isHangExtended = 0;
pros::ADIDigitalOut HangPistonLeft('H');
pros:: ADIDigitalOut HangPistonRight('G');


void updatePistons(){



        if(master.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_DOWN)){
                isRightWingExtended=!isRightWingExtended;
                wingPistonRight.set_value(isRightWingExtended);
        }

        if(master.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_B)){

                isLeftWingExtended = !isLeftWingExtended;
                wingPistonLeft.set_value(isLeftWingExtended);

        }




        /* HANG CONTROLS */
        if(master.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_R2) ){
                isHangExtended = !isHangExtended;
                HangPistonLeft.set_value(isHangExtended);
                HangPistonRight.set_value(isHangExtended);
        }

        pros::delay(20);

}
