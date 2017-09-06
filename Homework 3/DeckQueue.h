#include <cstdlib>
#include <string>
#include <algorithm>
#include "CardStruct.h"

using namespace std;

#define MAX_DECK_SIZE 104
#define CLASSIC_DECK_SIZE 52

#ifndef DECK_QUEUE_H
#define DECK_QUEUE_H

class DeckQueue {
	private:
		card pile_array[MAX_DECK_SIZE];
		int Back;
		int Front;
		int Length;
	public:
		DeckQueue();
		void enqueue(card c);
		card dequeue();
		card peek();
		int length();
		bool isEmpty();
		bool isFull();
		void emptyDeck();
};

#endif
