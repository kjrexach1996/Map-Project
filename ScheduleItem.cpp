//ScheduleItem.cpp - implementation file for the ScheduleItem class.

#include <iomanip>
#include <iostream>
#include <map>
#include <utility>
#include "ScheduleItem.h"

using namespace std;

string ScheduleItem::makeKey() const
{
	string key = item.subject + "_" + item.catalog + "_" + item.section;
	return key;
}

void ScheduleItem::print()
{
	cout << setw(10) << left << item.subject; 
	cout << setw(10) << left << item.catalog << setw(10) << left << item.section;
	cout << setw(12) << left << item.component << setw(10) << left << item.session;
	cout << setw(8) << left << item.units << setw(10) << left << item.totalEnrolled;
	cout << setw(13) << left << item.capacityEnrolled << setw(50) << item.instructor;
}

bool ScheduleItem::operator==(const SchItem& second_operator) const
{
	string item1 = item.subject + "_" + item.catalog + "_" + item.section;
	string item2 = second_operator.subject + "_" + second_operator.catalog + "_" + second_operator.section;
	return item1 == item2;
}

bool ScheduleItem::operator!=(const SchItem& second_operator) const
{
	string item1 = item.subject + "_" + item.catalog + "_" + item.section;
	string item2 = second_operator.subject + "_" + second_operator.catalog + "_" + second_operator.section;
	return item1 != item2;
}

bool ScheduleItem::operator>(const SchItem& second_operator) const
{
	string item1 = item.subject + "_" + item.catalog + "_" + item.section;
	string item2 = second_operator.subject + "_" + second_operator.catalog + "_" + second_operator.section;
	return item1 > item2;
}