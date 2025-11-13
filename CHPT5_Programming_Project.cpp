/* File: Ch5_Programming_Project.cpp
   Programmer: Sean G
   Program 5: Random Number Guessing Game
   Requirements:

   Generate random numbers using the C++ random library.
   Use loops with sentinel conditions to continue until correct guess.
   Provide meaningful feedback to the user and count attempts.
*/

#include <iostream>
#include <random>
using namespace std;

int main() {
	cout << "Would you like to play a game? (y/n): ";
	char StartGame;
	cin >> StartGame;
	if (StartGame != 'y' && StartGame != 'Y') {
		cout << "Maybe next time";
		return 0;
	}
	else {
		cout << "Great! Let's get started!\n";
	}
	const int MIN = 1;
	const int MAX = 100;
	random_device engine;
	uniform_int_distribution<int> NumDistribution(MIN, MAX);
	bool PlayAgain = true;

	while (PlayAgain) {
		int RandomNumber = NumDistribution(engine);
		int UserGuess = 0;
		int AttemptCount = 0;
		cout << "Welcome to the Random Number Guessing Game!\n";
		cout << "I have selected a random number between " << MIN << " and " << MAX << ".\n";
		cout << "Can you guess what it is?\n";
		while (UserGuess != RandomNumber) {
			cout << "Enter your guess here: ";
			cin >> UserGuess;
			if (cin.fail() || UserGuess < MIN || UserGuess > MAX) {
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cout << "Invalid input. Please enter a number between " << MIN << " and " << MAX << ".\n";
				continue;
			}
			AttemptCount++;
			if (UserGuess < RandomNumber) {
				cout << "Too low! Try again.\n";
			}
			else if (UserGuess > RandomNumber) {
				cout << "Too high! Try again.\n";
			}
			else {
				cout << "Congratulations! You guessed the correct number: " << RandomNumber << endl;
				cout << "It took you " << AttemptCount << " attempts.\n";
			}
		}
		char PlayAgainInput;
		cout << "Would you like to play again? (y/n): ";
		cin >> PlayAgainInput;
		if (PlayAgainInput == 'y' || PlayAgainInput == 'Y') {
			cout << "Great! I've selected a new number between " << MIN << " and " << MAX << ".\n";
		}
		else {
			cout << "Thank you for playing! Goodbye!\n";
			PlayAgain = false;
		}
	}
	return 0;
}

