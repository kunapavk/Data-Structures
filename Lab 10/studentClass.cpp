#include "studentClass.h"
#include <iostream>
#include <string>

using namespace std;

student::student(string f, string l, string m, int y, double g){
    FirstName = f;
    LastName = l;
    MNumber = m;
    birthday = y;
    GPA = g;
}

student::student(string m) {
	MNumber = m;
}

string student::getName(){
    return (FirstName + " " + LastName);
}

string student::getMNumber(){
    return MNumber;
}

int student::getAge(){
    return (2017 - birthday);
}

bool student::operator > (const student& other)const{
  int first_student = stoi(this->MNumber.substr(1));
  int second_student = stoi(other.MNumber.substr(1));
  return (first_student > second_student);
}

bool student::operator < (const student& other)const{
	int first_student = stoi(this->MNumber.substr(1));
	int second_student = stoi(other.MNumber.substr(1));
	return (first_student < second_student);
}

bool student::operator == (const student& other)const{
	int first_student = stoi(MNumber.substr(1));
	int second_student = stoi(other.MNumber.substr(1));
    return (first_student == second_student);
}

bool student::operator != (const student& other) const {
	return !(*this == other);
}

void student::print() {
	string full_name = this->getName();
	string m_number = this->getMNumber();
	string birth_year = to_string(this->getAge());
	string out_line_1;
	for (int i = 0; i < 11 + full_name.length() + 2; i++) {
		out_line_1 += "-";
	}
	string out_line_2 = "|Full Name: " + full_name + "|";
	string out_line_3 = "|M-number: " + m_number;
	for (int i = out_line_3.length(); i < out_line_1.length()-1; i++) {
		out_line_3 += " ";
	}
	out_line_3 += "|";
	string out_line_4 = "|Age: " + birth_year;
	for (int i = out_line_4.length(); i < out_line_1.length() - 1; i++) {
		out_line_4 += " ";
	}
	out_line_4 += "|";
	cout << out_line_1 << endl << out_line_2 << endl << out_line_3 << endl << out_line_4 << endl;
	for (int i = 0; i < 11 + full_name.length() + 2; i++) {
		cout << "-";
	}
	cout << endl;
}