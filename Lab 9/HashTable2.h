#ifndef HASH_TABLE_2_H
#define HASH_TABLE_2_H
#include "HashTable.h"
#include "LinkedList.h"

#define DEFAULT_SIZE 100

template <class T>
class HashTable2 : public HashTable<T> {
	public:
		LinkedList<T>** data_array;
		HashTable2();
		HashTable2(int custom_size);
		void add_item(T* to_be_added);
		T* remove_item(T* to_be_removed);
		T* get_item(T* item_to_get, int& operations);
		~HashTable2();
		void print();
};

template <class T>
HashTable2<T>::HashTable2() {
	size = DEFAULT_SIZE;
	data_array = new LinkedList<T>*[size];
	for (int i = 0; i < size; i++) {
		data_array[i] = nullptr;
	}
}

template <class T>
HashTable2<T>::HashTable2(int custom_size) {
	size = custom_size;
	data_array = new LinkedList<T>*[size];
	for (int i = 0; i < size; i++) {
		data_array[i] = nullptr;
	}
}

template <class T>
void HashTable2<T>::add_item(T* to_be_added) {
	int key = hash(*to_be_added);
	//data_array[key]->addItem(to_be_added);
	//curr_size++;
	if (data_array[key]) {
		data_array[key]->addItem(to_be_added);
		curr_size++;
	}
	else {
		data_array[key] = new LinkedList<T>();
		data_array[key]->addItem(to_be_added);
		curr_size++;
	}
}

template <class T>
T* HashTable2<T>::remove_item(T* to_be_removed) {
	int key = hash(*to_be_removed);
	if (!data_array[key]) {
		return nullptr;
	}
	else {
		if (data_array[key]->isEmpty() && !(data_array[key]->isInList(to_be_removed))) {
			return nullptr;
		}
		if (data_array[key]->isInList(to_be_removed)) {
			curr_size--;
			return data_array[key]->getItem(to_be_removed);
		}
		/*else {
			return nullptr;
		}*/
	}
}

template <class T>
T* HashTable2<T>::get_item(T* item_to_get, int& operations) {
	int key = hash(*item_to_get);
	if (!data_array[key]) {
		return nullptr;
	}
	else {
		if (data_array[key]->isEmpty() && !(data_array[key]->isInList(item_to_get))) {
			return nullptr;
		}
		if (data_array[key]->isInList(item_to_get)) {
			return data_array[key]->seeItem(item_to_get, operations);
		}
		/*else {
		return nullptr;
		}*/
	}
}

template <class T>
HashTable2<T>::~HashTable2() {
	for (int i = 0; i < size; i++) {
		if (data_array[i]) {
			delete data_array[i];
		}
	}
	return;
}

template <class T>
void HashTable2<T>::print() {
	for (int i = 0; i < size; i++) {
		if (data_array[i]) {
			if (!(data_array[i]->isEmpty())) {
				cout << "The list at position " << i << " is as follows: " << endl;
				data_array[i]->print();
			}
			else {
				cout << "The position " << i << " is empty" << endl;
			}
		}
		else {
			cout << "The position " << i << " has no list" << endl;
		}
	}
}


#endif
