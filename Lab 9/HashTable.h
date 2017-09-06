#ifndef HASH_TABLE_H
#define HASH_TABLE_H

#include <string>

#define DEFAULT_SIZE 100

using namespace std;

template <class T>
class HashTable {
	public:
		int size;
		int curr_size;
		T** data_array;
		int hash(string to_be_hashed);
		HashTable();
		HashTable(int custom_size);
		void add_item(T* to_be_added);
		T* remove_item(T* to_be_removed);
		T* get_item(T* item_to_get, int& operations);
		int get_length();
		~HashTable();
		void print();
};

template <class T>
int HashTable<T>::hash(string to_be_hashed) {
	int sum = 0;
	for (int i = 0; i < to_be_hashed.length(); i++) {
		sum += int(to_be_hashed[i]);
	}
	return (sum % size);
}

template <class T>
HashTable<T>::HashTable() {
	size = DEFAULT_SIZE;
	curr_size = 0;
	data_array = new T*[size];
	for (int i = 0; i < size; i++) {
		data_array[i] = nullptr;
	}
}

template <class T>
HashTable<T>::HashTable(int custom_size) {
	size = custom_size;
	curr_size = 0;
	data_array = new T*[size];
	for (int i = 0; i < size; i++) {
		data_array[i] = nullptr;
	}
}

template <class T>
void HashTable<T>::add_item(T* to_be_added) {
	int key = hash(*to_be_added);
	// cout << bool(data_array[key]) << endl;
	if (data_array[key] && !(data_array[key]->is_deleted)) {
		while (data_array[key] && !(data_array[key]->is_deleted)) {
			key = (key + 1) % size;
		}
		data_array[key] = to_be_added;
	}
	else {
		data_array[key] = to_be_added;
		curr_size++;
	}
}

template <class T>
T* HashTable<T>::remove_item(T* to_be_removed) {
	int key = hash(*to_be_removed);
	if (data_array[key] && !(data_array[key]->is_deleted)) {
		if (*(data_array[key]) == *to_be_removed && !(data_array[key]->is_deleted)) {
			T* ret_val = data_array[key];
			data_array[key]->is_deleted = true;
			curr_size--;
			return ret_val;
		}
		else {
			int i;
			for (i = 1; i < size; i++) {
				if (data_array[(key + i) % size]  && !(data_array[(key + 1) % size]->is_deleted)) {
					if (*(data_array[(key + i) % size]) == *to_be_removed && !(data_array[(key + i) % size]->is_deleted)) {
						T* ret_val = data_array[(key + i) % size];
						data_array[(key + i) % size]->is_deleted = true;
						curr_size--;
						return ret_val;
					}
				}
			}
			return nullptr;
		}
	}
	else {
		return nullptr;
	}
}

template <class T>
T* HashTable<T>::get_item(T* item_to_get, int& operations ) {
	int key = hash(*item_to_get);
	if (data_array[key] && !(data_array[key]->is_deleted)) {
		if (*(data_array[key]) == *item_to_get && !(data_array[key]->is_deleted)) {
			return data_array[key];
		}
		else {
			int i;
			for (i = 1; i < size; i++) {
				if (data_array[(key + i) % size] && !(data_array[(key + i) % size]->is_deleted)) {
					if (*(data_array[(key + i) % size]) == *item_to_get && !(data_array[(key + i) % size]->is_deleted)) {
						operations += i;
						return data_array[(key+i)% size];
					}
				}
			}
			return nullptr;
		}
	}
	else {
		return nullptr;
	}
}

template <class T>
int HashTable<T>::get_length() {
	return curr_size;
}

template <class T>
HashTable<T>::~HashTable() {
	for (int i = 0; i < size; i++) {
		if (data_array[i]) {
			delete data_array[i];
		}
	}
	return;
}

template <class T>
void HashTable<T>::print() {
	for (int i = 0; i < size; i++) {
		if (data_array[i]) {
			cout << "The student at this position " << i << " has Mnumber: " << string(*data_array[i]) << endl;
			cout << "The student at this position " << i << " is " << data_array[i]->is_deleted << endl;
		}
		else {
			cout << "The pointer at position " << i << " is a nullptr" << endl;
		}
	}
}

#endif