#ifndef ORDERED_LIST_H
#define ORDERED_LIST_H

#define MAX_SIZE 10

template <class T>
class OrderedList {
	public:
		T* class_array[MAX_SIZE];
		int length;
		OrderedList();
		void addItem(T* data, int& operations);
		T* removeItem(T data, int& operations);
		bool isEmpty();
		bool isFull();
		void makeEmpty();
		class EmptyListException{};
		class FullListException{};
		class ItemNotFoundException{};
};

template <class T>
OrderedList<T>::OrderedList() {
	for (int i = 0; i < MAX_SIZE; i++) {
		class_array[i] = nullptr;
	}
	length = 0;
}

template <class T>
void OrderedList<T>::addItem(T* data, int& operations) {
	if (length == MAX_SIZE) {
		throw new FullListException();
	}
	int i = 0;
	while (!(class_array[i] == nullptr) && (*class_array[i] < *data) && i < MAX_SIZE) {
		operations++;
		i++;
	}
	if (i >= MAX_SIZE) {
		throw new FullListException();
	}
	for (int j = (length-1); j >= i; j--) {
		operations++;
		class_array[j + 1] = class_array[j];
	}
	class_array[i] = data;
	length++;
}

template <class T>
T* OrderedList<T>::removeItem(T data, int& operations) {
	if (length == 0) {
		throw new EmptyListException();
	}
	int i = 0;
	while (!(class_array[i] == nullptr) && (!(*class_array[i] == data)) && i < MAX_SIZE) {
		operations++;
		i++;
	}
	if (i >= MAX_SIZE) {
		throw new ItemNotFoundException();
	}
	T* ret_val = class_array[i];
	for (int j = i; j < (length - 1); j++) {
		operations++;
		class_array[j] = class_array[j + 1];
	}
	class_array[length-1] = nullptr;
	length--;
	return ret_val;
}

template <class T>
bool OrderedList<T>::isEmpty() {
	return (length == 0);
}

template <class T>
bool OrderedList<T>::isFull() {
	return (length == MAX_SIZE);
}

template <class T>
void OrderedList<T>::makeEmpty() {
	for (int i = 0; i < length; i++) {
		class_array[i] == nullptr;
	}
	length = 0;
}
#endif
