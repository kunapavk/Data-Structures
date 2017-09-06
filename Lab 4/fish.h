#ifndef Fish_H
#define Fish_h
#include "animals.h"

class fish : public animals{
	private:
		std::string species;
	public:
		//setter
		void set_species(std::string t);
		//getter
		std::string get_species() const;

		void move() const;

		void eat() const;
};

#endif