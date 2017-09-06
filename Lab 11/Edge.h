#ifndef EDGE_H
#define EDGE_H

template <class T>
class Edge {
private:
	T node;
	Edge<T>* next;
public:
	Edge(T data);
	Edge<T>* get_next();
	T get_node();
	void set_next(Edge<T>* val);
};

template <class T>
Edge<T>::Edge(T data) {
	node = data;
	next = nullptr;
}

template <class T>
Edge<T>* Edge<T>::get_next() {
	return next;
}

template <class T>
T Edge<T>::get_node() {
	return node;
}

template <class T>
void Edge<T>::set_next(Edge<T>* val) {
	next = val;
}

#endif