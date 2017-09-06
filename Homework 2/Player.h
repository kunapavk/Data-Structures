#ifndef PLAYER_H
#define PLAYER_H

#include "diceclass.h"

class Player {
	private:
		int money;
	public:
		dice own_dice;
		Player();
		Player(int m);
		Player(int m, int s);
		int get_money();
		void set_money(int m);
		friend int play(dice& player, dice& house, int wager);
};

#endif // !PLAYER_H

