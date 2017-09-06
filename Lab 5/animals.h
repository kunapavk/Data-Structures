// This file declare a base class called animals

#ifndef animals_H
#define animals_H

#include <cstdlib>
#include <string>

using namespace std;

//class declaration
class animals
{
private:
	string name;
	int age;
public:
	//defailt constructor
	animals();
	//overload constructor
	animals(string set_name, int set_age);
	//setter
	void set_name(string n);
	void set_age(int a);
	//getter
	string get_name() const;
	int get_age() const;
	//non-virtual
	void eat();
	//virtual
	virtual void move() const;
};
#endif
