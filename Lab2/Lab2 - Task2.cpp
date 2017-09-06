#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
using namespace std;

int main()
{
	const int NUM_DIVS = 3;           // Number of divisions
	const int NUM_QTRS = 4;           // Number of quarters
	double sales[NUM_DIVS][NUM_QTRS]; // Array with 3 rows and 4 columns.
	double totalSales = 0;            // To hold the total sales.
	int div, qtr;                     // Loop counters.

	cout << "This program will calculate the total sales of\n";
	cout << "all the company's divisions.\n";
	cout << "Enter the following sales information:\n\n";

	// Nested loops to fill the array with quarterly
	// sales figures for each division.
	for (div = 0; div < NUM_DIVS; div++)
	{
		for (qtr = 0; qtr < NUM_QTRS; qtr++)
		{
			cout << "Division " << (div + 1);
			cout << ", Quarter " << (qtr + 1) << ": $";
			cin >> sales[div][qtr];
		}
		cout << endl; // Print blank line.
	}
	//-------------------------------------

	string filename;
	cout << "Please enter the name of the file you wish to have the output in: ";
	cin >> filename;
	fstream DataFile;
	DataFile.open(filename, ios::app);

	cout << "Writing data to " + filename + " file" << endl;

	DataFile << fixed << showpoint << setprecision(2);
	DataFile << "The sales for the company is: $" << endl;
	DataFile << "Div" << "\t" << "Q1" << "\t" << "Q2" << "\t" << "Q3" << "\t" << "Q4" << endl;

	for (div = 0; div < NUM_DIVS; div++) {
		DataFile << div + 1 << "\t";
		for (qtr = 0; qtr < NUM_QTRS; qtr++) {
			DataFile << "$" << sales[div][qtr] << "\t";
			totalSales += sales[div][qtr];
		}
		DataFile << endl;
	}

	DataFile << endl;
	DataFile << "The total sales for the company are: $";
	DataFile << totalSales << endl;

	cout << "The output has been written to file. Ending program..." << endl;

	return 0;
}
