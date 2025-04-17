// Map Project.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <istream>
#include <iostream>
#include <fstream>
#include <string>
#include "Schedule.h"
#include "ScheduleItem.h"

using namespace std;

const string FILENAME = "Summer2022Schedule_Updated.txt";

int main()
{
	ifstream inFile;
	inFile.open(FILENAME);
	if (!inFile)
	{
		cout << "File not found." << endl;
		return 1;
	}

	Schedule mySchedule;
	mySchedule.initSchedule(inFile);

	bool appOn = true;
	int selection;
	string subject, category, lastName;
	while (appOn)
	{
		mySchedule.printInstructions();
		cin >> selection;

		if (selection == 1)
		{
			cout << "Enter the subject you would like to search: ";
			cin >> subject;
			mySchedule.findBySubject(subject);
			cout << endl;
		}
		else if (selection == 2)
		{
			cout << "Enter the subject you would like to search: ";
			cin >> subject;
			cout << "Enter the category you would like to search: ";
			cin >> category;
			mySchedule.findBySubAndCat(subject, category); 
			cout << endl;
		}
		else if (selection == 3)
		{
			cout << "Enter the last name of the instructor you would like to search: ";
			cin.ignore();
			getline(cin, lastName);
			mySchedule.findByInstructor(lastName);
			cout << endl;
		}
		else if (selection == 4)
		{
			mySchedule.print();
			cout << endl;
		}
		else if (selection == 0)
			appOn = false;
	}
	return 0;
}