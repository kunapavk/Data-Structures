#include "Horse.h"
#include "fish.h"
#include <iostream>

void call_eat_and_move(animals* a);

int main() {
	bool user_choice_bool = true;
	while (user_choice_bool) {
		int user_choice = 0;
		cout << "Welcome to the Testing Animals Program." << endl;
		cout << "Press 1 for an instance of an animal" << endl;
		cout << "Press 2 for an instance of a fish" << endl;
		cout << "Press 3 for an instance of a horse" << endl;
		cout << "Press 4 for an instance of a fish declared as an animal" << endl;
		cout << "Press 5 for an instance of a horse declared as an animal: ";
		cin >> user_choice;
		string animal_name;
		int animal_age;
		string fish_species;
		string horse_colour;
		switch (user_choice)
		{
		case 1:
		{
			animals* animal_instance = new animals();
			cout << "Please enter the name of the animal: ";
			cin.ignore();
			std::getline(cin, animal_name);
			animal_instance->set_name(animal_name);
			cout << "Please enter the age of the animal: ";
			cin >> animal_age;
			animal_instance->set_age(animal_age);
			cout << "Calling eat and move functions inside main" << endl;
			animal_instance->eat();
			animal_instance->move();
			cout << "Calling eat and move functions from inside declared function" << endl;
			call_eat_and_move(animal_instance);
		}
		break;
		case 2:
		{
			cout << "Please enter the name of the fish: ";
			cin.ignore();
			std::getline(cin, animal_name);
			cout << "Please enter the age of the fish: ";
			cin >> animal_age;
			cout << "Please enter the species of the fish: ";
			cin.ignore();
			std::getline(cin, fish_species);
			fish* fish_instance = new fish();
			fish_instance->set_name(animal_name);
			fish_instance->set_age(animal_age);
			fish_instance->set_species(fish_species);
			cout << "Calling eat and move functions inside main" << endl;
			fish_instance->eat();
			fish_instance->move();
			cout << "Calling eat and move functions from inside declared function" << endl;
			call_eat_and_move(fish_instance);
		}
		break;
		case 3:
		{
			cout << "Please enter the name of the horse: ";
			cin.ignore();
			std::getline(cin, animal_name);
			cout << "Please enter the age of the horse: ";
			cin >> animal_age;
			cout << "Please enter the colour of the horse: ";
			cin.ignore();
			std::getline(cin, horse_colour);
			Horse* horse_instance = new Horse();
			horse_instance->set_name(animal_name);
			horse_instance->set_age(animal_age);
			horse_instance->set_colour(horse_colour);
			cout << "Calling eat and move functions inside main" << endl;
			horse_instance->eat();
			horse_instance->move();
			cout << "Calling eat and move functions from inside declared function" << endl;
			call_eat_and_move(horse_instance);
		}
		break;
		case 4:
		{
			animals* animal_fish_instance = new fish();
			cout << "Please enter the name of the fish: ";
			cin.ignore();
			std::getline(cin, animal_name);
			animal_fish_instance->set_name(animal_name);
			cout << "Please enter the age of the fish: ";
			cin >> animal_age;
			animal_fish_instance->set_age(animal_age);
			cout << "Calling eat and move functions inside main: " << endl;
			animal_fish_instance->eat();
			animal_fish_instance->move();
			cout << "Calling eat and move functions from inside declared function" << endl;
			call_eat_and_move(animal_fish_instance);
		}
		break;
		case 5:
		{
			animals* animal_horse_instance = new Horse();
			cout << "Please enter the name of the horse: ";
			cin.ignore();
			std::getline(cin, animal_name);
			animal_horse_instance->set_name(animal_name);
			cout << "Please enter the age of the horse: ";
			cin >> animal_age;
			animal_horse_instance->set_age(animal_age);
			cout << "Calling eat and move functions inside main" << endl;
			animal_horse_instance->eat();
			animal_horse_instance->move();
			cout << "Calling eat and move functions from inside declared function" << endl;
			call_eat_and_move(animal_horse_instance);
		}
		break;
		default:
			cout << "Please select a number from 1-5";
			break;
		}
		char rerun_choice;
		cout << "Would you like to run through the program again? (Y/N): ";
		cin >> rerun_choice;
		user_choice_bool = (tolower(rerun_choice) == 'y');
	}
	return 0;
}

void call_eat_and_move(animals* a) {
	a->eat();
	a->move();
	return;
}