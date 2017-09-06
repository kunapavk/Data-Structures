// This program produces a sales report for DLC, Inc.

#include "ClassTask3.h"
#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
using namespace std;

// Function prototypes

void calcSales(class Prod[], int);
void showOrder(class Prod[], int);
void showOrderFile(class Prod[], int, fstream&);
void dualSort(class Prod[], int);
void showTotals(class Prod[], int);
void showTotalsFile(class Prod[], int, fstream&);
int number_of_lines_in_file(string file_name);

// NUM_PRODS is the number of products produced.

const int NUM_PRODS = 9;

int main()
{	//
	Prod myProducts[NUM_PRODS];
	string name_file;
	cout << "What's the name of file you want to test?";
	cin >> name_file;
	fstream customer_file;
	string line;
	customer_file.open(name_file, ios::in);
	if (!customer_file) {
		cout << "Given file name doesn't exist!";
		return 0;
	}

	int file_lines = number_of_lines_in_file(name_file);

	if (file_lines > 27) {
		cout << "The specified file has more than the required number of products." << endl;
		cout << "Please rerun the program and specify a file with " << NUM_PRODS * 3 << " products." << endl;
		return 0;
	}
	else if (file_lines < 27) {
		cout << "The specified file has less than the required number of products." << endl;
		cout << "Please rerun the program and specify a file with " << NUM_PRODS * 3 << " products." << endl;
		return 0;
	}

	if (std::getline(customer_file, line)) {
		int i = 0;
		myProducts[0].setid(stoi(line.substr(4, 3)));
		std::getline(customer_file, line);
		myProducts[0].setunits(stoi(line.substr(7, 3)));
		std::getline(customer_file, line);
		myProducts[0].setprices(atof((line.substr(7, 5)).c_str()));
		for (i = 1; i < NUM_PRODS; i++) {
			std::getline(customer_file, line);
			myProducts[i].setid(stoi(line.substr(4, 3)));
			std::getline(customer_file, line);
			myProducts[i].setunits(stoi(line.substr(7, 3)));
			std::getline(customer_file, line);
			myProducts[i].setprices(atof((line.substr(7, 5)).c_str()));
		}
	}
	else {
		cout << "empty file!";
		return 0;
	}

	 // Calculate each product's sales.
	 calcSales(myProducts, NUM_PRODS);

	 // Sort the elements in the sales array in descending
	 // order and shuffle the ID numbers in the id array to
	 // keep them in parallel.
	 dualSort(myProducts, NUM_PRODS);

	 string user_choice;
	 cout << "Please  enter a filename if you wish to save the ouput. If not enter N: ";
	 cin >> user_choice;

	 if (user_choice.length() == 1 && tolower(user_choice[0]) == 'n') {
		 cout << setprecision(2) << fixed << showpoint;
		 showOrder(myProducts, NUM_PRODS);
		 showTotals(myProducts, NUM_PRODS);
	 }
	 else {
		 fstream WriteStream;
		 WriteStream.open(user_choice, ios::app);
		 WriteStream << setprecision(2) << fixed << showpoint;
		 showOrderFile(myProducts, NUM_PRODS, WriteStream);
		 showTotalsFile(myProducts, NUM_PRODS, WriteStream);
	 }

	 // Set the numeric output formatting.
	 

	 // Display the products and sales amounts.
	 

	 // Display total units sold and total sales.
	return 0;
}

//****************************************************************
// Definition of calcSales. Accepts units, prices, and sales     *
// arrays as arguments. The size of these arrays is passed       *
// into the num parameter. This function calculates each         *
// product's sales by multiplying its units sold by each unit's  *
// price. The result is stored in the sales array.               *
//****************************************************************

void calcSales(class Prod myProducts[], int num)
{
   for (int index = 0; index < num; index++)
	  myProducts[index].setsales(myProducts[index].getunits() * myProducts[index].getprices());
}

//***************************************************************
// Definition of function dualSort. Accepts id and sales arrays *
// as arguments. The size of these arrays is passed into size.  *
// This function performs a descending order selection sort on  *
// the sales array. The elements of the id array are exchanged  *
// identically as those of the sales array. size is the number  *
// of elements in each array.                                   *
//***************************************************************

void dualSort(class Prod myProducts[], int size)
{
   int startScan, maxIndex, tempid;
   double maxValue;
   Prod temp_prod;
   for (startScan = 0; startScan < (size - 1); startScan++)
   {
	  maxIndex = startScan;
	  maxValue = myProducts[startScan].getsales();
	  tempid = myProducts[startScan].getid();
	  for(int index = startScan + 1; index < size; index++)
	  {
		 if (myProducts[index].getsales() > maxValue)
		 {
			maxValue = myProducts[index].getsales();
			tempid = myProducts[index].getid();
			maxIndex = index;
		 }
	  }
	  temp_prod = myProducts[startScan];
	  myProducts[startScan] = myProducts[maxIndex];
	  myProducts[maxIndex] = temp_prod;
   }
}

//****************************************************************
// Definition of showOrder function. Accepts sales and id arrays *
// as arguments. The size of these arrays is passed into num.    *
// The function first displays a heading, then the sorted list   *
// of product numbers and sales.                                 *
//****************************************************************

void showOrder(class Prod myProducts[], int num)
{
   cout << "Product Number\tSales\n";
   cout << "----------------------------------\n";
   for (int index = 0; index < num; index++)
   {
	  cout << myProducts[index].getid() << "\t\t$";
	  cout << setw(8) << myProducts[index].getsales() << endl;
   }
   cout << endl;
}

void showOrderFile(class Prod myProducts[], int num, fstream& write_file_stream)
{
	write_file_stream << "Product Number\tSales\n";
	write_file_stream << "----------------------------------\n";
	for (int index = 0; index < num; index++)
	{
		write_file_stream << myProducts[index].getid() << "\t\t$";
		write_file_stream << setw(8) << myProducts[index].getsales() << endl;
	}
	write_file_stream << endl;
}

//*****************************************************************
// Definition of showTotals function. Accepts sales and id arrays *
// as arguments. The size of these arrays is passed into num.     *
// The function first calculates the total units (of all          *
// products) sold and the total sales. It then displays these     *
// amounts.                                                       *
//*****************************************************************

void showTotals(class Prod myProducts[], int num)
{
   int totalUnits = 0;
   double totalSales = 0.0;

   for (int index = 0; index < num; index++)
   {
	  totalUnits += myProducts[index].getunits();
	  totalSales += myProducts[index].getsales();
   }
   cout << "Total units Sold:  " << totalUnits << endl;
   cout << "Total sales:      $" << totalSales << endl;
}

void showTotalsFile(class Prod myProducts[], int num, fstream& write_file_stream) {
	int totalUnits = 0;
	double totalSales = 0.0;

	for (int index = 0; index < num; index++)
	{
		totalUnits += myProducts[index].getunits();
		totalSales += myProducts[index].getsales();
	}
	write_file_stream << "Total units Sold:  " << totalUnits << endl;
	write_file_stream << "Total sales:      $" << totalSales << endl;
}

int number_of_lines_in_file(string file_name) {
	int ret_val = 0;
	fstream tempStream(file_name, ios::in);
	string line_holder;
	while (getline(tempStream, line_holder)) {
		++ret_val;
	}
	return ret_val;
}