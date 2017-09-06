#include "DeckQueue.h"

DeckQueue::DeckQueue() {
	Front = 0;
	Back = 52;
	Length = 52;
	// Setting cards from values 0 to 12. Ensures theres one of each card
	for (int i = 0; i < CLASSIC_DECK_SIZE; i++) {
		pile_array[i] = {
			(i / 4),
			(i % 4)
		};
	}
	// Shuffling positions of the cards 
	for (int i = 0; i < CLASSIC_DECK_SIZE; i++) {
		int r = rand() % CLASSIC_DECK_SIZE;
		card temp = pile_array[r];
		pile_array[r] = pile_array[i];
		pile_array[i] = temp;
	}
}

void DeckQueue::enqueue(card c) {
	pile_array[Back] = c;
	Back = ((Back + 1) % MAX_DECK_SIZE);
	Length++;
}

card DeckQueue::dequeue() {
	card ret_val = pile_array[Front];
	Front = ((Front + 1) % MAX_DECK_SIZE);
	Length--;
	return ret_val;
}

card DeckQueue::peek() {
	return pile_array[Front];
}

int DeckQueue::length() {
	return Length;
}

bool DeckQueue::isEmpty() {
	return (Length == 0);
}

bool DeckQueue::isFull() {
	return (Length == MAX_DECK_SIZE);
}

void DeckQueue::emptyDeck() {
	Front = 0;
	Back = 0;
	Length = 0;
}