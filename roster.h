#pragma once
#include <string>
#include <iostream>
#include "student.h"
#include "softwareStudent.h"
#include "networkStudent.h"
#include "securityStudent.h"
#include "degree.h"
using namespace std;

//Roster is a collection of students
class Roster {
private:
	int lastStudent; //This is the last student in the Roster
	int maxRosterSize=5; //This keeps track of the max size of the roster
	Student** students; //Student is an array of pointers
public:
	Roster(); //Empy constructor creates roster and initializes all fields to default values
	Roster(int maxRosterSize); //This constructor does the same as above but sets max size

	Student* getStudentAt(int index);
	void parseThenAdd(string datarow); //Parses the strings, creates the Student objects, and adds them to the repo
	void add(string sID, string sfirstName, string slastName, string semailAddress, int sAge, int nd1, int nd2, int nd3, DegreeType d); //Called at the end
	void print_All(); //Prints all the students in the roster using each student's print() method
	void remove(string studentID); //Removes a student based on its ID
	void printAverageDaysInCourse(string studentID); //Prints students average days in course by student id
	void printInvalidEmails( ); //Finds and prints invalid emails
	void printByDegreeProgram(DegreeType d);
	~Roster(); //Destructor for the roster
};
