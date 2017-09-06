#ifndef NODE_H
#define NODE_H

template <class T>
class Node {
private:
	T* data;
	Node* left;
	Node* right;
public:
	Node();
	Node(T* val);
	void set_left(Node<T>* val);
	void set_right(Node<T>* val);
	Node<T>* get_left();
	Node<T>* get_right();
	T get_data();
	T* get_data_pointer();
	void set_data(T* val);
};

template <class T>
Node<T>::Node() {
	data = nullptr;
	left = nullptr;
	right = nullptr;
}

template <class T>
Node<T>::Node(T* val) {
	data = val;
	left = nullptr;
	right = nullptr;
}

template <class T>
void Node<T>::set_left(Node<T>* val) {
	left = val;
}

template <class T>
void Node<T>::set_right(Node<T>* val) {
	right = val;
}

template <class T>
Node<T>* Node<T>::get_left() {
	return left;
}

template <class T>
Node<T>* Node<T>::get_right() {
	return right;
}

template <class T>
T Node<T>::get_data() {
	return *data;
}

template <class T>
void Node<T>::set_data(T* val) {
	data = val;
}

template <class T>
T* Node<T>::get_data_pointer() {
	return data;
}

#endif