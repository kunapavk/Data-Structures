#include "HashTable.h"
#include "studentClass.h"

#define USER_CHOICES 5

class Node {
	public:
	student data;
	bool is_deleted;
	operator string() const {
		return string(this->data);
	}
	Node(student s) {
		this->data = s;
		this->is_deleted = false;
	}
	bool operator == (const Node& other) {
		return other.data == this->data;
	}
};

int get_user_choice();
void print(Node* print_val);

using namespace std;

int main() {
	int user_choice = get_user_choice();
	while (user_choice - USER_CHOICES > 0 && user_choice - USER_CHOICES < -1*(USER_CHOICES - 1)) {
		cout << "Please select a proper input(1-5)" << endl;
		user_choice = get_user_choice();
	}

	string student_first_name, student_last_name, Mnumber, student_m;
	string student_birth_s, student_GPA_s;
	int student_birth;
	double student_GPA;

	HashTable<Node> a;
	while (user_choice != 5) {
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
			Node* temp_to_add = new Node(student(student_first_name, student_last_name, Mnumber, student_birth, student_GPA));
			a.add_item(temp_to_add);
			break;
		}
		case 2:
		{
			cout << "Enter the Mnumber of the student you wish to remove: ";
			getline(cin, student_m);
			Node* temp_to_remove = new Node(student(student_m));
			Node* removed_item = a.remove_item(temp_to_remove);
			print(removed_item);
			break;
		}
		case 3:
		{
			cout << "Enter the Mnumber of the student you wish to get: ";
			getline(cin, student_m);
			Node* temp_to_get = new Node(student(student_m));
			Node* got_item = a.get_item(temp_to_get);
			print(got_item);
			break;
		}
		case 4: 
		{
			int size = a.get_length();
			cout << "The current size of the has table is: " << size << " students." << endl;
			break;
		}
		default:
		{
			cout << "Incorrect input. Please restart the program" << endl;
			break;
		}
		}
		cout << "\n\n\n\n" << endl;
		user_choice = get_user_choice();
		while (user_choice - USER_CHOICES > 0 && user_choice - USER_CHOICES < -1 * (USER_CHOICES - 1)) {
			cout << "Please select a proper input(1-5)" << endl;
			user_choice = get_user_choice();
		}
	}
	cout << "Ending program...." << endl;
	return 0;
}

int get_user_choice() {
	cout << "Please select the use case which you want to test from the following:" << endl;
	cout << "1.Add item to hash table" << endl;
	cout << "2.Remove item from hash table" << endl;
	cout << "3.Get item from hash table" << endl;
	cout << "4.Get the size of the hash table" << endl;
	cout << "5.Stop the program" << endl;
	cout << "Enter the number for which function you wish to test: ";
	int ret_val;
	string ret_val_s;
	getline(cin, ret_val_s);
	ret_val = stoi(ret_val_s);
	return ret_val;
}

void print(Node* print_val) {
	if (print_val) {
		cout << "The student is as follows: " << endl;
		print_val->data.print();
	}
	else {
		cout << "The student was not found" << endl;
	}
}