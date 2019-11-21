#include<string>
#include<iostream>
#include"softwareStudent.h"
using namespace std;

SoftwareStudent::SoftwareStudent() :Student()
{
	dtype = SOFTWARE;
}

SoftwareStudent::SoftwareStudent(string studentID, string firstName, string lastName, string emailAddress, int age, int numDays[], DegreeType degreetype)
	: Student(studentID, firstName, lastName, emailAddress, age, numDays) {
	dtype = SOFTWARE;
}

DegreeType SoftwareStudent::getDegreeType() {
	return SOFTWARE;
}

void SoftwareStudent::print()
{
	this->Student::print();
	cout << "SOFTWARE" << endl;
}

SoftwareStudent::~SoftwareStudent()
{
	Student::~Student(); //Calls superdestructor form Student
}