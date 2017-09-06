#include "Horse.h"
#include <iostream>

void Horse::set_colour(std::string c) {
	colour = c;
}

std::string Horse::get_colour() const {
	return colour;
}

void Horse::move() const {
	cout << "Walk, Trot, Canter, Gallop." << endl;
}

void Horse::eat() const {
	cout << "Yummy grass." << endl;
}