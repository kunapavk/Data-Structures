#include <iostream>
#include <string>
#include "HashTable.h"
#include "HashTable2.h"
#include "studentClass.h"
#include <random>
#include <ctime>

#define SIZE 250

using namespace std;

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

class Node2 {
public:
	student data;
	Node2* next;
	operator string() const {
		return string(this->data);
	}
	Node2(student s) {
		this->data = s;
		this->next = nullptr;
	}
	bool operator == (const Node& other) {
		return other.data == this->data;
	}
};

int main() {
	srand(time(NULL));
	HashTable<Node> a(SIZE);
	HashTable2<Node2> b(SIZE);
	int num_array[50];
	int j, k;
	bool check;
	for (int i = 0; i < 50; i++) {
		j = rand() % 1000;
		check = true;
		k = 0;
		do {
			if (num_array[k] == j) {
				check = false;
				break;
			}
			else {
				k++;
			}
		} while (!check && k < 50);
		if (check || k == 50) {
			num_array[i] = j;
		}
		else {
			i--;
		}
	}
	string student_first, student_last, student_M;
	int student_birth;
	Node* temp = nullptr;
	Node2* temp2 = nullptr;
	int num_operations_1 = 0;
	int num_operations_2 = 0;
	for (int i = 0; i < 50; i++) {
		student_first = "student " + to_string(i);
		student_last = "name " + to_string(i);
		student_M = "M" + to_string(num_array[i]);
		student_birth = 1970 + (rand() % 47);
		student curr_student(student_first, student_last, student_M, student_birth);
		temp = new Node(curr_student);
		temp2 = new Node2(curr_student);
		a.add_item(temp);
		b.add_item(temp2);
	}
	int rand_index = rand() % 50;
	string M_to_get = "M" + to_string(num_array[rand_index]);
	temp = new Node(student(M_to_get));
	temp2 = new Node2(student(M_to_get));
	a.get_item(temp, num_operations_1);
	b.get_item(temp2, num_operations_2);
	cout << "For the size of " << SIZE << " Hash Table 1 had " << num_operations_1 << " operations and Hash Table 2 had " << num_operations_2 << " operations." << endl;
	return 0;
}