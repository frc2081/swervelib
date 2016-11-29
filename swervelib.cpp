/* Copyright 2016 Charles Young */

#include <algorithm>
#include "swervelib.hpp"

static double degrees_to_radians(double degrees) {
  double radians;
  radians = (degrees * M_PI)/180;
  return radians;
}

static double radians_to_degrees(double radians) {
  double degrees;
  degrees = radians * 180/M_PI;
  return degrees;
}

swervelib::swervelib(double wheelbase, double trackwidth) {
  R = sqrt(pow(wheelbase, 2) + pow(trackwidth, 2));
}

swervelib::wheel swervelib::calcWheelVect(
        double x,
        double y,
        double rudder,
        double R,
        double wheelbase) {

  double A = x - rudder * (wheelbase/R);
  double B = x + rudder * (wheelbase/R);
  double C = y - rudder * (wheelbase/R);
  double D = y + rudder * (wheelbase/R);

  double target_WS1 = sqrt(pow(B, 2) + pow(C, 2));
  double target_WS2 = sqrt(pow(B, 2) + pow(D, 2));
  double target_WS3 = sqrt(pow(A, 2) + pow(D, 2));
  double target_WS4 = sqrt(pow(A, 2) + pow(C, 2));
  double MAX_WS = std::max({target_WS1, target_WS2, target_WS3, target_WS4});
  wheel *whl = new swervelib::wheel;
  // This is a mess
  if (target_WS1 > 1) {
    whl->speed1 = target_WS1/MAX_WS;
  } else {
    whl->speed1 = target_WS1;
  }
  if (target_WS2 > 1) {
    whl->speed2 = target_WS2/MAX_WS;
  } else {
    whl->speed2 = target_WS2;
  }
  if (target_WS3 > 1) {
    whl->speed3 = target_WS3/MAX_WS;
  } else {
    whl->speed3 = target_WS3;
  }
  if (target_WS4 > 1) {
    whl->speed4 = target_WS4/MAX_WS;
  } else {
    whl->speed4 = target_WS4;
  }

  /*
  * Gives the angle in radians between the positive X axis and the point given
  * by the coordinates.  The result is then converted to degrees.
  */
  if (x > 0 && y > 0 && rudder > 0) {
    whl->angle1 = radians_to_degrees(atan2(B, C));
    whl->angle2 = radians_to_degrees(atan2(B, D));
    whl->angle3 = radians_to_degrees(atan2(A, D));
    whl->angle4 = radians_to_degrees(atan2(A, C));
  } else {
    whl->angle1 = 0;
    whl->angle2 = 0;
    whl->angle3 = 0;
    whl->angle4 = 0;
  }
  return swervelib::wheel();
}
