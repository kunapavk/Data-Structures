#ifndef VECTOR_H
#define VECTOR_H

class Vector_H {
private:
	int x_coord;
	int y_coord;
	double angle;
	double magnitude;
public:
	void sety(int y);
	int gety();
	void setx(int x);
	int getx();
	void setmag(double mag);
	double getmag();
	void setang(double ang);
	double getang();
	Vector_H();
	Vector_H(int x, int y);
	Vector_H(double angle, double magnitude);
	void print_members();
	void operator==(const Vector_H& right);
	Vector_H operator+(const Vector_H& right);
	Vector_H operator-(const Vector_H& right);
	Vector_H operator*(const double& right);
	Vector_H operator/(const double& right);
};

#endif