/* File: Ch5_Programming_Project.cpp
   Programmer: Sean G
   Program 2: Student Line-Up
   Requirements:

   Read data from an input file until end-of-file (EOF).
   Apply string comparisons to determine alphabetical order.
   Output correct information (class size, first student, last student).
*/

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <cstdlib>
#include <cmath>
using namespace std;

int main()
{
	ifstream inputFile;
	string Name;
	string FirstStudent;
	string LastStudent;

	int StudentCount = 0;

	inputFile.open("students.txt");
	if (!inputFile) {
		cout << "Error opening the file." << endl;
		return 1;
	}
	while (inputFile >> Name) {
		StudentCount++;

		if (StudentCount == 1 || Name < FirstStudent) {
			FirstStudent = Name;
		}
		if (StudentCount == 1 || Name > LastStudent) {
			LastStudent = Name;
		}
	}
	inputFile.close();

	cout << "Class Size: " << StudentCount << endl;
	if (StudentCount > 0)
	{
		cout << "First Student: " << FirstStudent << endl;
		cout << "Last Student: " << LastStudent << endl;
	}
	else {
		cout << "No students found." << endl;
	}
	return 0;
}

