/* File: Ch5_Programming_Project.cpp
   Programmer: Sean G
   Program 4: Patterns
   Requirements:

   Use nested or sequential loops to generate and format character-based output.
   Control repetition and alignment to match required patterns.
   Develop confidence with loop structure variations.
*/

#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	const int Size = 10;

	cout << "Pattern A:\n";
	for (int i = 1; i <= Size; ++i) {
		for (int b = 1; b <= i; ++b) {
			cout << "*";
		}
		cout << endl;
	}
	cout << endl;

	cout << "Pattern B:\n";
	for (int i = Size; i >= 1; --i) {
		for (int b = 1; b <= i; ++b) {
			cout << "*";
		}
		cout << endl;
	}
	cout << endl;

	return 0;
}

