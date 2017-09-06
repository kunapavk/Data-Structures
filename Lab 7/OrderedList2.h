#ifndef ORDERED_LIST_2_H
#define ORDERED_LIST_2_H

#include "OrderedList.h"

template <class T>
class OrderedList2 : public OrderedList<T> {
	public:
		void addItem(T* data, int& operations);
};

template <class T>
void OrderedList2<T>::addItem(T* data, int& operations) {
	if (length == MAX_SIZE) {
		throw new OrderedList<T>::FullListException();
	}
	int i;
	for (i = (MAX_SIZE - 1); i >= 0; i--) {
		if (class_array[i] == nullptr) {
			continue;
		}
		else {
			if (*class_array[i] > *data) {
				operations++;
				continue;
			}
			else {
				operations++;
				break;
			}
		}
	}
	int index_to_place = i + 1;
	for (int j = length; j > index_to_place; j--) {
		operations++;
		class_array[j] = class_array[j - 1];
	}
	class_array[index_to_place] = data;
	length++;
}
#endif