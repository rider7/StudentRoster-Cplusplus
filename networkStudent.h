#pragma once
#include<string>
#include<iostream>
#include"student.h"
using namespace std;

//Create subclass of Student for networkstudent
class NetworkStudent : public Student
{
public:
	NetworkStudent();
	NetworkStudent(
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
	~NetworkStudent();


};