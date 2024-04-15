#include "main.h"

bool isArcade = false;
bool isFlipped = false;
bool loop = false;

ez::Drive chassis ({-20,-19,-10}, {11,12,1}, 15 ,3.25,600,1.666);

void updateDrive(){

        if(master.get_digital(pros::E_CONTROLLER_DIGITAL_LEFT)){
                chassis.drive_imu_reset();
                chassis.opcontrol_drive_reverse_set(!chassis.opcontrol_drive_reverse_get());
        }

        if(master.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_UP)){
                // macro
        }

        chassis.opcontrol_tank();
        

        pros::delay(50);
}

/* Redundent Code */

// void forwardBackwardLoop(){        

//         chassis.drive_imu_reset();

//         while(true){

//                 skillsCycle();
                
//                 if(master.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_UP)){
//                         break;

//                 }
//                 pros::delay(50);
//         }

// }


