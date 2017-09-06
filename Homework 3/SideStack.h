#include <cstdlib>
#include <string>
#include "CardStruct.h"

using namespace std;

#define MAX_SIDE_STACK_SIZE 5

#ifndef SIDE_STACK_H
#define SIDE_STACK_H

class SideStack {
	private:
		card own_cards[MAX_SIDE_STACK_SIZE];
		int Top;
	public:
		SideStack();
		void push(card c);
		card pop();
		card peek();
		int deck_length();
		bool isEmpty();
		bool isFull();
		void emptyStack();
		class EmptyStackException {};
		class FullStackException {};
};

#endif