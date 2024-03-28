#include "main.h"

pros::Motor intakeMotor(19,MOTOR_GEARSET_06,false);
pros::Motor intakeMotorTop(16,MOTOR_GEARSET_6,false);

void setIntakeBrakes(){
        intakeMotor.set_brake_mode(MOTOR_BRAKE_COAST);
}

void spinIntake(){

        if(master.get_digital(pros::E_CONTROLLER_DIGITAL_L1) && !(master.get_digital(pros::E_CONTROLLER_DIGITAL_L2))){
                intakeMotor = 127;
                intakeMotorTop = 127;
        }else if(master.get_digital(pros::E_CONTROLLER_DIGITAL_L2) && !(master.get_digital(pros::E_CONTROLLER_DIGITAL_L1))){
                intakeMotor = -127;
                intakeMotorTop = -127;
        }else{
                intakeMotor.brake();
                intakeMotorTop.brake();
        }
        
        pros::delay(20);


}

