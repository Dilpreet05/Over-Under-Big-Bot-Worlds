#include "main.h"

pros::Motor flywheel1(10,MOTOR_GEARSET_06,false);
pros::Motor flywheel2(1,MOTOR_GEARSET_06,true);

void setFlywheelBrake(){
        flywheel1.set_brake_mode(MOTOR_BRAKE_COAST);
        flywheel2.set_brake_mode(MOTOR_BRAKE_COAST);
}

void spinFlywheel(){
        eBrake();
        if(master.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_R1)){
                flywheel1 = 127;
                flywheel2 = 127;
        }

        pros::delay(20);

}

void eBrake(){

        if(master.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_Y)){
                flywheel1=0;
                flywheel2=0;
        }

}