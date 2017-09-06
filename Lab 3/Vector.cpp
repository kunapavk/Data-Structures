#include "Vector.h"
#include <math.h>
#include <iostream>

#define PI 3.14159265

using namespace std;

void Vector_H::sety(int y) {
	y_coord = y;
}

void Vector_H::setx(int x) {
	x_coord = x;
}

void Vector_H::setmag(double mag) {
	magnitude = mag;
}

void Vector_H::setang(double ang) {
	angle = ang;
}

int Vector_H::gety() {
	return y_coord;
}

int Vector_H::getx() {
	return x_coord;
}

double Vector_H::getmag() {
	return magnitude;
}

double Vector_H::getang() {
	return angle;
}

Vector_H::Vector_H() {
	x_coord = 0;
	y_coord = 0;
	angle = 0;
	magnitude = 0;
}

Vector_H::Vector_H(int x, int y) {
	x_coord = x;
	y_coord = y;
	angle = atan(double(y_coord) / double(x_coord));
	magnitude = sqrt(pow(x_coord, 2) + pow(y_coord, 2));
}

Vector_H::Vector_H(double ang, double mag) {
	angle = ang;
	magnitude = mag;
	x_coord = magnitude * cos(angle);
	y_coord = magnitude * sin(angle);
}

void Vector_H::print_members() {
	cout << "X co-ordinate is: " << x_coord << endl;
	cout << "Y co-ordinate is: " << y_coord << endl;
	cout << "Angular value of Vector is: " << angle * 180 / PI << endl;
	cout << "Magnitude of the Vector is: " << magnitude << endl;
}

void Vector_H::operator == (const Vector_H& right) {
	x_coord = right.x_coord;
	y_coord = right.y_coord;
	angle = right.angle;
	magnitude = right.magnitude;
}

Vector_H Vector_H::operator + (const Vector_H& right) {
	Vector_H ret_val((x_coord + right.x_coord), (y_coord + right.y_coord));
	return ret_val;
}

Vector_H Vector_H::operator - (const Vector_H& right) {
	Vector_H ret_val((x_coord - right.x_coord), (y_coord - right.y_coord));
	return ret_val;
}

Vector_H Vector_H::operator * (const double& right) {
	Vector_H ret_val(int(x_coord * right), int(y_coord * right));
	return ret_val;
}

Vector_H Vector_H::operator / (const double& right) {
	Vector_H ret_val(int(x_coord / right), int(y_coord / right));
	return ret_val;
}