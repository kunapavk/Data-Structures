#ifndef NODE_H
#define NODE_H

#define DEFAULT_ORDER 3

using namespace std;

template <class T>
class Node {
	public:
		T** data_array;
		Node<T>** data_pointer_array;
		int internal_size;
		bool is_leaf;
		int internal_order;
		Node<T>* parent;
		Node(Node<T>* p = nullptr);
		Node(int custom_size, Node<T>* p = nullptr);
		void add_item(T* val);
		int get_size();
		bool is_full();
};

template <class T>
Node<T>::Node(Node<T>* p = nullptr) {
	internal_order = DEFAULT_ORDER;
	parent = p;
	data_array = new T*[internal_order];
	data_pointer_array = new Node<T>*[internal_order + 1];
	int i;
	for (i = 0; i < internal_order; i++) {
		data_array[i] = nullptr;
		data_pointer_array[i] = nullptr;
	}
	is_leaf = true;
	data_pointer_array[i] = nullptr;
	internal_size = 0;
}

template <class T>
Node<T>::Node(int custom_size, Node<T>* p = nullptr) {
	internal_order = custom_size;
	parent = p;
	data_array = new T*[custom_size];
	data_pointer_array = new Node<T>*[internal_order + 1];
	int i;
	for (i = 0; i < internal_order; i++) {
		data_array[i] = nullptr;
		data_pointer_array[i] = nullptr;
	}
	is_leaf = true;
	data_pointer_array[i] = nullptr;
	internal_size = 0;
}

template <class T>
void Node<T>::add_item(T* val) {
	if (internal_size == 0) {
		data_array[internal_size] = val;
		internal_size++;
	}
	else {
		int i = 0;
		while (i < internal_size && *data_array[i] < *val) {
			i++;
		}
		/*if (i == 0) {
			for (int j = internal_size; j <= (internal_size); j++) {

			}
		}*/
		if (i == internal_size) {
			data_array[internal_size] = val;
		}
		else {
			for (int j = internal_order; j > i; j--) {
				data_array[j] = data_array[j - 1];
			}
			data_array[i] = val;
		}
		internal_size++;
	}
}

template <class T>
int Node<T>::get_size() {
	return internal_size;
}

template <class T>
bool Node<T>::is_full() {
	return (internal_size == internal_order);
}

#endif