#define MAX_ANIMALS 10

#ifndef ANIMAL_COLLECTION_H
#define ANIMAL_COLLECTION_H

template <class T>
class AnimalCollection {
	private:
		T animal_array[MAX_ANIMALS];
		int num_animals;
	public:
		AnimalCollection();
		void add_animal(T& temp_animal);
		T remove_animal();
		int get_num_animals();
		class FullStable{};
		class EmptyStable{};
};

template <class T>
AnimalCollection<T>::AnimalCollection() {
	num_animals = 0;
}

template <class T>
void AnimalCollection<T>::add_animal(T& temp_animal) {
	if (num_animals < MAX_ANIMALS) {
		animal_array[num_animals] = temp_animal;
		num_animals++;
	}
	else {
		throw FullStable();
	}
}

template <class T>
T AnimalCollection<T>::remove_animal() {
	num_animals--;
	if (num_animals >= 0) {
		return animal_array[num_animals];
	}
	else {
		throw EmptyStable();
	}
}

template <class T>
int AnimalCollection<T>::get_num_animals() {
	return num_animals;
}
#endif