#include "fish.h"
#include <iostream>

//setter
void fish::set_species(string t){
    species = t;
}

string fish::get_species() const {
	return species;
}

void fish::move() const {
	cout << "Just keep swimming." << endl;
}

void fish::eat() const {
	cout << "Yummy Fish Food." << endl;
}

