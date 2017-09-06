#include "Player.h"
#include "diceclass.h"

Player::Player() {
	money = 0;
	own_dice = dice();
}

Player::Player(int m) {
	money = m;
	own_dice = dice();
}

Player::Player(int m, int s) {
	money = m;
	own_dice = dice(s);
}

int Player::get_money() {
	return money;
}

void Player::set_money(int m) {
	money = m;
}