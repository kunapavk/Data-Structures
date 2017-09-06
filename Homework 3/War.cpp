#include <iostream>
#include "DeckQueue.h"
#include <ctime>
#include "SideStack.h"

// Using integer values inside the stack to represent card values and suites
// The integers correspond to a value in the constant arrays declared here
const string card_values[13] = { "2","3","4","5","6","7","8","9","10","J","Q","K", "A" };
const string suite_values[4] = { "Diamonds", "Hearts", "Clubs", "Spades" };

using namespace std;

// Function prototypes
bool play(DeckQueue& player_deck, DeckQueue& computer_deck, SideStack& player_stack);
bool play(DeckQueue& player_deck, DeckQueue& computer_deck, SideStack& player_stack, int num_turns);
bool take_turn(DeckQueue& player_deck, DeckQueue& computer_deck, SideStack& player_stack);
bool compare_cards(card p, card c);
bool compare_cards(card p, card c, card s);

int main() {
	// Seeding the random number generator
	srand(time(0));

	// Initial values to represent user choices
	int user_choice_int;
	bool try_again_inital = true;
	bool card_mode_choice = false;
	int number_of_turns_mode = 0;

	cout << "Welcome to War!" << endl;
	cout << "Press 1 if you want to play until you are out of cards." << endl;
	cout << "Press 2 if you want to play with a set number of rounds: ";
	cin >> user_choice_int;
	// Taking users choice about which mode they wish to play
	while (try_again_inital) {
		switch (user_choice_int) {
			case 1:
				card_mode_choice = true;
				try_again_inital = false;
				break;
			case 2:
				card_mode_choice = false;
				try_again_inital = false;
				cout << "Please enter the number of turns you want to play: ";
				cin >> number_of_turns_mode;
				break;
			default:
				cout << "Incorrect input. Please only enter 1 or 2" << endl;
				cout << "Press 1 if you want to play until you are out of cards." << endl;
				cout << "Press 2 if you want to play with a set number of rounds: ";
				cin >> user_choice_int;
				break;
		}
	}

	// Initializing the decks and stacks to be used by the player and the computer
	DeckQueue player_deck;
	DeckQueue computer_deck;
	SideStack player_side_stack;
	bool player_victory = false;
	
	// Selecting play function based on game mode chosen
	if (card_mode_choice) {
		player_victory = play(player_deck, computer_deck, player_side_stack);
	}
	else {
		player_victory = play(player_deck, computer_deck, player_side_stack, number_of_turns_mode);
	}
	if (player_victory) {
		cout << "The game has ended. You are the winner. Congratulations!" << endl;
	}
	else {
		cout << "The game has ended. The computer has won. Better luck next time!" << endl;
	}
}

bool play(DeckQueue& player_deck, DeckQueue& computer_deck, SideStack& player_stack) {
	// Continues play until either one of the decks are empty
	while ((!player_deck.isEmpty()) && (!computer_deck.isEmpty())) {
		take_turn(player_deck, computer_deck, player_stack);
	}
	// Returns true for player victory and false for computer victory
	return computer_deck.isEmpty();
}

bool play(DeckQueue& player_deck, DeckQueue& computer_deck, SideStack& player_stack, int num_turns) {
	// Initializng values to be used in the function
	int player_wins = 0;
	int computer_wins = 0;
	bool player_victory = false;
	// Play continues until either of the decks are empty or turns run out
	while ((num_turns > 0) && (!player_deck.isEmpty()) && (!computer_deck.isEmpty())) {
		// take_turn returns true for player victory and false for computer victory
		player_victory = take_turn(player_deck, computer_deck, player_stack);
		// Incrementing wins based on victory
		player_victory ? player_wins++ : computer_wins++;
		num_turns--;
	}
	return (player_wins > computer_wins);
}

bool take_turn(DeckQueue& player_deck, DeckQueue& computer_deck, SideStack& player_stack) {
	bool try_again = true;
	while (try_again) {
		try {
			// Initializng values to be used inside the function
			try_again = false;
			card player_card;
			card computer_card;
			card player_stack_card;
			int user_side_choice;
			bool player_stack_full = player_stack.isFull();
			bool try_again_input = true;

			// Drawing cards from respective decks and displaying card drawn to user
			player_card = player_deck.dequeue();
			computer_card = computer_deck.dequeue();
			cout << "The card you have drawn is " << card_values[player_card.val] << " of " << suite_values[player_card.suite] << endl;
			cout << "What would you like to do?" << endl;
			// Taking user's input based on the size of the player's stack
			if (!player_stack_full) {
				cout << "Press 1 to stay with this card" << endl;
				cout << "Press 2 to pull an additional card out of the side pile" << endl;
				cout << "Press 3 to push this card onto your side pile: ";
				cin >> user_side_choice;
			}
			else {
				cout << "Your side pile is full. You cannot add any more cards to it" << endl;
				cout << "Press 1 to stay with this card" << endl;
				cout << "Press 2 to pull an additional card out of the side pile: ";
				cin >> user_side_choice;
			}
			while (try_again_input) {
				// Switch case for whether user wishes to use the side pile or not
				switch (user_side_choice) {
				case 1:
					// When player decides to do nothing with side pile
					if (compare_cards(player_card, computer_card)) {
						cout << "Congratulations! You have won" << endl;
						cout << "Both the cards have been returned to the bottom of your deck" << endl;
						player_deck.enqueue(player_card);
						player_deck.enqueue(computer_card);
						return true;
					}
					else {
						cout << "Bad Luck! You lost this round" << endl;
						cout << "Both cards have been returned to the bottom of the opponent's deck" << endl;
						computer_deck.enqueue(computer_card);
						computer_deck.enqueue(player_card);
						return false;
					}
					try_again_input = false;
					break;
				case 2:
					// When player decides to draw a card from side pile
					player_stack_card = player_stack.pop();
					if (compare_cards(player_card, computer_card, player_stack_card)) {
						cout << "Congratulations! You have won" << endl;
						cout << "All the cards have been returned to the bottom of your deck" << endl;
						player_deck.enqueue(player_card);
						player_deck.enqueue(computer_card);
						player_deck.enqueue(player_stack_card);
						return true;
					}
					else {
						cout << "Bad Luck! You lost this round" << endl;
						cout << "All the cards have been returned to the bottom of the opponent's deck" << endl;
						computer_deck.enqueue(computer_card);
						computer_deck.enqueue(player_card);
						computer_deck.enqueue(player_stack_card);
						return false;
					}
					try_again_input = false;
					break;
				case 3:
					// When player decides to push card onto side pile
					player_stack.push(player_card);
					player_card = player_deck.dequeue();
					cout << "The new card you have drawn is the " << card_values[player_card.val] << " of " << suite_values[player_card.suite] << endl;
					if (compare_cards(player_card, computer_card)) {
						cout << "Congratulations! You have won" << endl;
						cout << "Both the cards have been returned to the bottom of your deck" << endl;
						player_deck.enqueue(player_card);
						player_deck.enqueue(computer_card);
						return true;
					}
					else {
						cout << "Bad Luck! You lost this round" << endl;
						cout << "Both cards have been returned to the bottom of the opponent's deck" << endl;
						computer_deck.enqueue(computer_card);
						computer_deck.enqueue(player_card);
						return false;
					}
					try_again_input = false;
					break;
				default:
					// In case the user enters the wrong input
					cout << "Incorrect input. Please try again and enter only the input shown" << endl;
					if (player_stack_full) {
						cout << "Your side pile is full. You cannot add any more cards to it" << endl;
						cout << "Press 1 to stay with this card" << endl;
						cout << "Press 2 to pull an additional card out of the side pile: ";
					}
					else {
						cout << "Press 1 to stay with this card" << endl;
						cout << "Press 2 to pull an additional card out of the side pile" << endl;
						cout << "Press 3 to push this card onto your side pile: ";
					}
					cin >> user_side_choice;
					break;
				}
			}
		}
		// catch statements to check handle empty and full side piles
		catch (SideStack::EmptyStackException) {
			cout << "The side stack is empty. Please make a choice again" << endl;
			try_again = true;
		}
		catch (SideStack::FullStackException) {
			cout << "The side stack is full. You cannot add any more cards to it. Please try again" << endl;
			try_again = true;
		}
	}
}

// Both the compare_cards functions compare the cards given and return true for player victory and false for computer victory
// Since we are using a card system with A high and the card's vals are just indexes in the const array, we can compare them directly
bool compare_cards(card p, card c) {
	cout << "The computer's drawn card is the " << card_values[c.val] << " of " << suite_values[c.suite] << endl;
	return (p.val > c.val);
}

bool compare_cards(card p, card c, card s) {
	cout << "The computer's drawn card is the " << card_values[c.val] << " of " << suite_values[c.suite] << endl;
	cout << "The card you drew from the side pile is the " << card_values[s.val] << " of " << suite_values[s.suite] << endl;
	return ((p.val + s.val) > c.val);
}