#include <iostream>
#include <string>
#include "StackClass.h"

#define NUMBER_OF_RODS 5
#define VICTORY_ROD_INDEX 2

struct Diskstruct {
	int size;
	int owner;
};

struct MoveStruct {
	int rod_from;
	int rod_to;
};

int players[2] = { 0, 1 };
char player_denotions[2] = { 'X', 'O' };

using namespace std;

bool take_turn(stackclass<Diskstruct> all_rods[], int num_disks, MoveStruct m);
void play(stackclass<Diskstruct> all_rods[], int num_disks);
int get_user_input(int player);
bool check_victory_condition_multiplayer(stackclass<Diskstruct> all_rods[], int num_disks, int play_rod, int& curr_player);
void print_to_screen(stackclass<Diskstruct> all_rods[], int num_disks);

int main() {
	int num_disks;
	cout << "Welcome the Towers of Hanoi Multiplayer game" << endl;
	cout << "Select the number of discs you wish to play with: ";
	cin >> num_disks;
	bool player_victory = false;
	cout << "Player 1 will start on the left side. Player 1's disks will be denoted by an X." << endl;
	cout << "Player 2 will start on the right side. Player 2's disks will be denoted by an O." << endl;
	stackclass<Diskstruct> A(num_disks);
	stackclass<Diskstruct> B(num_disks);
	stackclass<Diskstruct> C(num_disks);
	stackclass<Diskstruct> D(num_disks);
	stackclass<Diskstruct> E(num_disks);
	stackclass<Diskstruct> all_rods[NUMBER_OF_RODS] = {A, B, C, D, E};
	for (int i = num_disks; i > 0; i--) {
		all_rods[0].push(new Diskstruct({ i, 0 }));
		all_rods[NUMBER_OF_RODS - 1].push(new Diskstruct({ i, 1 }));
	}
	print_to_screen(all_rods, num_disks);
	// play(A, B, C, all_rods, num_disks);
	play(all_rods, num_disks);
	return 0;
}


void play(stackclass<Diskstruct> all_rods[], int num_disks) {
	int current_player = 0;
	int user_play_choice = get_user_input(current_player);
	bool end_game = false;
	int rod_from = 0;
	int rod_to = 0;
	bool valid_play = true;
	while (!end_game) {
		switch (user_play_choice) {
		case 1:
			print_to_screen(all_rods, num_disks);
			user_play_choice = get_user_input(current_player);
			break;
		case 2:
			cout << "Enter a rod you wish to move the disk from(1-5): ";
			cin >> rod_from;
			cout << "Enter a rod you wish to move the disk to(1-5): ";
			cin >> rod_to;
			MoveStruct temp = { (rod_from - 1), (rod_to - 1) };
			valid_play = take_turn(all_rods, num_disks, temp);
			if (!valid_play) {
				cout << "The move you made is invalid. Please try again" << endl;
			}
			else {
				print_to_screen(all_rods, num_disks);
				end_game = check_victory_condition_multiplayer(all_rods, num_disks, temp.rod_to, current_player);
				if (end_game) {
					cout << "Congratulations. Player " + to_string(current_player + 1) +   " has won. The program will now end" << endl;
					break;
				}
				current_player = 1 - current_player;
				user_play_choice = get_user_input(current_player);
			}

		}
	}
}

int get_user_input(int player) {
	int ret_val = 0;
	cout << "It is the turn of player " + to_string(player + 1) + "." << endl;
	while (ret_val != 1 && ret_val != 2) {
		cout << "Press 1 to see the current rod structure" << endl;
		cout << "Press 2 to make a move: ";
		cin >> ret_val;
	}
	return ret_val;
}

bool take_turn(stackclass<Diskstruct> all_rods[], int num_disks, MoveStruct m) {
	int from_size = all_rods[m.rod_from].top() ? all_rods[m.rod_from].top()->size : 0;
	int to_size = all_rods[m.rod_to].top() ? all_rods[m.rod_to].top()->size : 0;
	if (!(from_size == 0) && ((to_size == 0) || !(from_size > to_size))) {
		Diskstruct* from_disk = all_rods[m.rod_from].pop();
		all_rods[m.rod_to].push(from_disk);
		return true;
	}
	else {
		return false;
	}
}

bool check_victory_condition_multiplayer(stackclass<Diskstruct> all_rods[], int num_disks, int play_rod, int& curr_player) {
	int stack_player = 0;
	for (int i = num_disks; i > 0; i--) {
		if (!all_rods[play_rod].stack_array[i - 1]) {
			return false;
		}
		else {
			stack_player = all_rods[play_rod].stack_array[i - 1]->owner;
		}
		if (all_rods[play_rod].stack_array[i - 1]->size != (num_disks - i + 1)) {
			return false;
		}
		if (stack_player != all_rods[play_rod].stack_array[i - 1]->owner) {
			return false;
		}
	}
	if ((stack_player == 0) && (play_rod != 4 && play_rod != 3)) {
		return false;
	}
	if ((stack_player == 1) && (play_rod != 0 && play_rod != 1)) {
		return false;
	}
	curr_player = stack_player;
	return true;
}

void print_to_screen(stackclass<Diskstruct> all_rods[], int num_disks) {
	cout << endl << "Current structure of the rods is as follows" << endl;
	for (int i = num_disks; i > 0; i--) {
		for (int j = 0; j < NUMBER_OF_RODS; j++) {
			cout << "\t" << ((all_rods[j].stack_array[i - 1] == nullptr) ? "| |" : ("|" + to_string((all_rods[j].stack_array[i - 1])->size)) + " " + player_denotions[all_rods[j].stack_array[i-1]->owner] + "|");
		}
		cout << endl;
	}
	cout << "---------------NAMES OF RODS---------------" << endl;
	for (int i = 0; i < NUMBER_OF_RODS; i++) {
		cout << "\t" << "|" + to_string(i + 1) + "|";
	}
	cout << endl;
}