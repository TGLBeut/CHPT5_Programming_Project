/* File: Ch5_Programming_Project.cpp
   Programmer: Sean G
   Program 3: Population Bar Chart
   Requirements:

   Open and validate external data files.
   Use loops to read sequential data and associate values with years.
   Represent numeric values visually using text-based bar charts.
*/

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
using namespace std;

int main()
{
	const int Max_Years = 10;
	string Years[Max_Years];
	int Populations[Max_Years];
	int YearCount = 0;

	ifstream inputFile("population_data.txt");

	if (!inputFile) {
		cout << "Error opening file.\n";
		return 1;
	}

	while (YearCount < Max_Years && inputFile >> Years[YearCount] >> Populations[YearCount]) {
		YearCount++;
	}
	inputFile.close();

	cout << "Each * represents 1,000 people\n\n";
	cout << "Population Bar Chart\n";
	cout << "---------------------\n";
	for (int i = 0; i < YearCount; i++) {
		cout << Years[i] << " | ";

		int BarLength = Populations[i] / 1000;

		for (int b = 0; b < BarLength; b++) {
			cout << "*";
		}
		cout << " (" << Populations[i] << ")" << endl;
	}
	return 0;
}

