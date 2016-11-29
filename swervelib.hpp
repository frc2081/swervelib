/* Copyright 2016 Charles Young */

#include <cmath>

static double degrees_to_radians(double degrees);
static double radians_to_degrees(double radians);
class swervelib {
public:
    double A, B, C, D, R;
    double target_WS1, target_WS2, target_WS3, target_WS4, MAX_WS;
    swervelib(double wheelbase, double trackwidth);
    static struct wheel {
        // front right, front left, rear left, rear right
        double speed1, speed2, speed3, speed4;
        // front right, front left, rear left, rear right
        double angle1, angle2, angle3, angle4;
    } whl;
    static wheel calcWheelVect(double x, double y, double rudder, double R, double wheelbase);
};
