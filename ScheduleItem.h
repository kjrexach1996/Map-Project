//ScheduleItem.h - specification file for ScheduleItem class.

#pragma once
#include <iostream>

using namespace std;

struct SchItem
{
	string subject;
	string catalog;
	string section;
	string component;
	string session;
	int units;
	int totalEnrolled;
	int capacityEnrolled; 
	string instructor;

	SchItem(string sub = "", string cat = "", string sec = "", string comp = "", string sess = "", int units = 0, int totEn = 0, int capEn = 0, string ins = "")
		: subject(sub), catalog(cat), section(sec), component(comp), session(sess), units(units), totalEnrolled(totEn), capacityEnrolled(capEn), instructor(ins) {};
} ;

class ScheduleItem
{
private:
	SchItem item;
public:
	ScheduleItem()
	{
		item = SchItem();
	}

	ScheduleItem(string sub, string cat, string sec, string comp, string sess, int units, int totEn, int capEn, string ins)
		: item(sub, cat, sec, comp, sess, units, totEn, capEn, ins) {};

	SchItem& getScheduleItem()
	{
		return item;
	}

	string makeKey() const;

	void print();

	bool operator==(const SchItem& second_operator) const;
	bool operator!=(const SchItem& second_operator) const;
	bool operator>(const SchItem& second_operator) const;
};