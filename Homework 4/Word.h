#ifndef WORD_H
#define WORD_H

#include <string>

using namespace std;

class Word {
private:
	string data;
	int count;
public:
	Word() {
		data = "";
		count = 0;
	}
	string get_data() {
		return data;
	}
	int get_count() {
		return count;
	}
	Word(string val) {
		data = val;
		count = 1;
	}
	void increment_count() {
		count++;
	}
	bool operator == (Word& other) {
		string this_lower_case = this->get_data();
		this_lower_case[0] = tolower(this->get_data()[0]);
		string other_lower_case = other.get_data();
		other_lower_case[0] = tolower(other.get_data()[0]);
		return this_lower_case == other_lower_case;
	}
	bool operator > (Word& other) {
		string this_lower_case = this->get_data();
		this_lower_case[0] = tolower(this->get_data()[0]);
		string other_lower_case = other.get_data();
		other_lower_case[0] = tolower(other.get_data()[0]);
		return this_lower_case > other_lower_case;
	}
	bool operator < (Word& other) {
		string this_lower_case = this->get_data();
		this_lower_case[0] = tolower(this->get_data()[0]);
		string other_lower_case = other.get_data();
		other_lower_case[0] = tolower(other.get_data()[0]);
		return this_lower_case < other_lower_case;
	}
};

#endif