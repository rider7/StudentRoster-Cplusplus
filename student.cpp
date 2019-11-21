#include<string>
#include<iostream>
#include "student.h"
using namespace std;

//Define functions
Student::Student() //Set default values
{
	this->studentID = "";
	this->firstName = "";
	this->lastName = "";
	this->emailAddress = "";
	this->age = 0;
	for (int i = 0; i < numDaysSize; i++) this->numDays[i] = 0;
};

//Define full constructor
Student::Student(string ID, string firstName, string lastName, string emailAddress, int age, int numDays[])
{
	this->studentID = ID;
	this->firstName = firstName;
	this->lastName = lastName;
	this->emailAddress = emailAddress;
	this->age = age;
	for (int i = 0; i < numDaysSize; i++) this->numDays[i] = numDays[i];
};

//Define the Getters
string Student::getStudentID()
{
	return studentID;
}

string Student::getFirstName()
{
	return firstName;
}

string Student::getLastName()
{
	return lastName;
}

string Student::getEmailAddress()
{
	return emailAddress;
}

int Student::getAge()
{
	return age;
}

int Student::getNumDays(int classNumber) {
	return numDays[classNumber];
}

//Define the Setters
void Student::setStudentID(string ID) 
{
	this->studentID = ID;
}

void Student::setFirstName(string firstName)
{
	this->firstName = firstName;
}

void Student::setLastName(string lastName)
{
	this->lastName = lastName;
}

void Student::setEmailAddress(string emailAddress)
{
	this->emailAddress = emailAddress;
}

void Student::setAge(int age)
{
	this->age = age;
}

void Student::setNumDays(int class1, int class2, int class3)
{
	numDays[0] = class1;
	numDays[1] = class2;
	numDays[2] = class3;
}

//Print
void Student::print() 
{
	cout << this->getStudentID() << "\t";
	cout << "First Name: " << this->getFirstName() << "\t";
	cout << "Last Name: " << this->getLastName() << "\t";
	cout << "Age: " << this->getAge() << "\t";
	cout << "Days In Course: " << "{" << this->getNumDays(0) << ", " << this->getNumDays(1) << ", " << this->getNumDays(2) << "} ";
	cout << "Degree Program: ";
}

Student::~Student()
{}