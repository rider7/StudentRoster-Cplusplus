#pragma once
#include<string>
#include<iostream>
#include"student.h"
using namespace std;

//Create subclass of Student for security student
class SecurityStudent : public Student
{
public:
	SecurityStudent();
	SecurityStudent(
		string studentID,
		string firstName,
		string lastName,
		string emailAddress,
		int age,
		int numDays[],
		DegreeType degreetype
	);
	
	DegreeType getDegreeType();
	void print();

	//Destructor
	~SecurityStudent();


};