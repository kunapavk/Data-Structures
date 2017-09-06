#include <iostream>
#include <stdlib.h>
#include <time.h>'
#include <string>
#include "OrderedList.h"
#include "OrderedList2.h"
#include "OrderedList3.h"

#define NUMBER_OF_RUNS 100
#define ITEMS_REMOVED 25

using namespace std;

void do_the_stuff(int& a_o, int& b_o, int& c_o);

int main() {
	srand(time(NULL));
	OrderedList<int> a;
	OrderedList2<int> b;
	OrderedList3<int> c;
	cout << "Initialized lists" << endl;
	int* temp = nullptr;
	int item_array[MAX_SIZE];
	int list_1_operations = 0;
	int list_2_operations = 0;
	int list_3_operations = 0;
	for (int i = 0; i < MAX_SIZE; i++) {
		temp = new int(rand() % 100);
		a.addItem(temp, list_1_operations);
		b.addItem(temp, list_2_operations);
		c.addItem(temp, list_3_operations);
		item_array[i] = *temp;
		cout << "Item to add: " << *temp << endl;
	}
	int j = NULL;
	for (int i = 0; i < ITEMS_REMOVED; i++) {
		j = rand() % MAX_SIZE;
		while (item_array[j] == -1) {
			j = rand() % MAX_SIZE;
		}
		int remove_item_val = item_array[j];
		item_array[j] = -1;
		a.removeItem(remove_item_val, list_1_operations);
		b.removeItem(remove_item_val, list_2_operations);
		c.removeItem(remove_item_val, list_3_operations);
		cout << "Item to remove: " << remove_item_val << endl;
	}
	cout << "Number of List 1 operations: " << list_1_operations << endl;
	cout << "Number of List 2 operations: " << list_2_operations << endl;
	cout << "Number of List 3 operations: " << list_3_operations << endl;
	/*
	int list_1_operations = 0;
	int list_2_operations = 0;
	int list_3_operations = 0;
	for (int i = 0; i < NUMBER_OF_RUNS; i++) {
		do_the_stuff(list_1_operations, list_2_operations, list_3_operations);
	}
	cout << "Final number of operations in first list: " << list_1_operations << endl;
	cout << "Final number of operations in second list: " << list_2_operations << endl;
	cout << "Final number of operations in third list: " << list_3_operations << endl;
	*/
}

void do_the_stuff(int& a_o, int& b_o, int& c_o) {
	OrderedList<int> a;
	OrderedList2<int> b;
	OrderedList3<int> c;
	cout << "Initialized lists" << endl;
	int* temp = nullptr;
	int item_array[MAX_SIZE];
	int list_1_operations = 0;
	int list_2_operations = 0;
	int list_3_operations = 0;
	for (int i = 0; i < MAX_SIZE; i++) {
		temp = new int(rand() % 100);
		a.addItem(temp, list_1_operations);
		b.addItem(temp, list_2_operations);
		c.addItem(temp, list_3_operations);
		item_array[i] = *temp;
	}
	int j = NULL;
	for (int i = 0; i < ITEMS_REMOVED; i++) {
		j = rand() % MAX_SIZE;
		while (item_array[j] == NULL) {
			j = rand() % MAX_SIZE;
		}
		int remove_item_val = item_array[j];
		item_array[j] = NULL;
		a.removeItem(remove_item_val, list_1_operations);
		b.removeItem(remove_item_val, list_2_operations);
		c.removeItem(remove_item_val, list_3_operations);
	}
	cout << "List 1 operations" << list_1_operations << endl;
	cout << "List 2 operations" << list_2_operations << endl;
	cout << "List 3 operations" << list_3_operations << endl;
	a_o += list_1_operations;
	b_o += list_2_operations;
	c_o += list_3_operations;
}