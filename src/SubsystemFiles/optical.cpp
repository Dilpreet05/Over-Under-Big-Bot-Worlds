#include "main.h"

pros::Optical opticalSensor(17, 50);

void printValue(){
    pros::c::optical_rgb_s_t rgb_value;
    pros::lcd::print(0, "Hue: %.2f, Dis:%d", opticalSensor.get_hue(),opticalSensor.get_proximity());
    pros::lcd::print(1, "Sat: %.2f, Bri:%.5f", opticalSensor.get_saturation(),opticalSensor.get_brightness());
    rgb_value = opticalSensor.get_rgb();
    pros::lcd::print(2, "R: %.2f, G: %.2f, B: %.2f", rgb_value.red, rgb_value.green, rgb_value.blue);
    
}

void setOpticalLight(int value){
    opticalSensor.set_led_pwm(value);
}

bool detectRedObject(){
    double hue = opticalSensor.get_hue();
    if (hue >= 11 && hue <= 17){
        return true;
    }
    return false;
}

bool detectGreenObject(){
    double hue = opticalSensor.get_hue();
    if (hue >= 80 && hue <= 90){
        return true;
    }
    return false;
}

bool detectBlueObject(){
    double hue = opticalSensor.get_hue();
    if (hue >= 210 && hue <= 235){
        return true;
    }
    return false;
}

bool detectColorObject(double min_value, double max_value){
    double hue = opticalSensor.get_hue();
    if (hue >= min_value && hue <= max_value){
        return true;
    }
    return false;
}

bool detectIntakeObject(int min_dist=150, int max_dist=270){
    int dist = opticalSensor.get_proximity();
    if (dist >= min_dist && dist <= max_dist){
        return true;
    }
    return false;
}