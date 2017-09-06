#include "SideStack.h"

SideStack::SideStack() {
	Top = 0;
}

void SideStack::push(card c) {
	if (Top == MAX_SIDE_STACK_SIZE) {
		throw FullStackException();
	}
	own_cards[Top] = c;
	Top++;
}

card SideStack::pop() {
	if (Top == 0) {
		throw EmptyStackException();
	}
	Top--;
	return own_cards[Top];
}

card SideStack::peek() {
	return own_cards[Top - 1];
}

int SideStack::deck_length() {
	return Top;
}

bool SideStack::isEmpty() {
	return (Top == 0);
}

bool SideStack::isFull() {
	return (Top == MAX_SIDE_STACK_SIZE);
}

void SideStack::emptyStack() {
	Top = 0;
	return;
}