#ifndef NODE_H
#define NODE_H

#include "Edge.h"

template <class T>
class Node {
private:
	T data;
	Edge<T>* edges;
	Node<T>* next;
public:
	Node(T val);
	Edge<T>* get_edges();
	Node<T>* get_next();
	T get_data();
	void set_edge(Edge<T>* val);
	void set_next(Node<T>* val);
};

template <class T>
Node<T>::Node(T val) {
	data = val;
	edges = nullptr;
	next = nullptr;
}

template <class T>
Edge<T>* Node<T>::get_edges() {
	return edges;
}

template <class T>
Node<T>* Node<T>::get_next() {
	return next;
}

template <class T>
T Node<T>::get_data() {
	return data;
}

template <class T>
void Node<T>::set_edge(Edge<T>* val) {
	edges = val;
}

template <class T>
void Node<T>::set_next(Node<T>* val) {
	next = val;
}

#endif