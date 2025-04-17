//Schedule.h - specification file for the Schedule class.
//This program describes the Schedule class, which contains a map structure as an instance variable.
//The map structure holds pair objects where the unique keys representing the courses from the
//school schedule are the keys, and the courses themselves contained within a ScheduleItem object
//are the values. The courses contained in the map are searchable by subject, subject and catalog,
//and by instructor. A menu will be displayed for users for interacting with the map.

#pragma once
#include <map>
#include "ScheduleItem.h"

using namespace std;

class Schedule
{
private: 
	map<string, ScheduleItem> scheduleMap; //Map structure instance variable
public:
	//Constructors

	//Preconditions: None
	//Postconditions: A map object is created containing pair objects which represent the courses read in from the data file and their keys.
	Schedule()
	{
		ScheduleItem item;
		scheduleMap["KEY"] = item;
	}

	//Preconditions: None
	//Postconditions: A map object is created containing pair objects which represent the courses read in from the data file and their keys.
	Schedule(map<string, ScheduleItem>& map)
		: scheduleMap(map) {}

	//This function will add a new course into the map structure. The entry will be a pair object.
	//Preconditions: A reference to a ScheduleItem object must exist and be provided; ScheduleItem's makeKey() 
	//function must be accessible; the instance variable scheduleMap must be accessible. 
	//Postconditions: The pair object is added into the map structure; a key for the ScheduleItem is created.
	void addEntry(const ScheduleItem& item);

	//This function will allow the user to search for courses in the map by instructor name.
	//Preconditions: Parameter must be a string; instructors for all courses must be accessible; scheduleMap must be accessible for accessing courses.
	//Postconditions: All courses being taught by the match instructor will be displayed.
	void findByInstructor(string lastName);

	//This function will allow the user to search for courses in the map by subject name.
	//Preconditions: Parameter must be a string; subjects for all courses must be accessible; scheduleMap must be accessible for accessing courses.
	//Postconditions: All courses with matching subjects will be displayed.
	void findBySubject(string sub);

	//This function will allow the user to search for courses in the map by subject name and catalog name.
	//Preconditions: Parameters entered must be strings; subjects and catalogs for all courses must be accessible; scheduleMap must be accessible for accessing courses.
	//Postconditions: All courses with matching values will be displayed.
	void findBySubAndCat(string sub, string cat);

	//This function will initiate the map structure and fill it with all entries read from the data file.
	//Preconditions : The file must be accessible and open; access to addEntry function must be permitted.
	//Postconditions : All lines except for the header line from the file will be read and processed into the map.
	void initSchedule(ifstream& filename);

	//This function will display each entry in the map structure.
	//Preconditions: The map must contain some data; initSchedule function must be called to initiate map structure; ScheduleItem's print function must also be accessible.
	//Postconditions: All entries contained in the map will be displayed.
	void print();

	//This function will only display the headers for each column.
	//Preconditions: None
	//Postconditions: The header line will be displayed in a neat format.
	void printHeader(); 

	//This function will display a menu that users can use to interact with the map structure.
	//Preconditions: None
	//Postconditions: A menu containing all available options to the user will be displayed in a neat format.
	void printInstructions();
};