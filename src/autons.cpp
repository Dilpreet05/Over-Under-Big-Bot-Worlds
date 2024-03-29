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
  chassis.pid_drive_constants_forward_set(10,0,39.5);
  chassis.pid_drive_constants_backward_set(10,0,39.5);
  chassis.pid_heading_constants_set(4, 0, 22);
  chassis.pid_turn_constants_set(2.2, 0, 0);
  chassis.pid_swing_constants_forward_set(3.7,0,12.5);
  chassis.pid_swing_constants_backward_set(3.7,0,14.5);


  

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


/* This is the autonomous routine we use when we are in R16 or ELIMS */
/* This routine has more consistant scoring of triballs at the cost of no win point */
void matchCycleElims(){



}


/* This is the autonomous routine we call when we are playing in our qualification matches */
/* This rutine gets us win point as well as scoring as many triballs as possible */
void matchCycleQuals(){



}


void opcontrolCycle(){
  grabberDown();
  pros::delay(250);
  chassis.pid_drive_set(-10_in,DRIVE_SPEED);
  chassis.pid_wait();
  grabberUp();
  pros::delay(250);
  chassis.pid_drive_set(10_in,DRIVE_SPEED);
  chassis.pid_wait();
}


// 
// void leftWingDown(){
//   wingPistonLeft.set_value(1);
// }

// void rightWingDown(){
//   wingPistonRight.set_value(1);
// }

// void wingsDown(){
//   rightWingDown();
//   leftWingDown();
// }

// void leftWingUp(){
//   wingPistonLeft.set_value(0);
// }

// void rightWingUp(){
//   wingPistonRight.set_value(0);
// }

// void wingsUp(){
//   rightWingUp();
//   leftWingUp();
// }

void spinFW(){
  flywheel1 = 127;
  flywheel2 = 127;
}

void stopFW(){
  flywheel1 = 0;
  flywheel2 = 0;
  flywheel1.brake();
  flywheel2.brake();
}

void intakeSpin(){ // intake triballs for flywheel or controlling
  intakeMotor = 127;
}

void outtake(){ // outtake/pushout triballs
  intakeMotor = -127;
}

void stopIntake(){ // stops intake
  intakeMotor = 0;
}

void grabberDown(){
  GrabberPiston1.set_value(true);  // Deploy the piston
  GrabberPiston2.set_value(true);
}

void grabberUp(){
  GrabberPiston1.set_value(false);  // Deploy the piston
  GrabberPiston2.set_value(false);
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

