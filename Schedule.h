//Schedule.h - specification file for the Schedule class.

#pragma once
#include <iostream>
#include <map>
#include "ScheduleItem.h"

using namespace std;

class Schedule
{
private: 
	map<string, ScheduleItem> scheduleMap;
public:
	Schedule()
	{
		ScheduleItem item;
		scheduleMap["KEY"] = item;
	}

	Schedule(map<string, ScheduleItem>& map)
		: scheduleMap(map) {}

	void addEntry(const ScheduleItem& item);
	void findByInstructor(string lastName);
	void findBySubject(string sub);
	void findBySubAndCat(string sub, string cat);
	void initSchedule(ifstream& filename);
	void print();
	void printHeader(); 
	void printInstructions();
};