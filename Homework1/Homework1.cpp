// Including dependencies
#include <string>
#include <iomanip>
#include <iostream>
#include <fstream>

// Declaring globals
using namespace std;
const int NUMBER_OF_CHARS = 26;
const string output_file = "CardCatalog.txt";

// Declaring structs
struct BookInfo {
	string Title;
	string AuthorName;
	int LetterFrequency[NUMBER_OF_CHARS];
	int CharCount;
	int LineCount;
};


// Prototyping functions
void read_title_author(fstream&, BookInfo&);
void analyze_contents(fstream&, BookInfo&);
void book_output(fstream&, BookInfo&);
void output_frequency(BookInfo&);

// Main function
int main() {
	// Wrapping the whole program in while loop for requirement 6
	bool user_choice = true;
	while (user_choice) {
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

		// Initialising struct
		BookInfo curr_book;
		for (int i = 0; i < NUMBER_OF_CHARS; i++) {
			curr_book.LetterFrequency[i] = 0;
		}

		// Extracting information from the file stream into the struct
		read_title_author(BookRead, curr_book);
		analyze_contents(BookRead, curr_book);

		// creating stream for writing to file
		fstream BookWrite;
		BookWrite.open(output_file, ios::app);
		cout << "Writing Data to file " + output_file << endl;
		BookWrite << endl;
		book_output(BookWrite, curr_book);

		// Taking user input for displaying letter frequency
		char choice;
		cout << "Would you like to see the letter frequency of the input file?(Enter Y/N): ";
		cin >> choice;
		if (tolower(choice) == 'y') {
			output_frequency(curr_book);
		}

		// Deleting connections
		BookRead.close();
		BookWrite.close();

		// taking user choice for another file's processing
		user_choice = false;
		char user_c;
		cout << "The selected file has been processed." << endl;
		cout << "Would you like to process another file?(Y/N) :";
		cin >> user_c;
		if (tolower(user_c) == 'y') {
			user_choice = true;
		}
	}
	cout << "Ending program....." << endl;
	return 0;
}

// Implementing functions
void read_title_author(fstream& open_file_stream, BookInfo& curr_book) {
	string curr_line;
	std::getline(open_file_stream, curr_line);
	curr_book.Title = curr_line;
	std::getline(open_file_stream, curr_line);
	curr_book.AuthorName = curr_line;
	return;
}

void analyze_contents(fstream& open_file_stream, BookInfo& curr_book) {
	string curr_line;
	int line_count = 0;
	int char_count_total = 0;
	while (std::getline(open_file_stream, curr_line)) {
		// If statement to get past the line with only "Contents: "
		if (curr_line.length() == 9) {
			continue;
		}
		else {
			line_count++;
			// Counting only the line after "Contents: "
			int test_contents = curr_line.find("Contents:");
			if (test_contents > 0) {
				curr_line = curr_line.substr(test_contents);
			}
			for (unsigned int i = 0; i < curr_line.length(); i++) {
				if (isalpha(curr_line[i])) {
					// If alphabetic include the letter in count
					curr_book.LetterFrequency[tolower(curr_line[i]) - int('a')]++;
					char_count_total++;
				}
				else if (!isspace(curr_line[i])) {
					// If not a space and not alphabetic, include in total character count
					char_count_total++;
				}
			}
		}
	}
	curr_book.LineCount = line_count;
	curr_book.CharCount = char_count_total;
	return;
}

void book_output(fstream& write_file_stream, BookInfo& curr_book) {
	// Outputting all the information in the struct
	write_file_stream << "Title: " + curr_book.Title << endl;
	write_file_stream << "Full Author: " + curr_book.AuthorName << endl;
	write_file_stream << "Author First Name: " + curr_book.AuthorName.substr(0, curr_book.AuthorName.find(" ")) << endl;
	write_file_stream << "Author Last Name: " + curr_book.AuthorName.substr(curr_book.AuthorName.find(" ") + 1) << endl;
	write_file_stream << "Character Count: " + to_string(curr_book.CharCount) << endl;
	write_file_stream << "Line Count: " + to_string(curr_book.LineCount) << endl;
	return;
}

void output_frequency(BookInfo& curr_book) {
	cout << curr_book.Title + " letter frequency:" << endl;
	int total_characters = 0;
	// Getting total number of characters
	for (int i = 0; i < NUMBER_OF_CHARS; i++) {
		total_characters += curr_book.LetterFrequency[i];
	}
	// Getting frequency of characters
	for (int i = 0; i < NUMBER_OF_CHARS; i++) {
		cout << char(int('a') + i) << ": " << (double(curr_book.LetterFrequency[i]) / double(total_characters)) * 100 << "%" << endl;
	}
	return;
}