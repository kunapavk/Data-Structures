#ifndef BST_H
#define BST_H

#include "Node.h"
#include <math.h>

template <class T>
class BST {
private:
	Node<T>* head;
	int size;
	Node<T>* insert_recursive(T val, Node<T>* tree);
	Node<T>* find_recursive(T val, Node<T>* tree);
	void add_recursive_left(Node<T>* tree, Node<T>** ret_val, int& index);
	void add_recursive_right(Node<T>* tree, Node<T>** ret_val, int& index);
	void empty_recursive(Node<T>* tree);
	Node<T>* find_parent_recursive(T val, Node<T>* tree);
	void rotate_left(Node<T>* parent, Node<T>* pivot);
	void rotate_right(Node<T>* parent, Node<T>* pivot);
	void rotate_left_head();
	void rotate_right_head();
	int node_height(Node<T>* parent, Node<T>* pivot);
	void balance_tree();
	void balance_helper(Node<T>* parent, Node<T>* pivot);
public:
	BST();
	~BST();
	BST(Node<T>* val);
	void insert(T val);
	Node<T>* find(T val);
	int BST_size();
	Node<T>** getAllAscending();
	Node<T>** getAllDescending();
	void empty();
	Node<T>* remove(T val);
	class ItemExistsException{};
};

template <class T>
BST<T>::BST() {
	head = nullptr;
	size = 0;
}

template <class T>
BST<T>::~BST() {
	this->empty();
	return;
}

template <class T>
BST<T>::BST(Node<T>* val) {
	head = val;
	size = 0;
}

template <class T>
Node<T>* BST<T>::insert_recursive(T val, Node<T>* tree) {
	// Saving data at current value to prevent extra lookups
	T curr_data = tree->get_data();

	// If current value is required value, throw exception
	if (val == curr_data) {
		throw new ItemExistsException();
	}
	else {
		// When value goes to the right of the current tree
		if (val > curr_data) {
			// If no right branch exists, implies that the value is the new branch of the tree
			if (tree->get_right() == nullptr) {
				Node<T>* insert_val = new Node<T>(new T(val));
				tree->set_right(insert_val);
				return insert_val;
			}
			// If a right branch does exist, call insert on that tree again
			else {
				return insert_recursive(val, tree->get_right());
			}

		}
		// When value goes to the left of the tree
		else {
			// If no left branch exists, implies the value is the new branch of the tree
			if (tree->get_left() == nullptr) {
				Node<T>* insert_val = new Node<T>(new T(val));
				tree->set_left(insert_val);
				return insert_val;
			}
			// If a left branch does exist, call insert on that tree again
			else {
				return insert_recursive(val, tree->get_left());
			}

		}
	}
}

template <class T>
void BST<T>::insert(T val) {
	// If head does not exist, val is the new head
	if (head == nullptr) {
		head = new Node<T>(new T(val));
		size++;
		return;
	}
	//If head itself is the val to be inserted
	else if (head->get_data() == val){
		throw new ItemExistsException();
	}
	// else, calls insert_recursive which looks for place to add in the tree recursively
	else {
		Node<T>* inserted = insert_recursive(val, head);
		// increments size when an element is added
		size++;
		// balance the tree after insertion if unbalanced
		balance_tree();
	}
}

template <class T>
Node<T>* BST<T>::find_recursive(T val, Node<T>* tree) {
	// If the current tree is a nullptr => the element was never found hence return nullptr
	if (tree == nullptr) {
		return nullptr;
	}
	// If the tree's value is the required value, return the tree itself
	else if (tree->get_data() == val) {
		return tree;
	}
	// If the value in the tree is lesser than required => must look in the right part of the tree
	else if (val > tree->get_data()) {
		return find_recursive(val, tree->get_right());
	}
	// If the value in the tree is greater than required => must look in the left part of the tree
	else if (val < tree->get_data()) {
		return find_recursive(val, tree->get_left());
	}
}

template <class T>
Node<T>* BST<T>::find(T val) {
	// call find_recursive on the head of the tree
	return find_recursive(val, head);
}

template <class T>
int BST<T>::BST_size() {
	// A function which simply returns size
	return size;
}

template <class T>
void BST<T>::add_recursive_left(Node<T>* tree, Node<T>** ret_val, int& index) {
	// add_recurisve_left is a helper function for getAllAscending
	if (tree->get_left()) {
		// If the tree has a left branch, call add_recursive_left on it
		add_recursive_left(tree->get_left(), ret_val, index);
	}
	// Then add the current value into the returned array and increment size
	ret_val[index] = tree;
	index++;
	if (tree->get_right()) {
		// If the tree has a right branch, call add_recurisve_left on it
		add_recursive_left(tree->get_right(), ret_val, index);
	}
	return;
}

template <class T>
Node<T>** BST<T>::getAllAscending() {
	// Initialize the pointer array which is to be returned and set initial index to 0
	Node<T>** ret_val = new Node<T>*[size];
	int initial_index = 0;
	// call the helper function and then return the array
	add_recursive_left(head, ret_val, initial_index);
	return ret_val;
}

template <class T>
void BST<T>::add_recursive_right(Node<T>* tree, Node<T>** ret_val, int& index) {
	// If a right branch exists, call the function on it
	if (tree->get_right()) {
		add_recursive_right(tree->get_right(), ret_val, index);
	}
	// Add the current value and increment index
	ret_val[index] = tree;
	index++;
	// If a left branch exists, call the function on it
	if (tree->get_left()) {
		add_recursive_right(tree->get_left(), ret_val, index);
	}
}

template <class T>
Node<T>** BST<T>::getAllDescending() {
	// Initialize returned array and index, call the helper function using them
	Node<T>** ret_val = new Node<T>*[size];
	int initial_index = 0;
	add_recursive_right(head, ret_val, initial_index);
	return ret_val;
}

template <class T>
void BST<T>::empty_recursive(Node<T>* tree) {
	// If the tree is a nullptr, dont do anything just return
	if (tree == nullptr) {
		return;
	}
	else {
		// If the tree has a left branch call this function on it
		if (tree->get_left()) {
			empty_recursive(tree->get_left());
		}
		// If the tree has a right branch, call this function on it
		if (tree->get_right()) {
			empty_recursive(tree->get_right());
		}
		// When both left and right branches get emptied, delete the current value and return
		delete tree;
		return;
	}
}

template <class T>
void BST<T>::empty() {
	// call empty_recurisve on the head of the tree
	empty_recursive(head);
}

template <class T>
Node<T>* BST<T>::find_parent_recursive(T val, Node<T>* tree) {
	// helper function for the remove function
	if (!(tree->get_left()) && !(tree->get_right())) {
		// Should never happen, but if tree has no right and no left, then it cannot be a parent of a node
		return nullptr;
	}
	else {
		if (val > tree->get_data()) {
			// If the current value is lesser than the val required, look in the right branch
			if (val == tree->get_right()->get_data()) {
				// If right branch is the required value, return current tree
				return tree;
			}
			else {
				// If right branch is not the required value, call this function on the right branch
				return find_parent_recursive(val, tree->get_right());
			}
		}
		else {
			// If the current value is greater than the val required, look in left branch
			if (val == tree->get_left()->get_data()) {
				// If left branch is the required value, return current tree
				return tree;
			}
			else {
				// If its not the required value, call this function on the left branch
				return find_parent_recursive(val, tree->get_left());
			}
		}
	}
}

template <class T>
Node<T>* BST<T>::remove(T val) {
	Node<T>* parent = nullptr;
	// Case when head is the value which needs to be removed
	if (head->get_data() == val) {
		Node<T>* temp = head;
		// If head has a left and right branch, right branch's head becomes new head, and left branch goes to bottom left of right branch
		if (temp->get_right() && temp->get_left()) {
			Node<T>* temp_replace = temp->get_right();
			Node<T>* temp_replace_bot_left = temp_replace;
			while (temp_replace_bot_left->get_left()) {
				temp_replace_bot_left = temp_replace_bot_left->get_left();
			}
			temp_replace_bot_left->set_left(temp->get_left());
			temp->set_left(nullptr);
			temp->set_right(nullptr);
			head = temp_replace;
			size--;
			balance_tree();
			return temp;
		}
		// if head has only a right branch, right branch's head becomes the new head
		if (temp->get_right() && !(temp->get_left())) {
			Node<T>* temp_replace = temp->get_right();
			temp->set_left(nullptr);
			temp->set_right(nullptr);
			head = temp_replace;
			size--;
			balance_tree();
			return temp;
		}
		// If head has only a left branch, left branch's head becomes the new head
		if (temp->get_left() && !(temp->get_right())) {
			Node<T>* temp_replace = temp->get_left();
			temp->set_left(nullptr);
			temp->set_right(nullptr);
			head = temp_replace;
			size--;
			balance_tree();
			return temp;
		}
		head = nullptr;
		size--;
		return temp;
	}

	// Find the parent of the to be removed value
	parent = find_parent_recursive(val, head);

	// Check which side the value is on of the parent
	bool is_on_left = (parent->get_left()->get_data() == val);

	Node<T>* temp = nullptr;
	if (is_on_left) {
		temp = parent->get_left();
	}
	else {
		temp = parent->get_right();
	}

	// Same as before, if both right and left trees exist, right tree's head becomes replacement 
	if (temp->get_right() && temp->get_left()) {
		Node<T>* temp_replace = temp->get_right();
		Node<T>* temp_replace_bot_left = temp_replace;
		while (temp_replace_bot_left->get_left()) {
			temp_replace_bot_left = temp_replace_bot_left->get_left();
		}
		temp_replace_bot_left->set_left(temp->get_left());
		size--;
	}
	// If only a right branch exists, right branch's head becomes replacement
	if (temp->get_right() && !(temp->get_left())) {
		Node<T>* temp_replace = temp->get_right();
		size--;
	}
	// If only a left branch exists, left branch's head becomes replacement
	if (temp->get_left() && !(temp->get_right())) {
		Node<T>* temp_replace = temp->get_left();
		size--;
	}
	// If both branches dont exists, replacement becomes a nullptr
	if (!(temp->get_right()) && !(temp->get_left())) {
		Node<T>* temp_replace = nullptr;
		size--;
	}

	// Setting the temp values to null to avoid user having access to tree
	temp->set_left(nullptr);
	temp->set_right(nullptr);
	// Setting the parent's child based on the original position
	if (is_on_left) {
		parent->set_left(temp_replace);
	}
	else {
		parent->set_right(temp_replace);
	}
	balance_tree();
	return temp;
}

template <class T>
void BST<T>::rotate_left(Node<T>* parent, Node<T>* pivot) {
	// Assigning is on left to decide which child of parent gets replaced
	bool is_on_left = (parent->get_left() == pivot);
	// Replace pivot is the node which replaces the pivot
	Node<T>* replace_pivot = pivot->get_right();
	// If replace pivot has a right branch
	if (replace_pivot->get_right()) {
		// Original pivot's right branch becomes the replacing node's left branch
		pivot->set_right(replace_pivot->get_left());
		// The original pivot will become the replacing node's left branch
		replace_pivot->set_left(pivot);
	}
	// If replace pivot does not have a right branch, very rare again, 3 insertions in a specific order
	else {
		// Finding the parent of the smallest node on the right side of original pivot
		Node<T>* replace_pivot_parent = replace_pivot;
		while (replace_pivot_parent->get_left()->get_left()) {
			replace_pivot_parent = replace_pivot_parent->get_left();
		}
		// Saving the replace_pivot's right branch for assigning to original_pivot
		Node<T>* replace_pivot_right = replace_pivot_parent->get_left()->get_right();
		replace_pivot = replace_pivot_parent->get_left();
		// Replace pivot becomes the head of the subtree, with right as original pivots right and left as original pivot
		replace_pivot->set_right(pivot->get_right());
		replace_pivot->set_left(pivot);
		// Replace pivots right branch becomes original pivots right branch
		pivot->set_right(replace_pivot_right);
		// The parent of the replace now has no child
		replace_pivot_parent->set_left(nullptr);
	}
	// Set the correct side of the parent to the replace pivot
	if (is_on_left) {
		parent->set_left(replace_pivot);
	}
	else {
		parent->set_right(replace_pivot);
	}
}

template <class T>
void BST<T>::rotate_right(Node<T>* parent, Node<T>* pivot) {
	// Assigning is_on_left to see which side of parent gets replaced
	bool is_on_left = (parent->get_left() == pivot);
	// The replace pivot is the node on the left of original pivot
	Node<T>* replace_pivot = pivot->get_left();
	// If replace pivot has a left branch
	if (replace_pivot->get_left()) {
		// The original pivot's left branch becomes the replacing pivot's right branch
		pivot->set_left(replace_pivot->get_right());
		// The replace pivots right branch becomes the original pivot
		replace_pivot->set_right(pivot);
	}
	// If replace pivot doesnt have a left branch, pretty rare, usually 3 insertions in a very specific order
	else {
		// Finding the biggest node on the left side of the original pivot
		Node<T>* replace_pivot_parent = replace_pivot;
		while (replace_pivot_parent->get_right()->get_right()) {
			replace_pivot_parent = replace_pivot_parent->get_right();
		}
		// Save replacing pivots left for reassigning
		replace_pivot = replace_pivot_parent->get_right();
		Node<T>* replace_pivot_left = replace_pivot->get_left();
		// Setting replace pivots left to original pivots left and right to original pivot
		replace_pivot->set_left(pivot->get_left());
		replace_pivot->set_right(pivot);
		// Original pivots left is now replacing pivots left
		pivot->set_left(replace_pivot_left);
		// Replacing pivots parent now has no child
		replace_pivot_parent->set_right(nullptr);
	}
	// Setting parent's child based on is_on_left
	if (is_on_left) {
		parent->set_left(replace_pivot);
	}
	else {
		parent->set_right(replace_pivot);
	}
	return;
}

template <class T>
void BST<T>::rotate_left_head() {
	// Rotate left but for head
	Node<T>* old_head = head;
	Node<T>* new_head = old_head->get_right();
	if (new_head->get_right()) {
		old_head->set_right(new_head->get_left());
		new_head->set_left(old_head);
	}
	else {
		Node<T>* new_head_parent = new_head;
		while (new_head_parent->get_left()->get_left()) {
			new_head_parent = new_head_parent->get_left();
		}
		new_head = new_head_parent->get_left();
		Node<T>* new_head_right = new_head->get_right();
		new_head->set_right(old_head->get_right());
		new_head->set_left(old_head);
		head->set_right(new_head_right);
		new_head_parent->set_left(nullptr);
	}
	head = new_head;
}

template <class T>
void BST<T>::rotate_right_head() {
	// Rotate right but for head
	Node<T>* old_head = head;
	Node<T>* new_head = old_head->get_left();
	if (new_head->get_left()) {
		old_head->set_left(new_head->get_right());
		new_head->set_right(old_head);
	}
	else {
		Node<T>* new_head_parent = new_head;
		while (new_head_parent->get_right()->get_right()) {
			new_head_parent = new_head_parent->get_right();
		}
		new_head = new_head_parent->get_right();
		Node<T>* new_head_left = new_head->get_left();
		new_head->set_left(old_head->get_left());
		new_head->set_right(old_head);
		old_head->set_left(new_head_left);
		new_head_parent->set_right(nullptr);
	}
	head = new_head;
}

template <class T>
int BST<T>::node_height(Node<T>* parent, Node<T>* pivot) {
	if (pivot == nullptr) {
		return 0;
	}
	else {
		// Recurses down entire left side gettting node height
		int left_size = node_height(pivot, pivot->get_left());
		// Recurses down entire right side getting node height
		int right_size = node_height(pivot, pivot->get_right());
		// Return max value + 1 to represent max level of the tree
		if (left_size > right_size) {
			return 1 + left_size;
		}
		else {
			return 1 + right_size;
		}
	}
}

template <class T>
void BST<T>::balance_helper(Node<T>* parent, Node<T>* pivot) {
	if (pivot == nullptr) {
		return;
	}
	// Balance both sides
	balance_helper(pivot, pivot->get_left());
	balance_helper(pivot, pivot->get_right());
	// get node height of both sides
	int left_size = node_height(pivot, pivot->get_left());
	int right_size = node_height(pivot, pivot->get_right());
	// Check if it currently needs balancing
	if (left_size - right_size >= 2) {
		rotate_right(parent, pivot);
		return;
	}
	else if (left_size - right_size <= -2) {
		rotate_left(parent, pivot);
		return;
	}
}

template <class T>
void BST<T>::balance_tree() {
	// Balance right and left size of head
	balance_helper(head, head->get_left());
	balance_helper(head, head->get_right());
	// Get node height of balanced trees
	int left_size = node_height(head, head->get_left());
	int right_size = node_height(head, head->get_right());
	// If still imbalanced call rotate on head
	if ((left_size - right_size) >= 2) {
		rotate_right_head();
	}
	else if ((left_size - right_size) <= -2) {
		rotate_left_head();
	}
}


#endif