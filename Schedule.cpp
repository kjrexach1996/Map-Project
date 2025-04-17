//Schedule.h - implementation file for the Schedule class.

#pragma once
#include <iostream>
#include <fstream>
#include <map>
#include <sstream>
#include <utility>
#include <vector>
#include "Schedule.h"
#include "ScheduleItem.h"

void Schedule::addEntry(const ScheduleItem& item)
{
	string key = item.makeKey(); //Calls makeKey to create a unique key
	pair<string, ScheduleItem> entry(key, item); //Creates a pair object using unique key as key and course as value
	scheduleMap.insert(entry); //Adds the new entry to the map
}

void Schedule::findByInstructor(string lastName)
{
	printHeader(); //Prints the column headers
	map<string, ScheduleItem>::const_iterator it; //Creates an iterator
	for (auto it = scheduleMap.begin(); it != scheduleMap.end(); ++it) //For traversing through the map
	{
		SchItem item = it->second.getScheduleItem(); //Return the item for variable access
		int position = item.instructor.find(',', 0); //Find the position where last name and first name are separated
		string lName = item.instructor.substr(0, position); //Create a substring from beginning of string to found position
		if (lName == lastName) //If user parameter matches substring
		{
			it->second.print(); //Print the course
			cout << endl;
		}
	}
}

void Schedule::findBySubject(string sub)
{
	printHeader(); //Prints the column headers
	map<string, ScheduleItem>::const_iterator it; //Creates an iterator
	for (auto it = scheduleMap.begin(); it != scheduleMap.end(); ++it) //For traversing through the map
	{
		SchItem item = it->second.getScheduleItem(); //Return the item for variable access
		if (item.subject == sub) //If user parameter matches course subject
		{
			it->second.print(); //Print the course
			cout << endl;
		}
	}
}

void Schedule::findBySubAndCat(string sub, string cat)
{
	printHeader(); //Prints the column headers
	map<string, ScheduleItem>::const_iterator it; //Creates an iterator
	for (auto it = scheduleMap.begin(); it != scheduleMap.end(); ++it) //For traversing through the map
	{
		SchItem item = it->second.getScheduleItem(); //Return the item for variable access
		if (item.subject == sub && item.catalog == cat) //If user parameters matches course subject and catalog
		{
			it->second.print(); //Print the course
			cout << endl;
		}
	}
}

void Schedule::initSchedule(ifstream& file)
{
	vector<string> itemInfo; //Vector for holding all course information
	string line, token; //Variables for file lines and tokens

	getline(file, line); //Reads and discards header line

	while (getline(file, line)) //Retrieving and storing each line
	{
		istringstream ss(line); //Tokenize the line
		while (ss >> token) //Store each part of line in the token
		{
			if (token.front() == '"') //If the token starts with quotations
			{
				string nextName; //Used for every part of instructor name
				while (token.back() != '"' && ss >> nextName) //Used to append instructor's name
				{
					token += " " + nextName; //Add next section of name with whitespaces
				}
				token = token.substr(1, token.size() - 2); //Create a substring to remove quotation marks
			}
			itemInfo.push_back(token); //Add the token to the vector
		}
		//Create a new ScheduleItem using data in vector 
		ScheduleItem newItem(itemInfo[0], itemInfo[1], itemInfo[2], itemInfo[3], itemInfo[4], stoi(itemInfo[5]), stoi(itemInfo[6]), stoi(itemInfo[7]), itemInfo[8]);
		addEntry(newItem); //Add the new item to the map
		itemInfo.clear(); //Reset the vector
	}
}

void Schedule::print()
{
	printHeader(); //Prints the column headers
	map<string, ScheduleItem>::const_iterator it; //Creates an iterator
	for (auto it = scheduleMap.begin(); it != scheduleMap.end(); ++it) //For traversing through the map
	{
		it->second.print(); //Print the course
		cout << endl;
	}
}

void Schedule::printHeader()
{
	//Prints the column headers
	cout << "Subject   Catalog   Section   Component   Session   Units   TotalEn   CapacityEn   Instructor" << endl;
}

void Schedule::printInstructions()
{
	//Prints the menu
	cout << "*********************************" << endl;
	cout << "1. Search by Subject." << endl;
	cout << "2. Search by Subject and Catalog." << endl;
	cout << "3. Search by Instructor." << endl;
	cout << "4. Display schedule data. " << endl;
	cout << "0. Exit." << endl;
	cout << "*********************************" << endl;
}

