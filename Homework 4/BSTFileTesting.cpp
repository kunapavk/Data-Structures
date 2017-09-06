#include <iostream>
#include <string>
#include <fstream>
#include "Node.h"
#include "BST.h"
#include "Word.h"

using namespace std;

int get_user_choice();

int main() {
	BST<Word> tree;
	fstream BookRead;

	string input_file;
	cout << "Please enter the name of the file to be processed: ";
	cin >> input_file;

	// While loop to make sure input file name is correct
	BookRead.open(input_file, ios::in);
	while (!BookRead) {
		cout << "The specified file is not available." << endl << endl;
		cout << "Please enter a valid file name: ";
		cin >> input_file;
		BookRead.open(input_file, ios::in);
	}

	char x;
	string curr_word;
	Node<Word>* is_present = nullptr;
	// Reading words letter by letter until a non alphanum char is read
	while (BookRead.get(x)) {
		if (isalnum(x)) {
			curr_word += x;
		}
		else {
			// If word's length is not 0 add the word to a struct
			if (curr_word.length() != 0) {
				Word curr_word_struct(curr_word);
				// Find if struct exists in tree
				is_present = tree.find(curr_word_struct);
				// If it exists, increment the count else add it to the tree
				if (is_present) {
					is_present->get_data_pointer()->increment_count();
				}
				else {
					tree.insert(curr_word_struct);
				}
				// Reset the curr_word to an empty string
				curr_word = "";
			}
		}
	}

	cout << "The file has been loaded into the tree." << endl;
	// Get user choice, while loop to make sure user choice is correct
	int user_choice_inner = get_user_choice();
	while (user_choice_inner < 1 || user_choice_inner > 4) {
		cout << "Incorrect input. Please try again" << endl;
		user_choice_inner = get_user_choice();
	}
	while (user_choice_inner != 4) {
		// Switch case for handling all the cases
		switch (user_choice_inner) {
		case 1:
		{
			string word_search;
			cout << "Please enter the word you wish to search for: ";
			cin >> word_search;
			Word word_search_struct(word_search);
			Node<Word>* found = tree.find(word_search_struct);
			if (found) {
				cout << "The word you were looking for: " << word_search << " has " << found->get_data().get_count() << " occurences in the file" << endl;
			}
			else {
				cout << "The word you were looking for does not appear in the file" << endl;
			}
			break;
		}
		case 2:
		{
			Node<Word>** ascending_words = tree.getAllAscending();
			int tree_size = tree.BST_size();
			for (int i = 0; i < tree_size; i++) {
				cout << "The word at position " << (i + 1) << " is " << ascending_words[i]->get_data().get_data() << " and it occurs " << ascending_words[i]->get_data().get_count() << " times in the file." << endl;
			}
			break;
		}
		case 3:
		{
			Node<Word>** descending_words = tree.getAllDescending();
			int tree_size = tree.BST_size();
			for (int i = 0; i < tree_size; i++) {
				cout << "The word at position " << (i + 1) << " is " << descending_words[i]->get_data().get_data() << " and it occurs " << descending_words[i]->get_data().get_count() << " times in the file." << endl;
			}
			break;
		}
		default:
		{
			cout << "Wrong input. Please try again" << endl;
		}
		}
		cout << " \n\n\n\n\n\n\n" << endl;
		user_choice_inner = get_user_choice();
		while (user_choice_inner < 1 || user_choice_inner > 4) {
			cout << "Incorrect input. Please try again" << endl;
			user_choice_inner = get_user_choice();
		}
	}

}

int get_user_choice() {
	int inner_user_input = 1;
	string inner_user_input_string;
	cout << "Please select what you wish to do from the following: " << endl;
	cout << "1. Search for a word" << endl;
	cout << "2. Get all words in ascending order" << endl;
	cout << "3. Get all words in descending order" << endl;
	cout << "4. Exit the program: ";
	cin >> inner_user_input_string;
	inner_user_input = stoi(inner_user_input_string);
	return inner_user_input;
}