/* Copyright 2016 Charles Young */

#include <algorithm>
#include "swervelib.h"

double degrees_to_radians(double degrees) {
	double radians;
	radians = (degrees * PI)/180;
	return radians;
}

double radians_to_degrees(double radians) {
	double degrees;
	degrees = radians * 180/PI;
	return degrees;
}

swervelib::swervelib(double wheelbase, double trackwidth) {
	target_WS1 = 0;
	target_WS2 = 0;
	target_WS3 = 0;
	target_WS4 = 0;
	MAX_WS = 0;

	A = 0;
	B = 0;
	C = 0;
	D = 0;
	R = sqrt(pow(wheelbase, 2) + pow(trackwidth, 2));
	_wheelbase = wheelbase;

	whl = new wheel();
}

void swervelib::calcWheelVect(double x,
						 double y,
						 double rudder) {

	A = x - rudder * (_wheelbase/R);
	B = x + rudder * (_wheelbase/R);
	C = y - rudder * (_wheelbase/R);
	D = y + rudder * (_wheelbase/R);

	target_WS1 = sqrt(pow(B, 2) + pow(C, 2));
	target_WS2 = sqrt(pow(B, 2) + pow(D, 2));
	target_WS3 = sqrt(pow(A, 2) + pow(D, 2));
	target_WS4 = sqrt(pow(A, 2) + pow(C, 2));
	MAX_WS = std::max({target_WS1, target_WS2, target_WS3, target_WS4});

	// This is a mess
	if (target_WS1 > 1) {
		this->whl->speed1 = target_WS1/MAX_WS;
	} else {
		this->whl->speed1 = target_WS1;
	}
	if (target_WS2 > 1) {
		this->whl->speed2 = target_WS2/MAX_WS;
	} else {
		this->whl->speed2 = target_WS2;
	}
	if (target_WS3 > 1) {
		this->whl->speed3 = target_WS3/MAX_WS;
	} else {
		this->whl->speed3 = target_WS3;
	}
	if (target_WS4 > 1) {
		this->whl->speed4 = target_WS4/MAX_WS;
	} else {
		this->whl->speed4 = target_WS4;
	}

	/*
	* Gives the angle in radians between the positive X axis and the point given
	* by the coordinates.  The result is then converted to degrees.
	*/
	if (x > 0 && y > 0 && rudder > 0) {
		this->whl->angle1 = radians_to_degrees(atan2(B, C));
		this->whl->angle2 = radians_to_degrees(atan2(B, D));
		this->whl->angle3 = radians_to_degrees(atan2(A, D));
		this->whl->angle4 = radians_to_degrees(atan2(A, C));
	} else {
		this->whl->angle1 = 0;
		this->whl->angle2 = 0;
		this->whl->angle3 = 0;
		this->whl->angle4 = 0;
	}
}
