/* File: Ch5_Programming_Project.cpp
   Programmer: Sean G
   Program 1: Population
   Requirements:

   Use loops to model repeated population growth across multiple days.
   Apply arithmetic calculations involving percentages.
   Implement input validation for starting size, daily increase, and days.
*/

#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main()
{

	int SP; //starting population
	double DIP; //daily increase percentage
	int NOD; //number of days to simulate

	do {
		cout << "Please enter the starting population (2 or more): ";
		cin >> SP;
		if (SP < 2) {
			cout << "The starting population must be at least 2. Please try again.\n";
		}
	} while (SP < 2);

	do {
		cout << "Please enter a positive number for the daily increase percentage: ";
		cin >> DIP;
		if (DIP < 0) {
			cout << "The daily increase percentage cannot be a negative number. Please try again.\n";
		}
	} while (DIP < 0);

	do {
		cout << "Please enter the number of days to simulate (min 1): ";
		cin >> NOD;
		if (NOD < 1) {
			cout << "Number of days must be at least 1. Please try again.\n";
		}
	} while (NOD < 1);

	cout << fixed << setprecision(2);
	cout << "\nDay \tPopulation\n";
	cout << "---------------------\n";

	for (int day = 1; day <= NOD; ++day) {
		cout << day << "\t" << SP << endl;

		SP += static_cast <int>(SP * (DIP / 100));
	}
	return 0;
}

