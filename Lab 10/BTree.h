#ifndef B_TREE_H
#define B_TREE_H

#define DEFAULT_ORDER 3

#include "Node.h"
#include <math.h>

using namespace std;

template <class T>
class BTree {
	private:
		int order;
		Node<T>* root;
		void insert_helper(T* value, Node<T>* tree, int& operations);
		void split(Node<T>* tree);
		T* find_recursive(T val, Node<T>* tree, int& operations);
		int get_tree_size_recursive(Node<T>* tree);
		int get_tree_height_recursive(Node<T>* tree);
		void print_recursive(Node<T>* tree);
	public:
		BTree();
		BTree(int custom_size);
		void insert_item(T* item_to_insert, int& operations);
		T* find_item(T val, int& operations);
		int get_tree_size();
		int get_tree_height();
		void print();
};

template <class T>
BTree<T>::BTree() {
	order = DEFAULT_ORDER;
	root = new Node<T>(order);
}

template <class T>
BTree<T>::BTree(int custom_size) {
	order = custom_size;
	root = new Node<T>(order);
}

template <class T>
void BTree<T>::insert_item(T* item_to_insert, int& operations) {
	insert_helper(item_to_insert, root, operations);
}

template <class T>
void BTree<T>::insert_helper(T* value, Node<T>* tree, int& operations) {
	if (tree->is_leaf) {
		tree->add_item(value);
		if (tree->is_full()) {
			split(tree);
		}
	}
	else {
		T** curr_array = tree->data_array;
		int i = 0;
		while (i < tree->internal_size && *value > *curr_array[i]) {
			i++;
		}
		// if (i == tree->internal_size) {
		//	return insert_helper(value, tree->data_pointer_array[i]);
		// }
		operations++;
		insert_helper(value, tree->data_pointer_array[i], operations);
	}
}

template <class T>
void BTree<T>::split(Node<T>* tree) {
	int middle_val_index = ceil(double(order) / 2) - 1;
	T* middle_val = tree->data_array[middle_val_index];
	tree->data_array[middle_val_index] = nullptr;
	Node<T>* parent = tree->parent;
	// Create a new node to hold the right side keys and pointers of the right side of the original node
	Node<T>* new_right = new Node<T>(order, parent);
	int new_right_size = 0;
	for (int j = ceil(double(order) / 2); j < order; j++) {
		new_right->add_item(tree->data_array[j]);
		tree->data_array[j] = nullptr;
		new_right_size++;
	}
	new_right->internal_size = new_right_size;
	tree->internal_size = tree->internal_size - new_right_size - 1;
	new_right->is_leaf = tree->is_leaf;
	// If tree has data pointers, move the right part over to right node
	int k = 0;
	if (!tree->is_leaf) {
		for (int j = ceil(double(order) / 2); j <= order; j++) {
			new_right->data_pointer_array[k] = tree->data_pointer_array[j];
			new_right->data_pointer_array[k]->parent = new_right;
			tree->data_pointer_array[j] = nullptr;
			k++;
		}
	}
	// If the node to be split has a parent
	if (parent) {
		// Finding the index of where to insert the middle value
		int i = 0;
		while (parent->data_pointer_array[i] != tree) {
			i++;
		}
		// Move all the keys on the right of the index to make space for the new key
		for (int j = parent->get_size(); j > i; j--) {
			parent->data_array[j] = parent->data_array[j - 1];
		}
		parent->data_array[i] = middle_val;
		parent->internal_size++;
		// Set the new left and right within the parent of tree
		for (int j = order; j > i; j--) {
			parent->data_pointer_array[j] = parent->data_pointer_array[j - 1];
		}
		parent->data_pointer_array[i + 1] = new_right;
		if (parent->is_full()) {
			split(parent);
		}
	}
	// If the tree doesnt have parent => It's the head of the tree
	else {
		Node<T>* new_head = new Node<T>(order);
		new_head->add_item(middle_val);
		new_head->data_pointer_array[0] = tree;
		new_head->data_pointer_array[1] = new_right;
		tree->parent = new_head;
		new_right->parent = new_head;
		new_head->is_leaf = false;
		root = new_head;
	}
}

template <class T>
T* BTree<T>::find_recursive(T val, Node<T>* tree, int& operations) {
	if (tree == nullptr) {
		return nullptr;
	}
	int i = 0;
	while (i < tree->internal_size && *(tree->data_array[i]) < val) {
		i++;
	}
	if (i == tree->internal_size) {
		operations++;
		return find_recursive(val, tree->data_pointer_array[i], operations);
	}
	else {
		if (val == *(tree->data_array[i])) {
			return tree->data_array[i];
		}
		else {
			operations++;
			return find_recursive(val, tree->data_pointer_array[i], operations);
		}
	}
}

template <class T>
T* BTree<T>::find_item(T val, int& operations) {
	return find_recursive(val, root, operations);
}

template <class T>
int BTree<T>::get_tree_size_recursive(Node<T>* tree) {
	if (tree == nullptr) {
		return 0;
	}
	else {
		int sum = 0;
		int i = 0;
		while (i <= tree->internal_size) {
			sum += get_tree_size_recursive(tree->data_pointer_array[i]);
			i++;
		}
		return tree->internal_size + sum;
	}
}

template <class T>
int BTree<T>::get_tree_size() {
	return get_tree_size_recursive(root);
}

template <class T>
int BTree<T>::get_tree_height_recursive(Node<T>* tree) {
	if (tree->is_leaf) {
		return 1;
	}
	int max_val = 0;
	for (int i = 0; i <= tree->internal_size; i++) {
		int curr_size = get_tree_height_recursive(tree->data_pointer_array[i]);
		if (max_val < curr_size) {
			max_val = curr_size;
		}
	}
	return 1 + max_val;
}

template <class T>
int BTree<T>::get_tree_height() {
	return get_tree_height_recursive(root);
}

template <class T>
void BTree<T>::print_recursive(Node<T>* tree) {
	if (tree == nullptr) {
		return;
	}
	else {
		// Root, Intermediate or Leaf
		if (tree == root) {
			cout << "Node Level: Root" << endl;
		}
		else if (tree->is_leaf) {
			cout << "Node Level: Leaf" << endl;
		}
		else {
			cout << "Node Level: Intermediate" << endl;
		}
		cout << "\n\n" << endl;
		// Keys inside the node
		cout << "Keys inside: " << endl;
		for (int i = 0; i < tree->internal_size; i++) {
			cout << "Key " << i << ": " << *(tree->data_array[i]) << " ";
		}
		cout << "\n\n" << endl;
		// Keys inside the parent
		if (tree->parent) {
			cout << "Keys of parent" << endl;
			for (int i = 0; i < tree->parent->internal_size; i++) {
				cout << "Key " << i << ": " << *(tree->parent->data_array[i]) << " ";
			}
		}
		else {
			cout << "The node has no parent" << endl;
		}
		cout << "\n\n" << endl;
		cout << "Keys of all the children" << endl;
		//Keys inside the children
		if (!tree->is_leaf) {
			for (int i = 0; i <= tree->internal_size; i++) {
				cout << "Child " << i << " keys:" << endl;
				for (int j = 0; j < tree->data_pointer_array[i]->internal_size; j++) {
					cout << "Key " << i << ": " << *(tree->data_pointer_array[i]->data_array[j]) << " ";
				}
				cout << endl;
			}
		}
		else {
			cout << "The node is a leaf hence it has no children" << endl;
		}
		cout << "\n\n" << endl;
		for (int i = 0; i <= tree->internal_size; i++) {
			print_recursive(tree->data_pointer_array[i]);
		}
	}
}

template <class T>
void BTree<T>::print() {
	print_recursive(root);
}

#endif
