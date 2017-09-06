//This program turn the lab1task3's structure into a class
#include <iostream>
#include <iomanip>
using namespace std;

//class declaration 
class Prod{	
	private:
	int id, units;
	double prices, sales;
	public:
	//setters
	void setid(int);
	void setunits(int);
	void setprices(double);
	void setsales(double);
	//getters
	int getid() const;
	int getunits() const;
	double getprices() const;
	double getsales() const;
	};