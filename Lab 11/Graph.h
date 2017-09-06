#ifndef GRAPH_H
#define GRAPH_H

#include "Node.h"
#include "Edge.h"
#include <vector>
#include <queue>
#include <stack>

using namespace std;

template <class T>
class Graph {
private:
	Node<T>* nodes;
public:
	Graph();
	void add_node(T val);
	void add_edge(T start, T end);
	void remove_edge(T start, T end);
	bool has_edge(T start, T end);
	vector<T> out_edges(T start);
	vector<T> in_edges(T end);
	void display_graph();
	~Graph();
	vector<T> breadth_first_search(T start);
	vector<T> depth_first_search(T start);
};

template <class T>
Graph<T>::Graph() {
	nodes = nullptr;
}

template <class T>
void Graph<T>::add_node(T val) {
	//TODO: Check for already existing node
	Node<T>* temp = nodes;
	if (temp == nullptr) {
		nodes = new Node<T>(val);
		return;
	}
	while (temp->get_next()) {
		if (temp->get_data() == val) {
			return;
		}
		temp = temp->get_next();
	}
	Node<T>* temp_add = new Node<T>(val);
	temp->set_next(temp_add);
}

template <class T>
void Graph<T>::add_edge(T start, T end) {
	//TODO: check if start and end exists, check if the edge already exists
	Node<T>* temp = nodes;
	while (temp->get_next()) {
		if (temp->get_data() == start) {
			break;
		}
		temp = temp->get_next();
	}
	if (temp->get_data() == start) {
		Edge<T>* temp_add = new Edge<T>(end);
		Edge<T>* curr_edges = temp->get_edges();
		if (curr_edges) {
			while (curr_edges->get_next()) {
				curr_edges = curr_edges->get_next();
			}
			curr_edges->set_next(temp_add);
		}
		else {
			temp->set_edge(temp_add);
		}
	}
}

template <class T>
void Graph<T>::remove_edge(T start, T end) {
	Node<T>* temp = nodes;
	while (temp->get_next()) {
		if (temp->get_data() == start) {
			break;
		}
		temp = temp->get_next();
	}
	if (temp->get_data() == start) {
		Edge<T>* curr_edges = temp->get_edges();
		if (curr_edges) {
			while (curr_edges->get_next() && (curr_edges->get_next()->get_node() != end)) {
				curr_edges = curr_edges->get_next();
			}
			if (curr_edges->get_next()->get_node() == end) {
				Edge<T>* temp = curr_edges->get_next();
				curr_edges->set_next(temp->get_next());
				delete temp;
			}
		}
	}
}

template <class T>
bool Graph<T>::has_edge(T start, T end) {
	Node<T>* temp = nodes;
	while (temp->get_next()) {
		if (temp->get_data() == start) {
			break;
		}
		temp = temp->get_next();
	}
	if (temp->get_data() == start) {
		Edge<T>* curr_edges = temp->get_edges();
		if (curr_edges) {
			while (curr_edges->get_next() && (curr_edges->get_next()->get_node() != end)) {
				curr_edges = curr_edges->get_next();
			}
			if (curr_edges->get_next()->get_node() == end) {
				return true;
			}
			else {
				return false;
			}
		}
		else {
			return false;
		}
	}
	else {
		return false;
	}
}

template <class T>
vector<T> Graph<T>::out_edges(T start) {
	Node<T>* temp = nodes;
	vector<T> ret_val;
	while (temp) {
		if (temp->get_data() == start) {
			break;
		}
		temp = temp->get_next();
	}
	if (temp->get_data() == start) {
		Edge<T>* curr_edges = temp->get_edges();
		while (curr_edges) {
			ret_val.push_back(curr_edges->get_node());
			curr_edges = curr_edges->get_next();
		}
	}
	return ret_val;
}

template <class T>
vector<T> Graph<T>::in_edges(T end) {
	Node<T>* temp = nodes;
	vector<T> ret_val;
	while (temp->get_next()) {
		Edge<T>* curr_edge = temp->get_edges();
		if (curr_edge) {
			while (curr_edge) {
				if (curr_edge->get_node() == end) {
					ret_val.push_back(curr_edge->get_node());
					break;
				}
				curr_edge = curr_edge->get_next();
			}
		}
	}
	return ret_val;
}

template <class T>
void Graph<T>::display_graph() {
	Node<T>* temp = nodes;
	while (temp) {
		Edge<T>* curr_edges = temp->get_edges();
		cout << "The current node is " << temp->get_data();
		if (curr_edges) {
			cout << " and it has the following edges: ";
			while (curr_edges) {
				cout << curr_edges->get_node() << ", ";
				curr_edges = curr_edges->get_next();
			}
		}
		else {
			cout << " and it has no edges";
		}
		cout << endl;
		temp = temp->get_next();
	}
}

template <class T>
Graph<T>::~Graph() {
	Node<T>* temp = nodes;
	while (temp) {
		Node<T>* to_delete = temp;
		Edge<T>* curr_edges = temp->get_edges();
		while (curr_edges) {
			Edge<T>* to_delete_edge = curr_edges;
			curr_edges = curr_edges->get_next();
			delete to_delete_edge;
		}
		temp = temp->get_next();
		delete to_delete;
	}
}

template <class T>
vector<T> Graph<T>::breadth_first_search(T start) {
	queue<T> q;
	vector<T> visited;
	vector<T> ret_val;
	T curr_val;
	q.push(start);
	visited.push_back(start);
	while (!q.empty()) {
		curr_val = q.front();
		q.pop();
		ret_val.push_back(curr_val);
		vector<T> neighbours = out_edges(curr_val);
		for (int i = 0; i < neighbours.size(); i++) {
			if (find(visited.begin(), visited.end(), neighbours[i]) == visited.end()) {
				q.push(neighbours[i]);
				visited.push_back(neighbours[i]);
			}
		}
	}
	for (int i = 0; i < ret_val.size(); i++) {
		cout << "The node " << ret_val[i] << " was visited at position " << i << endl;
	}
	return ret_val;
}

template <class T>
vector<T> Graph<T>::depth_first_search(T start) {
	stack<T> s;
	vector<T> visited;
	vector<T> ret_val;
	T curr_val;
	s.push(start);
	visited.push_back(start);
	while (!s.empty()) {
		curr_val = s.top();
		s.pop();
		ret_val.push_back(curr_val);
		vector<T> neighbours = out_edges(curr_val);
		for (int i = 0; i < neighbours.size(); i++) {
			if (find(visited.begin(), visited.end(), neighbours[i]) == visited.end()) {
				s.push(neighbours[i]);
				visited.push_back(neighbours[i]);
			}
		}
	}
	for (int i = 0; i < ret_val.size(); i++) {
		cout << "The node " << ret_val[i] << " was visited at position " << i << endl;
	}
	return ret_val;
}

#endif