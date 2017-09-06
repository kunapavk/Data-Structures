#include "fish.h"
#include "AnimalCollection.h"
#include <iostream>

using namespace std;


int main() {
	bool user_choice_bool = true;
	int user_choice_int;
	string temp_fish_name;
	int temp_fish_age;
	string temp_fish_species;
	AnimalCollection <fish> animal_collection_fish;
	cout << "Welcome to the Animal Collection testing program" << endl;
	while (user_choice_bool) {
		cout << "Press 1 to add a fish to the animal collection" << endl;
		cout << "Press 2 to remove a fish from the animal collection" << endl;
		cout << "Press 3 to see how many fishes are currently in the animal collection" << endl;
		cout << "Press 4 to quit: ";
		cin >> user_choice_int;

		try {
			switch (user_choice_int) {
			case 1:
			{
				cout << "Please enter name of the fish: ";
				cin.ignore();
				getline(cin, temp_fish_name);
				cout << "Pleae enter age of the fish: ";
				cin >> temp_fish_age;
				cout << "Please enter the species of the fish: ";
				cin.ignore();
				getline(cin, temp_fish_species);
				fish temp_fish(temp_fish_name, temp_fish_age, temp_fish_species);
				animal_collection_fish.add_animal(temp_fish);
				break;
			}
			case 2:
			{
				fish temp_removal = animal_collection_fish.remove_animal();
				cout << "The removed fish's name is: " << temp_removal.get_name() << endl;
				cout << "The removed fish's age is: " << temp_removal.get_age() << endl;
				cout << "The removed fish's colour is: " << temp_removal.get_species() << endl;
				break;
			}
			case 3:
			{
				cout << "The number of fishes in the animal collection currently are: " << animal_collection_fish.get_num_animals() << endl;
				break;
			}
			case 4:
			{
				user_choice_bool = false;
				break;
			}
			default:
			{
				cout << "Try again. Enter only 1-4" << endl;
				break;
			}
			}
		}
		catch (const AnimalCollection<fish>::FullStable) {
			cout << "The animal collection already has " << MAX_ANIMALS << " number of fishs" << endl;
			cout << "You can try to remove a fish instead" << endl;
		}
		catch (const AnimalCollection<fish>::EmptyStable) {
			cout << "The animal collection has no fishes to remove" << endl;
			cout << "You can try to add a fish instead" << endl;
		}

	}
}