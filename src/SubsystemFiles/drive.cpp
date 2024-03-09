#include "main.h"

bool isArcade = false;
bool isFlipped = false;
bool loop = false;

ez::Drive chassis ({-20,-19,-18,-17}, {14,13,12,11}, 15 ,3.5,600,1.666);

void updateDrive(){

        if(master.get_digital(pros::E_CONTROLLER_DIGITAL_UP)){
                chassis.drive_imu_reset();
                matchCycleFar();
        }

        if(master.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_LEFT)){
                isArcade = !isArcade;
        }


        if(!isArcade){
                chassis.opcontrol_tank();
        }   else{
                chassis.opcontrol_arcade_standard(ez::SPLIT);
        }
        

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


