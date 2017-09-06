#include "Stable.h"

Stable::Stable() {
	num_horses = 0;
}

void Stable::add_horse(Horse& h) {
	if (num_horses < MAX_HORSES) {
		horse_array[num_horses] = h;
		num_horses++;
	}
	else
		throw FullStable();
}

Horse Stable::remove_horse() {
	num_horses--;
	if (num_horses >= 0)
		return horse_array[num_horses];
	else
		throw EmptyStable();

}

int Stable::get_num_horses() {
	return num_horses;
}