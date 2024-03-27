#include "main.h"

extern pros::Optical opticalSensor;

void printValue();

void setOpticalLight(int value);

bool detectGreenObject();

bool detectBlueObject();

bool detectRedObject();

bool detectIntakeObject(int min_dist, int max_dist);

bool detectColorObject(int min_value, int max_value);




