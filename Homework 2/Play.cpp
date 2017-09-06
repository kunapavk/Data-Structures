#include "diceclass.h"
#include "Player.h"

using namespace std;

// Using global variables because we decided done and ugly is better than perfect
// Probably a better implementation is to pass in house wins as reference to play
int house_wins = 0;

// Function prototyping
int play(dice& player, dice& house, int wager, int total_money, bool hard_mode_choice);

// Main function

int main() {
	// Seeding random number generator with current time to ensure randomness
	srand(time(0));

	// Hard mode variables initialization
	bool hard_mode_choice_bool = false;
	char hard_mode_choice;
	cout << "Welcome to the Dice game" << endl;
	cout << "Would you like to try the hard mode?(Y/N): ";
	cin >> hard_mode_choice;
	hard_mode_choice_bool = (tolower(hard_mode_choice) == 'y');

	// Initial money and sides of dice initialization
	cout << "How much money do you wish to start with?: ";
	int initial_money = 0;
	cin >> initial_money;
	int dice_sides;
	cout << "What is the number of sides you wish to have on the dice?(6 - 20): ";
	cin >> dice_sides;
	while (dice_sides < 6 || dice_sides > 20) {
		cout << "Please enter a number between 6 and 20 inclusive";
		cin >> dice_sides;
	}

	// Creating two players representing self and the house
	Player self(initial_money, dice_sides);
	Player house(0, dice_sides);

	// Initializing variables to use inside the while loop
	char play_choice;
	bool play_choice_bool = true;
	int wager_amount;

	// Checking player's money and if player wishes to continue play
	while (self.get_money() > 0 && play_choice_bool) {
		// Quick and dirty implementation to differentiate between first time playing and other times
		if (self.get_money() != initial_money) {
			// Starting with displaying amount of money left after last play and asking whether player would like to continue
			cout << "You have " << self.get_money() << " left" << endl;
			cout << "Would you like to play again?(Y/N):";
			cin >> play_choice;
			if (tolower(play_choice) == 'n') {
				play_choice_bool = false;
			}
			else {
				// Simulating a round of play by asking wager
				cout << "Starting another round of play" << endl;
				cout << "The amount of money you have is: " << self.get_money() << endl;
				cout << "What would you like to wager?";
				cin >> wager_amount;
				// Checking if wager is possible with regards to current amount of money
				if (wager_amount > self.get_money()) {
					cout << "You do not have that much money left" << endl;
					// If the wager increase amount left, set wager to total amount left
					cout << "Wagering total amount left: " << self.get_money() << endl;
					wager_amount = self.get_money();
				}
				// Reducing wager amount from existing money
				self.set_money(self.get_money() - wager_amount);
				// Calling the play function with current state
				self.set_money(self.get_money() + play(self.own_dice, house.own_dice, wager_amount, self.get_money(), hard_mode_choice_bool));
			}
		}
		// Differentiating first time and other plays for output messages
		else {
			// First time playing: Don't need to display amount of money
			cout << "First play! What would you like to wager?";
			cin >> wager_amount;
			if (wager_amount > initial_money) {
				cout << "You do not have that much money left" << endl;
				cout << "Wagering total amount left: " << initial_money << endl;
				wager_amount = initial_money;
			}
			self.set_money(self.get_money() - wager_amount);
			self.set_money(self.get_money() + play(self.own_dice, house.own_dice, wager_amount, self.get_money(), hard_mode_choice_bool));
		}
	}

	// Output statements to represent game ending and cash out amount
	cout << "The game has ended." << endl;
	cout << "You have cashed out with " << self.get_money() << endl;

	return 0;
}


// Implementation of play function
int play(dice& player, dice& house, int wager, int total_money, bool hard_mode_choice) {
	// Initialization of values to be used inside the function
	// Return value is set at the end of the function
	// Wager increase is used to keep track of whether player increased the wager or not
	int return_value = 0;
	int wager_increase = 0;

	// Rolling player's dice and displaying the roll
	int player_roll = player.roll();
	cout << "Player's roll is: " << player_roll << endl;
	char user_choice;

	// Based on roll giving player chance to increase wager
	cout << "Would you like to increase the wager?(Y/N): ";
	cin >> user_choice;
	if (tolower(user_choice) == 'y') {
		cout << "Enter the amount you wish to increase the wager by(Maximum of double the original wager: " << wager << "): ";
		cin >> wager_increase;

		// Checking the wager doesn't go over the total money of the player's
		if (wager_increase <= total_money) {
			// Checking wager doesn't go above initial wager
			if (wager_increase > wager) {
				// If wager increase is greater than original wager set wager increase to original wager
				wager_increase = wager;
				cout << "Can only increase the wager upto twice the original amount." << endl;
				cout << "Increased the wager by twice the original amount" << endl;
				cout << "Current wager is: " << wager + wager_increase << endl;
			}
			else {
				cout << "Increased the wager by " << wager_increase << endl;
				cout << "Current wager is: " << wager + wager_increase << endl;
			}
		}
		else {
			// If wager increase is greater than wager, set it to 0
			cout << "You do not have that much money left to wager" << endl;
			cout << "Your wager is still " << wager << endl;
			wager_increase = 0;
		}
	}
	
	// Displaying house's roll
	int house_roll = house.roll();
	cout << "House's roll is: " << house_roll << endl;

	// Checking Win/Loss conditions
	if (player_roll > house_roll) {
		cout << "Your roll was greater than the house's roll" << endl;
		cout << "You have won " << endl;

		// Return value is double the wager and wager_increase since the requirements state returning the amount of money won
		// Also adding the return value to self.total_money in main function
		return_value = (2 * wager) + wager_increase;

		// Hard mode checks
		if (hard_mode_choice && house.num_side < 20) {
			house.set_number_of_sides(house.num_side + 1);
			cout << "The house's dice has increased the number of sides to " << house.num_side << endl;
		}
	}
	else if(player_roll < house_roll){
		cout << "The house's roll was greater than yours" << endl;
		cout << "Good luck next time" << endl;

		// Return value is 0 since loss minus wager_increase incase the wager was increased
		return_value = 0 - wager_increase;

		// Hard mode checks
		if (hard_mode_choice) {
			house_wins++;
			if (house_wins > 1 && (house.num_side > player.num_side)) {
				house.set_number_of_sides(house.num_side - 1);
				cout << "The house's dice has decreased number of sides to " << house.num_side << endl;
				house_wins = 0;
			}
		}
	}
	else {
		cout << "The house's roll was tied" << endl;
		cout << "Good luck next time" << endl;

		// Return value is 0 since loss minus wager_increase incase the wager was increased
		return_value = 0 - wager_increase;

		// Hard mode checks
		if (hard_mode_choice && (house.num_side > player.num_side)) {
			house_wins++;
			if (house_wins > 1) {
				house.set_number_of_sides(house.num_side - 1);
				cout << "The house's dice has decreased number of sides to " << house.num_side << endl;
				house_wins = 0;
			}
		}
	}
	return return_value;
}