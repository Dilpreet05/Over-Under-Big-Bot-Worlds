#include "main.h"

int isTrussExtended = 0;
pros::ADIDigitalOut trussPistonLeft('D');
pros::ADIDigitalOut trussPistonRight('E');




int isHangExtended = 0;
pros::ADIDigitalOut HangPistonLeft('H');
pros:: ADIDigitalOut HangPistonRight('G');


void updatePistons(){


        
        /* WING/TRUSS CONTROLS */
        if(master.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_R1)){
                isTrussExtended = !isTrussExtended;
                trussPistonLeft.set_value(isTrussExtended);
                trussPistonRight.set_value(isTrussExtended);  
        }





        /* HANG CONTROLS */
        if(master.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_R2) ){
                isHangExtended = !isHangExtended;
                HangPistonLeft.set_value(isHangExtended);
                HangPistonRight.set_value(isHangExtended);
        }

        pros::delay(20);

}
