#include <iostream>
#include <string>
#include "StackClass.h"
#include "Towerqueue.h"

#define NUMBER_OF_RODS 3
#define VICTORY_ROD_INDEX 2

struct Diskstruct {
	int size;
};

struct MoveStruct {
	int rod_from;
	int rod_to;
};

using namespace std;

bool take_turn(stackclass<Diskstruct> all_rods[], int num_disks, MoveStruct m);
void play(stackclass<Diskstruct> all_rods[], int num_disks, Towerqueue<MoveStruct>& all_moves);
int get_user_input();
bool check_victory_condition(stackclass<Diskstruct> all_rods[], int num_disks);
void print_to_screen(stackclass<Diskstruct> all_rods[], int num_disks);
void print_all_moves(Towerqueue<MoveStruct> all_moves);

int main() {
	int num_disks;
	cout << "Welcome the Towers of Hanoi game" << endl;
	cout << "Select the number of discs you wish to play with: ";
	cin >> num_disks;
	bool player_victory = false;
	stackclass<Diskstruct> A(num_disks);
	stackclass<Diskstruct> B(num_disks);
	stackclass<Diskstruct> C(num_disks);
	for (int i = num_disks; i > 0; i--) {
		Diskstruct* temp_val = new Diskstruct({ i });
		A.push( temp_val );
	}
	Towerqueue<MoveStruct> all_moves;
	stackclass<Diskstruct> all_rods[3] = { A, B, C };
	print_to_screen(all_rods, num_disks);
	play(all_rods, num_disks, all_moves);
	return 0;
}


void play(stackclass<Diskstruct> all_rods[], int num_disks, Towerqueue<MoveStruct>& all_moves) {
	int user_play_choice = get_user_input();
	bool end_game = false;
	int rod_from = 0;
	int rod_to = 0;
	bool valid_play = true;
	while (!end_game) {
		switch (user_play_choice) {
		case 1:
			print_to_screen(all_rods, num_disks);
			user_play_choice = get_user_input();
			break;
		case 2:
			cout << "Enter a rod you wish to move the disk from(1-3): ";
			cin >> rod_from;
			cout << "Enter a rod you wish to move the disk to(1-3): ";
			cin >> rod_to;
			MoveStruct temp = { (rod_from - 1), (rod_to - 1) };
			valid_play = take_turn(all_rods, num_disks, temp);
			if (!valid_play) {
				cout << "The move you made is invalid. Please try again" << endl;
			}
			else {
				print_to_screen(all_rods, num_disks);
				all_moves.enqueue(temp);
				end_game = check_victory_condition(all_rods, num_disks);
				if (end_game) {
					cout << "Congratulations. You have completed the Towers of Hanoi. The program will now show you all the moves you made." << endl;
					print_all_moves(all_moves);
					cout << "Program is ending...." << endl;
					break;
				}
				user_play_choice = get_user_input();
			}

		}
	}
}

int get_user_input() {
	int ret_val = 0;
	while (ret_val != 1 && ret_val != 2) {
		cout << "Press 1 to see the current rod structure" << endl;
		cout << "Press 2 to make a move: ";
		cin >> ret_val;
	}
	return ret_val;
}

bool take_turn(stackclass<Diskstruct> all_rods[], int num_disks, MoveStruct m) {
	int from_size = all_rods[m.rod_from].top() ? all_rods[m.rod_from].top()->size : 0;
	int to_size = all_rods[m.rod_to].top() ? all_rods[m.rod_to].top()->size: 0;
	if (!(from_size == 0) && ((to_size == 0) || !(from_size > to_size))) {
		Diskstruct* from_disk = all_rods[m.rod_from].pop();
		all_rods[m.rod_to].push(from_disk);
		return true;
	}
	else {
		return false;
	}
}

bool check_victory_condition(stackclass<Diskstruct> all_rods[], int num_disks) {
	for (int i = num_disks; i > 0; i--) {
		if (!all_rods[VICTORY_ROD_INDEX].stack_array[i-1]) {
			return false;
		}
		if (all_rods[VICTORY_ROD_INDEX].stack_array[i - 1]->size != (num_disks - i + 1)) {
			return false;
		}
	}
	return true;
}

void print_to_screen(stackclass<Diskstruct> all_rods[], int num_disks) {
	cout << endl << "Current structure of the rods is as follows" << endl;
	for (int i = num_disks; i > 0; i--) {
		for (int j = 0; j < NUMBER_OF_RODS; j++) {
			cout << "\t" << ((all_rods[j].stack_array[i - 1] == nullptr) ? "| |" : ("|" + to_string((all_rods[j].stack_array[i - 1])->size)) + "|");
		}
		cout << endl;
	}
	cout << "----------NAME OF RODS----------" << endl;
	for (int i = 0; i < NUMBER_OF_RODS; i++) {
		cout << "\t" << "|" + to_string(i + 1) + "|";
	}
	cout << endl;
}

void print_all_moves(Towerqueue<MoveStruct> all_moves) {
	int queue_length = all_moves.length();
	for (int i = 0; i < queue_length; i++) {
		MoveStruct curr_move = all_moves.dequeue();
		cout << "Move " + to_string(i + 1) + ": ";
		cout << "Rod " + to_string(curr_move.rod_from + 1) + " to " + to_string(curr_move.rod_to + 1) + "." << endl;
	}
}