#include <iostream>
#include <string>
#include "Vector.h"

using namespace std;

//Function prototyping
Vector_H get_second_vector();
double get_user_num_choice();

int main() {
	bool user_choice = true;
	while (user_choice) {
		user_choice = false;
		int temp_x;
		int temp_y;
		cout << "Please enter the x co-ordinate for the vector: ";
		cin >> temp_x;
		cout << "Please enter the y co-ordinate for the vector: ";
		cin >> temp_y;
		Vector_H first(temp_x, temp_y);

		char operation_choice;
		cout << "Please enter the operation to perform(+, -, *, /): ";
		cin >> operation_choice;
		Vector_H second, result;
		double num_choice;
		switch (operation_choice) {
			case '+': 
				second = get_second_vector();
				result = first + second;
				result.print_members();
				break;
			case '-':
				second = get_second_vector();
				result = first - second;
				result.print_members();
				break;
			case '*':
				num_choice = get_user_num_choice();
				result = first * num_choice;

				result.print_members();
				break;
			case '/':
				num_choice = get_user_num_choice();
				result = first / num_choice;
				result.print_members();
				break;
			default:
				cout << "Incorrect input. Please try again." << endl;
				break;
		}

		char user_choice_char;
		cout << "Do you wish to continue?(Y/N): ";
		cin >> user_choice_char;
		if (tolower(user_choice_char) == 'y') {
			user_choice = true;
		}
	}
}

Vector_H get_second_vector() {
	int temp_x_2;
	int temp_y_2;
	cout << "Enter x co-ordinate of second vector: ";
	cin >> temp_x_2;
	cout << "Enter y co-ordinate of second vector: ";
	cin >> temp_y_2;
	return Vector_H(temp_x_2, temp_y_2);
}

double get_user_num_choice() {
	double ret_val;
	cout << "Please enter the scalar operand you wish to work with: ";
	cin >> ret_val;
	return ret_val;
}