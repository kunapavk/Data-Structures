#ifndef stackclass_h
#define stackclass_h
#include <iostream>
#include <cstdlib>

using namespace std;

template <class T>
class stackclass{
  private:
	T** stack_array;
	int Top;
	int size;
  public:
	stackclass();
	stackclass(int s);
	void push(T* data);
	T* pop();
	T* top();
	int length();
	void Empty();
	friend void print_to_screen(stackclass<T> all_rods[], int num_disks);
	friend bool check_victory_condition(stackclass<T> all_rods[], int num_disks);
	friend bool check_victory_condition_multiplayer(stackclass<T> all_rods[], int num_disks, int play_rod, int& curr_player);
	class EmptyStackException{};
	class FullStackException{};
};

template <class T>
stackclass<T>::stackclass() {
	Top = 0;
}

template <class T>
stackclass<T>::stackclass(int s) {
	stack_array = new T*[s];
	for (int i = 0; i < s; i++) {
		stack_array[i] = NULL;
	}
	Top = 0;
	size = s;
}

template <class T>
void stackclass<T>::push(T* data) {
	if (Top < size) {
		stack_array[Top] = data;
		Top++;
	}
	else {
		throw FullStackException();
	}
}

template <class T>
T* stackclass<T>::pop() {
	if (Top > 0) {
		Top--;
		T* ret_val = stack_array[Top];
		stack_array[Top] = NULL;
		return ret_val;
	}
	else {
		throw EmptyStackException();
	}
}

template <class T>
T* stackclass<T>::top() {
	if (Top > 0) {
		return stack_array[Top - 1];
	}
	else {
		return NULL;
	}
}

template <class T>
int stackclass<T>::length() {
	return Top;
}

template <class T>
void stackclass<T>::Empty() {
	for (int i = 0; i < Top; i++) {
		delete stack_array[i];
	}
	Top = 0;
}

#endif
