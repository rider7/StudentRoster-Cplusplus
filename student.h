#pragma once
#include<string>
#include<iostream>
#include"degree.h"
using namespace std;

//This class represents a student
//Declare functions and variables
class Student
{
public:
	const static int numDaysSize = 3;

protected: // These items are only visible to the derived classes
	//Define variables
	string studentID;
	string firstName;
	string lastName;
	string emailAddress;
	int age;
	int numDays[numDaysSize];
	DegreeType dtype;

public: // These items visible everywhere in the application
	Student(); //Empty Constructor
	Student(string ID, string firstName, string lastName, string emailAddress, int age, int numDays[]); //Full Constructor

	//Getters for each instance field
	string getStudentID();
	string getFirstName();
	string getLastName();
	string getEmailAddress();
	int getAge();
	int getNumDays(int classNumber);
	//int* getNumDays();
	virtual DegreeType getDegreeType() = 0; //Virtual, cannot instantiate a degree object
	

	//Setters
	void setStudentID(string ID);
	void setFirstName(string firstName);
	void setLastName(string lastName);
	void setEmailAddress(string emailAddress);
	void setAge(int age);
	void setNumDays(int class1, int class2, int class3);
	

	virtual void print();
	~Student();



};

