#include "main.h"

pros::Motor hangMotorLeft(18,pros::E_MOTOR_GEARSET_36,false);
pros::Motor hangMotorRight(12,pros::E_MOTOR_GEARSET_36,true);

void setHangBrake(){

    hangMotorLeft.set_brake_mode(MOTOR_BRAKE_HOLD);
    hangMotorRight.set_brake_mode(MOTOR_BRAKE_HOLD);

}

void updateHang(){

    if(master.get_digital(pros::E_CONTROLLER_DIGITAL_DOWN)){

        hangMotorLeft  = 127;
        hangMotorRight = 127;

    }else if(master.get_digital(pros::E_CONTROLLER_DIGITAL_B)){

        hangMotorLeft  = -127;
        hangMotorRight = -127;

    }else{
        hangMotorLeft  = 0;
        hangMotorRight = 0;
        hangMotorLeft.brake();
        hangMotorRight.brake();
    }

} 