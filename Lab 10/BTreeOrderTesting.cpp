#include "BTree.h"
#include "Node.h"
#include "studentClass.h"
#include <iostream>
#include <string>
#include <math.h>
#include <time.h>

#define ORDER_CHOICE 5
#define NUMBER_OF_STUDENTS 50

using namespace std;

int main() {
	srand(time(NULL));
	BTree<student> tree(ORDER_CHOICE);
	string m_numbers[NUMBER_OF_STUDENTS];
	string first_name, last_name, m_number;
	int years;
	int curr_operations = 0;
	int operations[NUMBER_OF_STUDENTS];
	// Inserting the students into the array
	for (int i = 0; i < NUMBER_OF_STUDENTS; i++) {
		curr_operations = 0;
		first_name = "student_first_name" + to_string(i + 1);
		last_name = "student_last_name" + to_string(i + 1);
		m_number = "M" + to_string((rand() % 900) + 100);
		years = 1990 + (rand() % 20);
		tree.insert_item(new student(first_name, last_name, m_number, years), curr_operations);
		operations[i] = curr_operations;
		m_numbers[i] = m_number;
	}
	cout << "added all students to the tree" << endl;
	// Finding the students in the array
	for (int i = NUMBER_OF_STUDENTS - 1; i >= 0; i--) {
		curr_operations = 0;
		m_number = m_numbers[i];
		tree.find_item(student(m_number), curr_operations);
		operations[i] += curr_operations;
	}
	cout << "Found all the students in the tree" << endl;
	// Calculating mean operations by adding all the entries in the operations array
	int sum = 0;
	for (int i = 0; i < NUMBER_OF_STUDENTS; i++) {
		sum += operations[i];
	}
	cout << "The average number of operations to add and find an item within the tree are: " << sum  << endl;
	return 0;
}