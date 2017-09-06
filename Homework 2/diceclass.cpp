//This is an implement file for a dice class

#include "diceclass.h"
#include <iomanip>
#include <stdlib.h>
#include <time.h>

//implement
dice::dice(){
  num_side = 0;
};
dice::dice(int number){
    num_side = number;
}
//getter
int dice::roll(){
    return ((rand() % num_side) + 1);
};
//setter
void dice::set_number_of_sides(int num){
  num_side = num;
};

int dice::get_number_of_sides() {
	return num_side;
}
