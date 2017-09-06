#include <iostream>
#include <string>
#include "LinkedList.h"
#include "studentClass.h"

struct Node {
	student data;
	Node* next;
};

using namespace std;

int get_user_choice();
void print(Node* val);

int main() {
	int user_choice = get_user_choice();
	while (user_choice - 10 > 0 && user_choice-10 < -9) {
		cout << "Please select a proper input(1-10)" << endl;
		user_choice = get_user_choice();
	}

	string student_first_name, student_last_name, Mnumber, student_m;
	string student_birth_s, student_GPA_s;
	int student_birth;
	double student_GPA;

	LinkedList<Node> a;
	while (user_choice != 10) {

		switch (user_choice) {
		case 1: {
			cout << "Enter the first name of the student: ";
			getline(cin, student_first_name);
			cout << "Enter the last name of the student: ";
			getline(cin, student_last_name);
			cout << "Enter the M number of the student: ";
			getline(cin, Mnumber);
			cout << "Enter the year in which the student was born: ";
			getline(cin, student_birth_s);
			student_birth = stoi(student_birth_s);
			cout << "Enter the GPA of the student(if applicable): ";
			getline(cin, student_GPA_s);
			student_GPA = stod(student_GPA_s);
			student temp(student_first_name, student_last_name, Mnumber, student_birth, student_GPA);
			Node* temp_node = new Node{ temp, nullptr };
			a.addItem(temp_node);
			break;
		}
		case 2:
		{
			cout << "Enter the Mnumber of the student you wish to remove: ";
			getline(cin, student_m);
			student temp_find(student_m);
			Node* temp_find_node = new Node{ temp_find, nullptr };
			Node* ret_val = a.getItem(temp_find_node);
			cout << "The found item is as follows: " << endl;
			print(ret_val);
			break;
		}
		case 3:
		{
			cout << "Enter the Mnumber of the student you wish to check for: ";
			getline(cin, student_m);
			student temp_find(student_m);
			Node* temp_find_node = new Node{ temp_find, nullptr };
			bool ret_val = a.isInList(temp_find_node);
			if (ret_val) {
				cout << "The item you're looking for exists in the list" << endl;
			}
			else {
				cout << "The item you're looking for does not exist in the list" << endl;
			}
			break;
		}
		case 4:
		{
			bool ret_val = a.isEmpty();
			if (ret_val) {
				cout << "The list is currently empty" << endl;
			}
			else {
				cout << "The list is not empty" << endl;
			}
			break;
		}
		case 5: {
			int size = a.size();
			cout << "The current size of the list is " << size << " students." << endl;
			break;
		}
		case 6: {
			Node* temp_node = a.seeNext();
			cout << "The student at the next location is as follows:" << endl;
			print(temp_node);
			break;
		}
		case 7: {
			int user_pos;
			string user_pos_s;
			cout << "Please enter the position in the list you wish to see: ";
			getline(cin, user_pos_s);
			user_pos = stoi(user_pos_s);
			Node* temp_node = a.seeAt(user_pos);
			cout << "The student at the position is:" << endl;
			print(temp_node);
			break;
		}
		case 8: {
			a.reset();
			cout << "The internal location has now been reset" << endl;
			break;
		}
		case 9: {
			a.print();
			break;
		}
		default: {
			cout << "Incorrect input. Please restart the program" << endl;
			break;
		}
		}
		cout << "\n\n\n\n" << endl;
		user_choice = get_user_choice();
		while (user_choice - 10 > 0 && user_choice - 10 < -9) {
			cout << "Please select a proper input(1-10)" << endl;
			user_choice = get_user_choice();
		}
		}
	cout << "Ending program..." << endl;
	return 0;
}

int get_user_choice() {
	cout << "Please select the use case which you want to test from the following:" << endl;
	cout << "1.Add item to linked list" << endl;
	cout << "2.Remove item from linked list" << endl;
	cout << "3.Check if the item is in the list" << endl;
	cout << "4.Check if list is empty" << endl;
	cout << "5.Check the size of the list" << endl;
	cout << "6.See the next item in the list" << endl;
	cout << "7.See the item in the list according to location" << endl;
	cout << "8.Reset the internal location of the list" << endl;
	cout << "9.Print the entire linked list" << endl;
	cout << "10.Stop the program" << endl;
	cout << "Enter the number for which function you wish to test: ";
	int ret_val;
	string ret_val_s;
	getline(cin, ret_val_s);
	ret_val = stoi(ret_val_s);
	return ret_val;
}

void print(Node* val) {
	if (val) {
		cout << "The returned student's name is: " << val->data.getName() << endl;
		cout << "The returned student's M number is: " << val->data.getMNumber() << endl;
		cout << "The returned student's age is: " << val->data.getAge() << endl;
	}
	else {
		cout << "The student you were looking for does not exist in the list" << endl;
	}
}