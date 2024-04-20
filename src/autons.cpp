#include "main.h"

/////
// For installation, upgrading, documentations and tutorials, check out our website!
// https://ez-robotics.github.io/EZ-Template/
/////

// These are out of 127
const int DRIVE_SPEED = 101;  
const int TURN_SPEED = 90;
const int SWING_SPEED = 90;

///
// Constants
///

void default_constants() {
 // PID Constants
  chassis.pid_drive_constants_forward_set(12.5,0,38.5);
  chassis.pid_drive_constants_backward_set(12.5,0,38.5);
  chassis.pid_heading_constants_set(4, 0, 22);
  chassis.pid_turn_constants_set(2.1, 0, 9.75);
  chassis.pid_swing_constants_forward_set(4.5,0,19.75);
  chassis.pid_swing_constants_backward_set(4.5,0,22.75);


  

  chassis.pid_turn_exit_condition_set(300_ms, 3_deg, 500_ms, 7_deg, 750_ms, 750_ms);
  chassis.pid_swing_exit_condition_set(300_ms, 3_deg, 500_ms, 7_deg, 750_ms, 750_ms);
  chassis.pid_drive_exit_condition_set(300_ms, 1_in, 500_ms, 3_in, 750_ms, 750_ms);

  chassis.slew_drive_constants_set(7_in, 80);
  chassis.slew_turn_constants_set(5_deg, 50);
  chassis.slew_swing_constants_set(5_deg, 50); // Sets forward and backward
}


// . . .
// Make your own autonomous functions here!
// . . .


/*
  WINPOINT AUTO
  1. grab the 2 center triballs and put them in the alley
  2. score the alliance color triball
  3. matchload triballs
  4. push the loaded triballs to the other side and score

*/
void qualificationMatchAuto(){
  // pros::delay(1250);
  disrupt();
  scoreAllianceTriball();
  matchLoad();
  slam();


}

void disrupt(){

  // outtake preload
  drive(24,true);
  turn(60);
  outtake();
  pros::delay(500);
  stopIntake();

  // intake close center ball
  turn(-60);
  intake();
  drive(26,true);

  // outtake close center ball
  drive(-26,true);
  turn(60);
  outtake();
  pros::delay(750);
  stopIntake();


  // disrupt center balls
  // leftWingOut();
  // drive(6);
  // turn(290);
  // leftWingIn();

}

void scoreAllianceTriball(){

  turn(-45);
  drive(-18);

  turn(-135);

  leftWingOut();

  turn(-65);
  turn(-135);
  leftWingIn();
  drive(-4);


  pros::delay(500);
  // turn(-135);

  drive(12);
  turn(-290);
  drive(-10);
  // swing(ez::RIGHT_SWING,-260,127);
  turn(-270);
  drive(5);
  drive(-9,127);


}

void matchLoad(){

  // line up to bar

  drive(12);
  turn(-320);
  drive(12);
  rightWingOut();
  drive(10);

  // cycle match loads

  chassis.drive_angle_set(40);

  for(int k = 0; k < 2; k++){
    turn(-15,127);
    turn(45);
  }

  turn(-15,127);
  rightWingIn();
  drive(-4);
  pros::delay(500);



  

}

void slam(){

  turn(45);
  drive(8);

  turn(22.5);
  drive(6);

  leftWingOut();


  turn(-180);
  drive(-72,true,DRIVE_SPEED/2);
  turn(-225,TURN_SPEED/2);
  rightWingOut();
  drive(-24,true,DRIVE_SPEED/2);

  rightWingIn();
  leftWingIn();

  pros::delay(500);

  drive(25,true);
  turn(-180);
  drive(31,true);




}

/*
  ELIMS auto

*/

void eliminationMatchAuto(){
  eliminationDisrupt();
  eliminationLineUp();
  eliminationMatchLoad();
  eliminationSlam();

}

void eliminationDisrupt(){

  // outtake preload
  drive(24,true);
  // turn(60);
  // outtake();
  // pros::delay(500);
  // stopIntake();

  // intake close center ball
  turn(-60);
  intake();
  drive(28,true);

  // spinny
  
  leftWingOut();
  chassis.pid_turn_relative_set(360,60);
  chassis.pid_wait();
  pros::delay(150);
  leftWingIn();

  // outtake close center ball
  drive(-28,true);
  turn(60);
  outtake();
  pros::delay(750);
  stopIntake();



}




void eliminationLineUp(){

  turn(-45);
  drive(-16);

  turn(45);
  rightWingOut();
  drive(3);

}

void eliminationMatchLoad(){

  for(int k = 0; k < 10; k++){
    if(k%3==0){
      drive(5);
    }

    turn(-30,127);
    turn(45);
    rightWingOut();

  }

  turn(-45);
  rightWingIn();

}

void eliminationSlam(){

  drive(8);
  turn(225);

  drive(-20,true);
  turn(180);

  leftWingOut();
  rightWingOut();

  drive(-73,true);
  turn(135);
  drive(-30);

  rightWingIn();
  leftWingIn();

  drive(15);
  turn(225);
  drive(-5,127);
  turn(135,127);
  drive(-20,127);
  
  turn(110,127);
  
  drive(10,127);
  drive(-40,127);
  // drive(20,127);


  // turn(90);
  // drive(-40,127);
  // drive(20,127);
  // turn(-30,127);
 


}


/* SKILL */

void skills(){
  skillsLineUp();
  skillsMatchLoad();
  skillsSlam();

}

void skillsLineUp(){
  drive(24,true);

  turn(-45);
  drive(-16);

  turn(45);
  rightWingOut();
  drive(3);

}

void skillsMatchLoad(){

    for(int k = 0; k < 23; k++){
    if(k%3==0){
      drive(5);
    }

    turn(-30,127);
    turn(45);
    rightWingOut();

  }

  turn(-45);
  rightWingIn();


}

void skillsSlam(){
  drive(8);
  turn(225);

  drive(-17,true);
  turn(180);

  leftWingOut();
  rightWingOut();

  drive(-60,true);

  rightWingIn();
  leftWingIn();

  drive(50);
  
  

}




/* Helper methods */

void drive(double target,bool slew, int speed){

  chassis.pid_drive_set(target,speed,slew);
  chassis.pid_wait();

}

void turn(double target, int speed){

  chassis.pid_turn_set(target,speed);
  chassis.pid_wait();

}

void swing(ez::e_swing type, double target,int speed){

  chassis.pid_swing_set(type,target,speed);
  chassis.pid_wait();

}
void rightWingOut(){
  wingPistonRight.set_value(1);
}

void rightWingIn(){
  wingPistonRight.set_value(0);
}

void leftWingOut(){
  wingPistonLeft.set_value(1);
}

void leftWingIn(){
  wingPistonLeft.set_value(0);
}

void intake(){ // intake triballs for flywheel or controlling
  intakeMotor = 127;
}

void outtake(){ // outtake/pushout triballs
  intakeMotor = -127;
}

void stopIntake(){ // stops intake
  intakeMotor = 0;
}

void reset(){ // 0s all sensors, including IMU and IMEs
  chassis.drive_imu_reset();
}

float valLeft = 0.0;
float valRight = 0.0;
float gyroVal = 0.0;

void tuneSwing(){

  chassis.pid_swing_set(ez::LEFT_SWING,90,SWING_SPEED);
  chassis.pid_wait();
  gyroVal = chassis.drive_imu_get();  

  

  printf("Degrees of turn: %lf\n",gyroVal);


  chassis.pid_swing_set(ez::LEFT_SWING,0,SWING_SPEED);
  chassis.pid_wait();
  gyroVal = chassis.drive_imu_get();  

  

  printf("Degrees of turn: %lf\n",gyroVal);

  

}

void tuneTurn(){

  chassis.pid_turn_set(90,TURN_SPEED);
  chassis.pid_wait();
  gyroVal = chassis.drive_imu_get();  

  

  printf("Degrees of turn: %lf\n",gyroVal);



  chassis.pid_turn_set(0,TURN_SPEED);
  chassis.pid_wait();

  gyroVal = chassis.drive_imu_get();  

  

  printf("Degrees of turn: %lf\n",gyroVal);

}

void tuneHeading(){


  chassis.pid_drive_set(24_in, DRIVE_SPEED,true);
  chassis.pid_wait();

  gyroVal = chassis.drive_imu_get();  

  

  printf("Degrees of turn: %lf\n",gyroVal);

  chassis.pid_drive_set(-24_in, DRIVE_SPEED);
  chassis.pid_wait();

  gyroVal = chassis.drive_imu_get();
  
  printf("Degrees of turn: %lf\n",gyroVal);



}


void tuneForwardBackward() { 
  // The first parameter is target inches
  // The second parameter is max speed the robot will drive at
  // The third parameter is a boolean (true or false) for enabling/disabling a slew at the start of drive motions
  // for slew, only enable it when the drive distance is greater then the slew distance + a few inches

  chassis.pid_drive_set(24_in, DRIVE_SPEED,true);
  chassis.pid_wait();
  // valLeft = chassis.drive_sensor_left()/  chassis.drive_tick_per_inch();
  // valRight = chassis.drive_sensor_right()/  chassis.drive_tick_per_inch();
    valLeft = chassis.drive_sensor_left();
  valRight = chassis.drive_sensor_right();

  

  printf("Distance Traveled: %lf\t%lf\n",valLeft,valRight);

  chassis.pid_drive_set(-24_in, DRIVE_SPEED);
  chassis.pid_wait();

  valLeft = chassis.drive_sensor_left();
  valRight = chassis.drive_sensor_right();
  
  printf("Distance Traveled: %lf\t%lf\n",valLeft,valRight);
  // chassis.pid_drive_set(-12_in, DRIVE_SPEED);
  // chassis.pid_wait();
}

///
// Turn Example
///
void turn_example() {
  // The first parameter is target degrees
  // The second parameter is max speed the robot will drive at

  chassis.pid_turn_set(90_deg, TURN_SPEED);
  chassis.pid_wait();

  chassis.pid_turn_set(45_deg, TURN_SPEED);
  chassis.pid_wait();

  chassis.pid_turn_set(0_deg, TURN_SPEED);
  chassis.pid_wait();
}

///
// Combining Turn + Drive
///
void drive_and_turn() {
  chassis.pid_drive_set(24_in, DRIVE_SPEED, true);
  chassis.pid_wait();

  chassis.pid_turn_set(45_deg, TURN_SPEED);
  chassis.pid_wait();

  chassis.pid_turn_set(-45_deg, TURN_SPEED);
  chassis.pid_wait();

  chassis.pid_turn_set(0_deg, TURN_SPEED);
  chassis.pid_wait();

  chassis.pid_drive_set(-24_in, DRIVE_SPEED, true);
  chassis.pid_wait();
}

///
// Wait Until and Changing Max Speed
///
void wait_until_change_speed() {
  // pid_wait_until will wait until the robot gets to a desired position

  // When the robot gets to 6 inches, the robot will travel the remaining distance at a max speed of 30
  chassis.pid_drive_set(24_in, DRIVE_SPEED, true);
  chassis.pid_wait_until(6_in);
  chassis.pid_speed_max_set(30);  // After driving 6 inches at DRIVE_SPEED, the robot will go the remaining distance at 30 speed
  chassis.pid_wait();

  chassis.pid_turn_set(45_deg, TURN_SPEED);
  chassis.pid_wait();

  chassis.pid_turn_set(-45_deg, TURN_SPEED);
  chassis.pid_wait();

  chassis.pid_turn_set(0_deg, TURN_SPEED);
  chassis.pid_wait();

  // When the robot gets to -6 inches, the robot will travel the remaining distance at a max speed of 30
  chassis.pid_drive_set(-24_in, DRIVE_SPEED, true);
  chassis.pid_wait_until(-6_in);
  chassis.pid_speed_max_set(30);  // After driving 6 inches at DRIVE_SPEED, the robot will go the remaining distance at 30 speed
  chassis.pid_wait();
}

///
// Swing Example
///
void swing_example() {
  // The first parameter is ez::LEFT_SWING or ez::RIGHT_SWING
  // The second parameter is target degrees
  // The third parameter is speed of the moving side of the drive
  // The fourth parameter is the speed of the still side of the drive, this allows for wider arcs

  chassis.pid_swing_set(ez::LEFT_SWING, 45_deg, SWING_SPEED, 45);
  chassis.pid_wait();

  chassis.pid_swing_set(ez::RIGHT_SWING, 0_deg, SWING_SPEED, 45);
  chassis.pid_wait();

  chassis.pid_swing_set(ez::RIGHT_SWING, 45_deg, SWING_SPEED, 45);
  chassis.pid_wait();

  chassis.pid_swing_set(ez::LEFT_SWING, 0_deg, SWING_SPEED, 45);
  chassis.pid_wait();
}

///
// Auto that tests everything
///
void combining_movements() {
  chassis.pid_drive_set(24_in, DRIVE_SPEED, true);
  chassis.pid_wait();

  chassis.pid_turn_set(45_deg, TURN_SPEED);
  chassis.pid_wait();

  chassis.pid_swing_set(ez::RIGHT_SWING, -45_deg, SWING_SPEED, 45);
  chassis.pid_wait();

  chassis.pid_turn_set(0_deg, TURN_SPEED);
  chassis.pid_wait();

  chassis.pid_drive_set(-24_in, DRIVE_SPEED, true);
  chassis.pid_wait();
}

///
// Interference example
///
void tug(int attempts) {
  for (int i = 0; i < attempts - 1; i++) {
    // Attempt to drive backwards
    printf("i - %i", i);
    chassis.pid_drive_set(-12_in, 127);
    chassis.pid_wait();

    // If failsafed...
    if (chassis.interfered) {
      chassis.drive_sensor_reset();
      chassis.pid_drive_set(-2_in, 20);
      pros::delay(1000);
    }
    // If robot successfully drove back, return
    else {
      return;
    }
  }
}

// If there is no interference, robot will drive forward and turn 90 degrees.
// If interfered, robot will drive forward and then attempt to drive backwards.
void interfered_example() {
  chassis.pid_drive_set(24_in, DRIVE_SPEED, true);
  chassis.pid_wait();

  if (chassis.interfered) {
    tug(3);
    return;
  }

  chassis.pid_turn_set(90_deg, TURN_SPEED);
  chassis.pid_wait();
}

