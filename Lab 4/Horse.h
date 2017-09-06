#ifndef Horse_H
#define Horse_H
#include "animals.h"
#include <string>


class Horse : public animals {
	private:
		std::string colour;
	public:
		//setter
		void set_colour(std::string c);
		//getter
		std::string get_colour() const;

		void move() const;

		void eat() const;
};

#endif