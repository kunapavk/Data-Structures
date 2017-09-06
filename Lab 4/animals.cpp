//This file is the implementation of animals class
#include "animals.h"
#include <iostream>

//constructor
animals::animals(){
    name = "";
    age = 0;
}
animals::animals(string n, int a){
    name = n;
    age = a;
}

//setter
void animals::set_name(string name_set){
    name = name_set;
}

void animals::set_age(int age_set){
    age = age_set;
}

//getter
string animals::get_name()const{
    return name;
}

int animals::get_age()const{
    return age;
}

//non-virtual function
void animals::eat(){
      cout << "Yummy!" <<endl;
}

void animals::move() const {
	cout << "This animal has now moved" << endl;
}