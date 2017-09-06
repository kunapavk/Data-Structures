#ifndef LINKED_LIST_H
#define LINKED_LIST_H

template <class T>
class LinkedList {
	private:
		T* first;
		int length;
		int next_location;
	public:
		void addItem(T* item_to_add);
		T* getItem(T* item_to_get);
		T* seeItem(T* item_to_see, int& operations);
		bool isInList(T* item);
		bool isEmpty();
		int size();
		T* seeNext();
		T* seeAt(int user_location);
		void reset();
		~LinkedList();
		LinkedList();
		void print();
};

template <class T>
void LinkedList<T>::addItem(T* item_to_add) {
	/* if (first) {
		item_to_add->next = first;
		first = item_to_add;
		length++;
	}
	else {
		first = item_to_add;
		length++;
	}*/
	if (first) {
		T* temp = first;
		if (temp->next) {
			while (temp->next) {
				if (temp->next->data > item_to_add->data) {
					item_to_add->next = temp->next;
					temp->next = item_to_add;
					length++;
					return;
				}
				else {
					temp = temp->next;
				}
			}
			if (!temp->next) {
				temp->next = item_to_add;
				length++;
			}
		}
		else {
			if (temp->data > item_to_add->data) {
				item_to_add->next = temp;
				first = item_to_add;
				length++;
			}
			else {
				temp->next = item_to_add;
				length++;
			}
		}
	}
	else {
		first = item_to_add;
		length++;
	}
}

template <class T>
T* LinkedList<T>::getItem(T* item_to_get) {
	if (first->data == item_to_get->data) {
		T* ret_val = first;
		first = ret_val->next;
		ret_val->next = nullptr;
		length--;
		return ret_val;
	}
	T* temp = first;
	while (temp->next && temp->next->data != item_to_get->data) {
		temp = temp->next;
	}
	if (temp->next) {
		T* temp_node = temp->next;
		temp->next = temp_node->next;
		temp_node->next = nullptr;
		length--;
		return temp_node;
	}
	else{
		return nullptr;
	}
}

template <class T>
T* LinkedList<T>::seeItem(T* item_to_see, int& operations ) {
	if (first->data == item_to_see->data) {
		T* ret_val = first;
		// first = ret_val->next;
		ret_val->next = nullptr;
		// length--;
		operations++;
		return ret_val;
	}
	T* temp = first;
	while (temp->next && temp->next->data != item_to_see->data) {
		operations++;
		temp = temp->next;
	}
	if (temp->next) {
		T* temp_node = temp->next;
		// temp->next = temp_node->next;
		temp_node->next = nullptr;
		// length--;
		return temp_node;
	}
	else {
		return nullptr;
	}
}

template <class T>
bool LinkedList<T>::isInList(T* item) {
	T* temp = first;
	while (temp->next && temp->data != item->data) {
		temp = temp->next;
	}
	if (temp->data == item->data || temp->next) {
		return true;
	}
	else {
		return false;
	}
}

template <class T>
bool LinkedList<T>::isEmpty() {
	return (first == nullptr);
}

template <class T>
int LinkedList<T>::size() {
	return length;
}

template <class T>
T* LinkedList<T>::seeNext() {
	int i = 0;
	T* temp = first;
	while (temp->next && i < next_location) {
		i++;
		temp = temp->next;
	}
	if (temp->next || i == next_location) {
		next_location++;
		return temp;
	}
	else {
		return nullptr;
	}
}

template <class T>
T* LinkedList<T>::seeAt(int user_location) {
	int i = 0;
	T* temp = first;
	while (temp->next && i < (user_location)) {
		i++;
		temp = temp->next;
	}
	if (temp->next) {
		next_location = i + 1;
		return temp;
	}
	else {
		return nullptr;
	}
}

template <class T>
void LinkedList<T>::reset() {
	next_location = 0;
}

template <class T>
LinkedList<T>::~LinkedList() {
	T* temp = first;
	while (first->next) {
		first = first->next;
		delete temp;
		temp = first;
	}
	delete first;
	return;
}

template <class T>
LinkedList<T>::LinkedList() {
	length = 0;
	next_location = 0;
	first = nullptr;
}

template <class T>
void LinkedList<T>::print() {
	T* temp = first;
	if (first) {
		temp->data.print();
		while (temp->next) {
			cout << " || " << endl;
			cout << " || " << endl;
			cout << " \\/ " << endl;
			temp = temp->next;
			temp->data.print();
		}
	}
}

#endif
