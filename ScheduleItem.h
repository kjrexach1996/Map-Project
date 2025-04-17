//ScheduleItem.h - specification file for ScheduleItem class.
//This file contains a struct which holds all data for a course read from the data file.
//The ScheduleItem class returns the SchItem object to access all of its member variables
//as well as creates keys for the courses and prints their data in an organized format.

#pragma once

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

	//Constructor
	//Preconditions: None
	//Postconditions: A new SchItem is created with default or user parameters.
	SchItem(string sub = "", string cat = "", string sec = "", string comp = "", string sess = "", int units = 0, int totEn = 0, int capEn = 0, string ins = "")
		: subject(sub), catalog(cat), section(sec), component(comp), session(sess), units(units), totalEnrolled(totEn), capacityEnrolled(capEn), instructor(ins) {};
} ;

class ScheduleItem
{
private:
	SchItem item; //Instance variable is a struct SchItem to contain all fields
public:
	//Constructors
	
	//Preconditions: The SchItem's instance variables must be accessible to store information.
	//Postconditions: A new SchItem is created with default or user parameters and stored in the ScheduleItem object's instance variable. 
	ScheduleItem()
	{
		item = SchItem();
	}

	//Preconditions: The SchItem's instance variables must be accessible to store information.
	//Postconditions: A new SchItem is created with default or user parameters and stored in the ScheduleItem object's instance variable. 
	ScheduleItem(string sub, string cat, string sec, string comp, string sess, int units, int totEn, int capEn, string ins)
		: item(sub, cat, sec, comp, sess, units, totEn, capEn, ins) {};
	
	//The member variable is returned for easy access to the item's member variables.
	//Preconditions: The instance variable must exist and be filled in.
	//Postconditions: The SchItem instance variable reference will be returned.
	SchItem& getScheduleItem()
	{
		return item;
	}

	//A unique key for the course is created using the courses subject, catalog, and section. Each key must be unique.
	//Preconditions: A SchItem must exist; its subject, catalog, and section fields must be accessible.
	//Postconditions: The key must contain an underscore(_) between each of the fields displayed in the key; a string will be returned.
	string makeKey() const;

	//Print will neatly display all course information so that the data falls appropriately under each column header.
	//Preconditions: The SchItem variable and its individual fields must exist and be accessible.
	//Postconditions: Each field will be printed out and formatted so that all information aligns with headers.
	void print();

	//Overloaded Operators

	//Preconditions: Both SchItem objects and their instance variables must exist and be accessible for comparison.
	//Postconditions: The function must return true if the object's keys are equal and false if they are not. 
	bool operator==(const SchItem& second_operator) const;

	//Preconditions: Both SchItem objects and their instance variables must exist and be accessible for comparison.
	//Postconditions: The function must return false if the object's keys are equal and true if they are not. 
	bool operator!=(const SchItem& second_operator) const;

	//Preconditions: Both SchItem objects and their instance variables must exist and be accessible for comparison.
	//Postconditions: The function must return true if the first key is greater than the second key and false if the second key is greater than the first.
	bool operator>(const SchItem& second_operator) const;
};