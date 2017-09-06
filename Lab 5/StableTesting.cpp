#include "Stable.h"
#include <iostream>

using namespace std;

int main() {
	bool user_choice_bool = true;
	int user_choice_int;
	string temp_horse_name;
	int temp_horse_age;
	string temp_horse_colour;
	Stable test_stable;
	cout << "Welcome to the Stable testing program" << endl;
	while (user_choice_bool) {
		cout << "Press 1 to add a horse to the stable" << endl;
		cout << "Press 2 to remove a horse from the stable" << endl;
		cout << "Press 3 to see how many horses are currently in the stable" << endl;
		cout << "Press 4 to quit: ";
		cin >> user_choice_int;

		try {
			switch (user_choice_int) {
				case 1:
				{
					cout << "Please enter name of the horse: ";
					cin.ignore();
					getline(cin, temp_horse_name);
					cout << "Pleae enter age of the horse: ";
					cin >> temp_horse_age;
					cout << "Please enter the colour of the horse: ";
					cin.ignore();
					getline(cin, temp_horse_colour);
					Horse temp_horse(temp_horse_name, temp_horse_age, temp_horse_colour);
					test_stable.add_horse(temp_horse);
					break;
				}
				case 2:
				{
					Horse temp_removal = test_stable.remove_horse();
					cout << "The removed horse's name is: " << temp_removal.get_name() << endl;
					cout << "The removed horse's age is: " << temp_removal.get_age() << endl;
					cout << "The removed horse's colour is: " << temp_removal.get_colour() << endl;
					break;
				}
				case 3:
				{
					cout << "The number of horses in the stable currently are: " << test_stable.get_num_horses() << endl;
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
		catch (const Stable::FullStable) {
			cout << "The stable already has " << MAX_HORSES << " number of horses" << endl;
			cout << "You can try to remove a horse instead" << endl;
		}
		catch (const Stable::EmptyStable) {
			cout << "The stable has no horses to remove" << endl;
			cout << "You can try to add a horse instead" << endl;
		}

	}
}