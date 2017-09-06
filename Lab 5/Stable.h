#include "Horse.h"

#define MAX_HORSES 10


#ifndef STABLE_H
#define STABLE_H

class Stable {
	private:
		Horse horse_array[MAX_HORSES];
		int num_horses;
	public:
		Stable();
		void add_horse(Horse& h);
		Horse remove_horse();
		int get_num_horses();
		//Exception calss
		class FullStable{};
		class EmptyStable{};

};

#endif