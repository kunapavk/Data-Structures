#include "BTree.h"
#include "Node.h"
#include <iostream>

#define MAX_CHOICE 6

using namespace std;

int get_user_choice();

int main() {
	BTree<int> a;
	int user_input = get_user_choice();
	int operations_holder = 0;
	while (user_input > MAX_CHOICE || user_input < 1) {
		cout << "Incorrect input. Please enter numbers from 1 to 6 only. Please try again" << endl;
		cin >> user_input;
	}
	while (user_input != 6) {
		switch (user_input) {
		case 1:
		{
			cout << "Enter an item you wish to insert into the tree: ";
			int insert_val;
			cin >> insert_val;
			a.insert_item(new int(insert_val), operations_holder);
			break;
		}
		case 2:
		{
			cout << "Enter an item you wish to find in the tree: ";
			int find_val;
			cin >> find_val;
			int* found = a.find_item(find_val, operations_holder);
			if (found) {
				cout << "The found item is as follows: " << *found << endl;
			}
			else {
				cout << "The required item was not found" << endl;
			}
			break;
		}
		case 3:
		{
			int tree_size = a.get_tree_size();
			cout << "The current tree's size is: " << tree_size << endl;
			break;
		}
		case 4:
		{
			int tree_height = a.get_tree_height();
			cout << "The current tree's height is: " << tree_height << endl;
			break;
		}
		case 5: {
			a.print();
			break;
		}
		default: {
			cout << "Incorrect input. Please try again" << endl;
			break;
		}
		}
		cout << "\n\n\n\n" << endl;
		user_input = get_user_choice();
		while (user_input > MAX_CHOICE || user_input < 1) {
			cout << "Incorrect input. Please enter numbers from 1 to 6 only. Please try again" << endl;
			cin >> user_input;
		}
	}
	cout << "Ending program..." << endl;
	return 0;
}

int get_user_choice() {
	cout << "Please enter a choice from 1 to 6 to select what you wish to do with the program" << endl;
	cout << "1. Add an item into the tree" << endl;
	cout << "2. Find an item in the tree" << endl;
	cout << "3. Get the size of the tree" << endl;
	cout << "4. Get the height of the tree" << endl;
	cout << "5. Print the current tree" << endl;
	cout << "6. End the program" << endl;
	int ret_val;
	cin >> ret_val;
	return ret_val;
}