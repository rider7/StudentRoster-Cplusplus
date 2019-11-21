#include<string>
#include<iostream>
#include"securityStudent.h"
using namespace std;

SecurityStudent::SecurityStudent() :Student()
{
	dtype = SECURITY;
}

SecurityStudent::SecurityStudent(string studentID, string firstName, string lastName, string emailAddress, int age, int numDays[], DegreeType degreetype)
	: Student(studentID, firstName, lastName, emailAddress, age, numDays) {
	dtype = SECURITY;
}

DegreeType SecurityStudent::getDegreeType() {
	return SECURITY;
}

void SecurityStudent::print()
{
	this->Student::print();
	cout << "SECURITY" << endl;
}

SecurityStudent::~SecurityStudent()
{
	Student::~Student(); //Calls superdestructor from Student
}
