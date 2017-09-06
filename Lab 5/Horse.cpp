#include "Horse.h"
#include <iostream>

Horse::Horse() {
	colour = "";
}

Horse::Horse(string n, int a, string c) : animals(n,a) {
	colour = c;
}

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