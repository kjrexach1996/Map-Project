//Map Project.cpp: The purpose of this program is to read in data from a file representing the available
//courses during the Summer 2022 semester. The data will be read in to a map structure containing pair objects.
//The pair objects will contain unique keys will represent the courses as well as ScheduleItem objects which contain
//data about each course. The application will allow a user to search courses in the map structure using selections
//provided by a menu. Searching courses by subject name, subject and catalog names, and instructor names is possible. 
//Information will be displayed in neat and proper format for readability. 

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
	//Opens and reads data file; returns error if file is not found
	ifstream inFile;
	inFile.open(FILENAME);
	if (!inFile)
	{
		cout << "File not found." << endl;
		return 1;
	}

	//Initiates a new map object
	Schedule mySchedule;
	mySchedule.initSchedule(inFile);

	//Application usage
	bool appOn = true; //Flag for running application
	int selection; //Represents user choice
	string subject, category, lastName; //Stores all user inputs depending on selection made
	while (appOn)
	{
		mySchedule.printInstructions(); //Print menu
		cin >> selection; //Store choice

		if (selection == 1) //Finding course by subject
		{
			cout << "Enter the subject you would like to search: ";
			cin >> subject;
			mySchedule.findBySubject(subject);
			cout << endl;
		}
		else if (selection == 2) //Finding course by subject and catalog
		{
			cout << "Enter the subject you would like to search: ";
			cin >> subject;
			cout << "Enter the category you would like to search: ";
			cin >> category;
			mySchedule.findBySubAndCat(subject, category);
			cout << endl;
		}
		else if (selection == 3) //Finding course by instructor (last name)
		{
			cout << "Enter the last name of the instructor you would like to search: ";
			cin.ignore();
			getline(cin, lastName);
			mySchedule.findByInstructor(lastName);
			cout << endl;
		}
		else if (selection == 4) //Displays all courses in map
		{
			mySchedule.print();
			cout << endl;
		}
		else if (selection == 0) //Exit application
			appOn = false;
		else
			cout << "Invalid input!" << endl;
	}
	return 0;
}