#include <iostream>
#include <iomanip>
#include <stdio.h>
#include <string>
#include <fstream>

using namespace std;
const int MAX_LINE_SIZE = 512;

void main() {
	string filename;
	cout << "Please enter the name of the file you wish to read" << endl;
	cin >> filename;
	fstream toReadFiles;
	char line[MAX_LINE_SIZE];
	toReadFiles.open(filename, ios::in);
	if (!toReadFiles) {
		cout << "The mentioned file does not exist" << endl;
		return;
	}
	int i = 0;
	for (i = 0; i < 10; i++) {
		if (toReadFiles.getline(line, MAX_LINE_SIZE)) {
			cout << (i+1) << ". " << line << endl;
		}
		else {
			cout << "The file mentioned only has " << i << " lines" << endl;
			return;
		}
	}
	if (i == 10 && toReadFiles.getline(line, MAX_LINE_SIZE)) {
		cout << "The specified file has more than 10 lines" << endl;
	}
	else {
		cout << "The specified file has exactly 10 lines" << endl;
	}
	cout << "End of program" << endl;
	return;
}
