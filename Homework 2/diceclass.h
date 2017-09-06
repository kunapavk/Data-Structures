//This is a head file for dice class
#ifndef DICE_H
#define DICE_H

#include <iostream>
#include <iomanip>

using namespace std;
//dice class declarsion

class dice{
private:
  int num_side;
public:
  dice();
  dice(int num);
  int get_number_of_sides();
  int roll();
  void set_number_of_sides(int num);
  friend int play(dice& player, dice& house, int wager, int total_money, bool hard_mode_choice = false);
};

#endif
