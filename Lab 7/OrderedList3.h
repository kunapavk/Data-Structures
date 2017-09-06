#ifndef ORDERED_LIST_3_H
#define ORDERED_LIST_3_H
#include "OrderedList.h"

template <class T>
class OrderedList3 : public OrderedList<T> {
	public:
		T* removeItem(T data, int& operations);
		void addItem(T* data, int& operations);
};

template <class T>
T* OrderedList3<T>::removeItem(T data, int& operations) {
	if (length == 0) {
		throw new OrderedList<T>::EmptyListException();
	}
	int i = 0;
	bool compare_data = false;
	for (int j = 0; j < length; j++) {
		if (!(class_array[j] == nullptr)) {
			operations++;
			compare_data = (*class_array[j] == data);
			break;
		}
	}
	int empty_encounters = 0;
	while ((i < (length+empty_encounters)) && !(compare_data)){
		if (!(class_array[i] == nullptr)) {
			operations++;
			compare_data = (*class_array[i] == data);
			if (compare_data) {
				break;
			}
			else {
				i++;
			}
		}
		else {
			empty_encounters++;
			i++;
		}
	}
	if (i >= (length + empty_encounters)) {
		throw new OrderedList<T>::ItemNotFoundException();
	}
	T* ret_val = class_array[i];
	class_array[i] = nullptr;
	length--;
	return ret_val;
}

template <class T>
void OrderedList3<T>::addItem(T* data, int& operations){
	int empty_encounters = 0;
	if (length == MAX_SIZE) {
		throw new OrderedList<T>::FullListException();
	}
	int i = 0;
	bool compare_data = false;
	int j;
	for (j = 0; j < (length + empty_encounters); j++) {
		if (class_array[j] == nullptr) {
			empty_encounters++;
		}
		else {
			operations++;
			compare_data = (*class_array[j] < *data);
			break;
		}
	}
	// cout << "compare_data: " << compare_data << endl;
	if (!compare_data) {
		if (empty_encounters > 0) {
			int k;
			for (k = j; k > 0; k--) {
				if (class_array[k] == nullptr) {
					break;
				}
			}
			class_array[k] = data;
			length++;
			return;
		}
		else {
			if (i == 0) {
				operations++;
				int null_spaces = 0;
				for (int q = 0; q < (length + null_spaces); q++) {
					if (class_array[q] == nullptr) {
						null_spaces++;
					}
				}
				if (null_spaces > 0) {
					int null_space_index = 0;
					for (null_space_index; null_space_index < (length + null_spaces); null_space_index++) {
						if (class_array[null_space_index] == nullptr) {
							break;
						}
					}
					for (int q = null_space_index; q > 0; q--) {
						class_array[q] = class_array[q - 1];
					}
					class_array[0] = data;
					length++;
					return;
				}
				else {
					for (int q = length; q > 0; q--) {
						class_array[q] = class_array[q - 1];
					}
					class_array[0] = data;
					length++;
					return;
				}
				class_array[i + 1] = class_array[i];
				class_array[i] = data;
				length++;
				return;
			}
		}
	}
	// cout << " Value of compare data: " << compare_data << endl;
	empty_encounters = 0;
	while (compare_data && i < (length + empty_encounters)) {
		if (class_array[i] == nullptr) {
			empty_encounters++;
			i++;
		}
		else {
			operations++;
			compare_data = (*class_array[i] < *data);
			if (compare_data) {
				i++;
			}
			else {
				break;
			}
		}
	}
	// cout << "Value of compare data: " << compare_data << endl;
	// cout << "Value of i: " << i << endl;
	if (compare_data) {
		if (i == length) {
			class_array[i] = data;
			length++;
			return;
		}
		if (empty_encounters > 0) {
			int k;
			for (k = i; k > 0; k--) {
				if (class_array[k] == nullptr) {
					break;
				}
			}
			for (int m = k; m < i; m++) {
				operations++;
				class_array[m] = class_array[m + 1];
			}
			class_array[i - 1] = data;
			length++;
			return;
		}
		else {
			for (int k = length; k > i; k--) {
				operations++;
				class_array[k] = class_array[k - 1];
			}
			class_array[i] = data;
			length++;
			return;
		}
	}
	else {
		if (empty_encounters > 0) {
			int k = i;
			for (k; k >= 0; k--) {
				if (class_array[k] == nullptr) {
					break;
				}
			}
			int l;
			for (l = (i - 1); l > k; l--) {
				operations++;
				class_array[l - 1] = class_array[l];
			}
			class_array[i-1] = data;
			length++;
			return;
		}
		else {
			if (i == length) {
				class_array[length] = data;
				length++;
				return;
			}
			else {
				for (int m = length; m > i; m--) {
					operations++;
					class_array[m] = class_array[m - 1];
				}
				class_array[i] = data;
				length++;
				return;
			}
		}
	}
}

#endif
