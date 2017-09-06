#ifndef studentClass_h
#define studentClass_h

#include <iostream>
#include <string>

using namespace std;

class student{
  private:
    string FirstName;
    string LastName;
    string MNumber;
    double GPA;
    int birthday;
  public:
    student(string f, string l, string m, int y, double g = 0.0);
	student(string m);
    string getName();
    string getMNumber();
    int getAge();
    bool operator > (const student& other)const;
    bool operator < (const student& other)const;
    bool operator == (const student& other)const;
	bool operator != (const student& other)const;
	void print();
};
#endif
