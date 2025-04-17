//ScheduleItem.cpp - implementation file for the ScheduleItem class.

#include <iomanip>
#include <iostream>
#include <map>
#include <utility>
#include "ScheduleItem.h"

using namespace std;

string ScheduleItem::makeKey() const
{
	string key = item.subject + "_" + item.catalog + "_" + item.section; //Creates a unique key for the course
	return key; //Returns the key
}

void ScheduleItem::print()
{
	//Prints each member variable from the struct instance variable.
	//All data is printed accurately to fall under matching column header.
	cout << setw(10) << left << item.subject; 
	cout << setw(10) << left << item.catalog << setw(10) << left << item.section;
	cout << setw(12) << left << item.component << setw(10) << left << item.session;
	cout << setw(8) << left << item.units << setw(10) << left << item.totalEnrolled;
	cout << setw(13) << left << item.capacityEnrolled << setw(50) << item.instructor;
}

bool ScheduleItem::operator==(const SchItem& second_operator) const
{
	string item1 = item.subject + "_" + item.catalog + "_" + item.section; //Create a key for the current object
	string item2 = second_operator.subject + "_" + second_operator.catalog + "_" + second_operator.section; //Create a key for the parameter object
	
	//True if the keys are equal; false if they are not equal.
	return item1 == item2;
}

bool ScheduleItem::operator!=(const SchItem& second_operator) const
{
	string item1 = item.subject + "_" + item.catalog + "_" + item.section; //Create a key for the current object
	string item2 = second_operator.subject + "_" + second_operator.catalog + "_" + second_operator.section; //Create a key for the parameter object

	//True if they are not equal; false if the keys are equal.
	return item1 != item2;
}

bool ScheduleItem::operator>(const SchItem& second_operator) const
{
	string item1 = item.subject + "_" + item.catalog + "_" + item.section; //Create a key for the current object
	string item2 = second_operator.subject + "_" + second_operator.catalog + "_" + second_operator.section; //Create a key for the parameter object

	//True if the first item's key is alphabetically first; false if not.
	return item1 > item2;
}