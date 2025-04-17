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
	string key = item.makeKey();
	pair<string, ScheduleItem> entry(key, item);
	scheduleMap.insert(entry);
}

void Schedule::findByInstructor(string lastName)
{
	printHeader();
	map<string, ScheduleItem>::const_iterator it;
	for (auto it = scheduleMap.begin(); it != scheduleMap.end(); ++it)
	{
		SchItem item = it->second.getScheduleItem();
		int position = item.instructor.find(',', 0);
		string lName = item.instructor.substr(0, position);
		if (lName == lastName)
		{
			it->second.print();
			cout << endl;
		}
	}
}

void Schedule::findBySubject(string sub)
{
	printHeader();
	map<string, ScheduleItem>::const_iterator it;
	for (auto it = scheduleMap.begin(); it != scheduleMap.end(); ++it)
	{
		SchItem item = it->second.getScheduleItem();
		if (item.subject == sub)
		{
			it->second.print();
			cout << endl;
		}
	}
}

void Schedule::findBySubAndCat(string sub, string cat)
{
	printHeader();
	map<string, ScheduleItem>::const_iterator it;
	for (auto it = scheduleMap.begin(); it != scheduleMap.end(); ++it)
	{
		SchItem item = it->second.getScheduleItem();
		if (item.subject == sub && item.catalog == cat)
		{
			it->second.print();
			cout << endl;
		}
	}
}

void Schedule::print()
{
	printHeader();
	map<string, ScheduleItem>::const_iterator it;
	for (auto it = scheduleMap.begin(); it != scheduleMap.end(); ++it)
	{
		it->second.print();
		cout << endl;
	}
}

void Schedule::printHeader()
{
	cout << "Subject   Catalog   Section   Component   Session   Units   TotalEn   CapacityEn   Instructor" << endl;
}

void Schedule::printInstructions()
{
	cout << "*********************************" << endl;
	cout << "1. Search by Subject." << endl;
	cout << "2. Search by Subject and Catalog." << endl;
	cout << "3. Search by Instructor." << endl;
	cout << "4. Display schedule data. " << endl;
	cout << "0. Exit." << endl;
	cout << "*********************************" << endl;
}

void Schedule::initSchedule(ifstream& file)
{
	vector<string> itemInfo;
	string line, token;

	getline(file, line);

	while (getline(file, line))
	{
		istringstream ss(line);
		while (ss >> token)
		{
			if (token.front() == '"')
			{
				string nextName;
				while (token.back() != '"' && ss >> nextName)
				{
					token += " " + nextName;
				}
				token = token.substr(1, token.size() - 2);
			}
			itemInfo.push_back(token);
		}
		ScheduleItem newItem(itemInfo[0], itemInfo[1], itemInfo[2], itemInfo[3], itemInfo[4], stoi(itemInfo[5]), stoi(itemInfo[6]), stoi(itemInfo[7]), itemInfo[8]);
		addEntry(newItem);
		itemInfo.clear();
	}
}