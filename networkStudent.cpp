#include<string>
#include<iostream>
#include"networkStudent.h"
using namespace std;

NetworkStudent::NetworkStudent() :Student()
{
	dtype = NETWORKING;
}
//DegreeType dtype needed
NetworkStudent::NetworkStudent(string studentID, string firstName, string lastName, string emailAddress, int age, int numDays[], DegreeType degreetype)
	: Student(studentID, firstName, lastName, emailAddress, age, numDays) {
	dtype = NETWORKING;
}

DegreeType NetworkStudent::getDegreeType() {
	return NETWORKING;
}

void NetworkStudent::print()
{
	this->Student::print();
	cout << "NETWORKING" << endl;
}

NetworkStudent::~NetworkStudent()
{
	Student::~Student(); //Calls superdestructor form Student
}
