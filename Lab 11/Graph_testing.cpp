#include "Graph.h"
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int get_user_choice();

int main() {
	Graph<int> a;
	// Manual adding of all nodes and edges from figure in assignment.
	a.add_node(0);
	a.add_node(1);
	a.add_node(2);
	a.add_node(3);
	a.add_node(4);
	a.add_node(5);
	a.add_node(6);
	a.add_node(7);
	a.add_node(8);
	a.add_node(9);
	a.add_edge(0, 2);
	a.add_edge(0, 3);
	a.add_edge(0, 5);
	a.add_edge(1, 4);
	a.add_edge(1, 3);
	a.add_edge(1, 6);
	a.add_edge(2, 7);
	a.add_edge(2, 4);
	a.add_edge(2, 0);
	a.add_edge(3, 8);
	a.add_edge(3, 0);
	a.add_edge(3, 1);
	a.add_edge(4, 2);
	a.add_edge(4, 1);
	a.add_edge(4, 9);
	a.add_edge(5, 9);
	a.add_edge(5, 6);
	a.add_edge(5, 0);
	a.add_edge(6, 1);
	a.add_edge(6, 7);
	a.add_edge(6, 5);
	a.add_edge(7, 2);
	a.add_edge(7, 8);
	a.add_edge(7, 6);
	a.add_edge(8, 9);
	a.add_edge(8, 3);
	a.add_edge(8, 7);
	a.add_edge(9, 8);
	a.add_edge(9, 4);
	a.add_edge(9, 5);
	int user_choice = get_user_choice();
	while (user_choice < 1 || user_choice > 10) {
		cout << "Incorrect input. Please try again" << endl;
		user_choice = get_user_choice();
	}
	while (user_choice != 10) {
		switch (user_choice) {
		case 1:
		{
			int input_val;
			cout << "Please enter the number you wish to add to the graph: ";
			cin >> input_val;
			a.add_node(input_val);
			break;
		}
		case 2:
		{
			int input_val_start, input_val_end;
			cout << "Please enter the number you wish to start the edge from: ";
			cin >> input_val_start;
			cout << "Please enter the number you wish to end the edge at: ";
			cin >> input_val_end;
			a.add_edge(input_val_start, input_val_end);
			break;
		}
		case 3: {
			int input_val_start, input_val_end;
			cout << "Please enter the number you wish to start the edge from: ";
			cin >> input_val_start;
			cout << "Please enter the number you wish to end the edge at: ";
			cin >> input_val_end;
			a.remove_edge(input_val_start, input_val_end);
			break;
		}
		case 4: {
			int input_val_start, input_val_end;
			cout << "Please input the start of the edge you wish to find: ";
			cin >> input_val_start;
			cout << "Please input the end of the edge you wish to find: ";
			cin >> input_val_end;
			if (a.has_edge(input_val_start, input_val_end)) {
				cout << "The required edge exists in the graph" << endl;
			}
			else {
				cout << "The required edge does not exist in the graph" << endl;
			}
			break;
		}
		case 5:
		{
			int input_val;
			cout << "Please enter the value of the node you wish to find out edges for: ";
			cin >> input_val;
			vector<int> ret_val = a.out_edges(input_val);
			for (int i = 0; i < ret_val.size(); i++) {
				cout << "The node has edge " << ret_val[i] << endl;
			}
			break;
		}
		case 6:
		{
			int input_val;
			cout << "Please enter the value of the node you wish to find in edges for: ";
			cin >> input_val;
			vector<int> ret_val = a.in_edges(input_val);
			for (int i = 0; i < ret_val.size(); i++) {
				cout << "The node which connects to the specified node is " << ret_val[i] << endl;
			}
			break;
		}
		case 7: {
			a.display_graph();
			break;
		}
		case 8: {
			int input_val;
			cout << "Please enter the node where you wish to start the search: ";
			cin >> input_val;
			cout << "The following is the order of nodes by which depth first search was conducted: " << endl;
			a.depth_first_search(input_val);
			break;
		}
		case 9: {
			int input_val;
			cout << "Please enter the node where you wish to start the search: ";
			cin >> input_val;
			cout << "The following is the order of nodes by which breadth first search was conducted: " << endl;
			a.breadth_first_search(input_val);
			break;
		}
		default: {
			cout << "Wrong input. Please try again" << endl;
		}
		}
		cout << "\n\n\n\n\n\n" << endl;
		user_choice = get_user_choice();
		while (user_choice < 1 || user_choice > 10) {
			cout << "Incorrect input. Please try again" << endl;
			user_choice = get_user_choice();
		}
	}
	cout << "Ending program..." << endl;
}

int get_user_choice() {
	int inner_user_input;
	string inner_user_input_string;
	cout << "Please select what you wish to do from the following: " << endl;
	cout << "1. Add a node to the graph" << endl;
	cout << "2. Add an edge to the graph" << endl;
	cout << "3. Remove an edge from the graph" << endl;
	cout << "4. Find an edge in the graph" << endl;
	cout << "5. Find the out edges of a node in the graph" << endl;
	cout << "6. Find the in edges of a node in the graph" << endl;
	cout << "7. Display the graph as an adjacency list" << endl;
	cout << "8. Depth first search from specified node" << endl;
	cout << "9. Breadth first search from specified node" << endl;
	cout << "10. Exit the program: ";
	cin >> inner_user_input_string;
	inner_user_input = stoi(inner_user_input_string);
	return inner_user_input;
}