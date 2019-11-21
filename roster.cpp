#include <string>
#include <iostream>
#include "roster.h"
using namespace std;

Roster::Roster() // The empty constructor sets to default values.
{
	this->maxRosterSize = 0;
	this->lastStudent = -1; 
	this->students = nullptr;
}

Roster::Roster(int maxRosterSize) //Sets a max size for the roster
{
	this->maxRosterSize = maxRosterSize;
	this->lastStudent = -1; 
	this->students = new Student * [maxRosterSize];
}

Student* Roster::getStudentAt(int index)
{
	return students[index];
}

//Calls a seperate add() method at the end
void Roster::parseThenAdd(string row)
{
	if (lastStudent < maxRosterSize) {
		lastStudent++;
		DegreeType degreeType;
		degreeType = SECURITY;
		char lastLetter = row.back();
		
		if (lastLetter == 'K') {
			degreeType = NETWORKING;  
			//cout << "NETWORKING TEST";
		}
		else if (lastLetter == 'E') {
			degreeType = SOFTWARE;
			//cout << "SOFTWARE TEST";
		}
		else if (lastLetter == 'Y') {
			degreeType = SECURITY;
			//cout << "SECURITY TEST";
		}
		
		//Sort through the string by finding commas then extract subsrtring which we store in a temp var then move down the string to the next comma
		//repeat until all substrings are extracted
		int rhs = row.find(",");
		string sID = row.substr(0, rhs);

		//Find first name
		int lhs = rhs + 1;
		rhs = row.find(",", lhs);
		string sfirstName = row.substr(lhs, rhs - lhs);

		//Find last name
		lhs = rhs + 1;
		rhs = row.find(",", lhs);
		string slastName = row.substr(lhs, rhs - lhs);

		//Find email address
		lhs = rhs + 1;
		rhs = row.find(",", lhs);
		string semailAddress = row.substr(lhs, rhs - lhs);

		//Find age
		lhs = rhs + 1;
		rhs = row.find(",", lhs);
		int sAge = stoi(row.substr(lhs, rhs - lhs)); //stoi is StringToInteger method

		//Read each num of days
		lhs = rhs + 1;
		rhs = row.find(",", lhs);
		int numDay1 = stoi(row.substr(lhs, rhs - lhs)); //stoi is StringToInteger method

		lhs = rhs + 1;
		rhs = row.find(",", lhs);
		int numDay2 = stoi(row.substr(lhs, rhs - lhs));

		lhs = rhs + 1;
		rhs = row.find(",", lhs);
		int numDay3 = stoi(row.substr(lhs, rhs - lhs));

		//Our add() method will create the individual student based off the substrings we stored in the temporary variables
		add(sID, sfirstName, slastName, semailAddress, sAge, numDay1, numDay2, numDay3, degreeType);
	}
	else //We have too many students
	{
		cerr << "Too many students on the roster! Error!";
		exit(-1);
	}
}

//This method creates the student then adds all the values to the roster
void Roster::add(string sID, string sfirstName, string slastName, string semailAddress, int sAge, int nd1, int nd2, int nd3, DegreeType d)
{
	//Use an array numDays to pass the number of days in the constructor
	int numDays[Student::numDaysSize]; 
	numDays[0] = nd1;
	numDays[1] = nd2;
	numDays[2] = nd3;
	if (d == NETWORKING) students[lastStudent] = new NetworkStudent(sID, sfirstName, slastName, semailAddress, sAge, numDays, d);
	else if(d == SECURITY) students[lastStudent] = new SecurityStudent(sID, sfirstName, slastName, semailAddress, sAge, numDays, d);
	else students[lastStudent] = new SoftwareStudent(sID, sfirstName, slastName, semailAddress, sAge, numDays, d);
}

void Roster::print_All() // Go through the array of students and print each one
{

	for (int i = 0; i <= this->lastStudent; i++)(this->students)[i]->print();
}

void Roster::remove(string studentID) //Removes student from the roster based on studentID
{

	for (int i = 0; i <= lastStudent; ++i) {
		if (students[i] == nullptr) { //Checks if student is on the roster
			cout << "The student with ID: " << studentID << " was not found." << endl;
			break;
		}
		else if (studentID == students[i]->getStudentID()) { //Checks if student was removed from the roster
			students[i] = nullptr;
			cout << "The student with ID: " << studentID << " was removed." << endl;
		}
	}

}

void Roster::printAverageDaysInCourse(string studentID)
{
	bool found = false;
	for (int i = 0; i <= lastStudent; i++)
	{
		if (this->students[i]->getStudentID() == studentID) //Student found by their ID
		{
			found = true;
			//Print out the average num of days with the calculation using getNumDays()
			cout << "Average Days In Course " << students[i]->getStudentID() << " is " << ((students[i]->getNumDays(0) + students[i]->getNumDays(1) + students[i]->getNumDays(2)) / 3) << "\n";
		}
	}
	//Student is not found
	if (!found) cout << "Student not found!";
}

void Roster::printInvalidEmails() //Finds invalid emails
{
	cout << endl;
	cout << "Invalid Emails: ";
	for (int i = 0; i < 5; i++) { //Loops through the students onthe roster calling the getEmailAddress() method
		string invalidEmail = students[i]->getEmailAddress();
		if ((invalidEmail.find("@") == -1) || (invalidEmail.find(".") == -1) || !(invalidEmail.find(" ") == -1)) { //Checks each email address using find() method for "@" symbol or "." symbol and no spaces
			cout << invalidEmail << "\t";
		}
	}
	cout << endl << endl;
}

void Roster::printByDegreeProgram(DegreeType d)
{
	cout << endl << "Printing students of degree type " << degreeTypeStrings[d] << "\n";
	for (int i = 0; i <= lastStudent; i++)
	{
		//cout << lastStudent;
		if (this->students[i]->getDegreeType() == d) this->students[i]->print();
	}
	cout << endl;
}

Roster::~Roster()//Destroys all the students
{
	for (int i = 0; i <= lastStudent; i++)
	{
		delete this->students[i]; //Deletes each student first
	}
	delete students; //Deletes the dynamically allocated array of pointers to the students
}

int main() //MAIN 
{
	cout << "Scripting and Programming - Applications - C867 " << "Programming Language: C++ " << "Student ID: 001041039 " << "Brandon Rider" << endl;

	int numStudents = 5;
	const string studentData[5] =
	{ "A1,John,Smith,John1989@gmail.com,20,30,35,40,SECURITY",
	"A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
	"A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
	"A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
	"A5,Brandon,Rider,brider3@wgu.edu,30,23,35,24,SOFTWARE"
	};

	Roster* ros = new Roster(numStudents); //Create the roster
	cout << "Parsing data and adding students: ";
	for (int i = 0; i < numStudents; i++)
	{
		ros->parseThenAdd(studentData[i]);//Use parseThenAdd method to parse the data creating individual students and place them on the roster
	}
	cout << "DONE" << endl;
	cout << "Displaying all students: \n";
	ros->print_All();//Print the roster with all of the students through the print_All() method

	ros->printInvalidEmails();//Spots emails that are in error and displays them
	//Note: A valid email should include an at sign ('@') and period ('.') and should not include a space (' ').

	cout << "Printing average num of days for all students:" << endl;;
	for (int i = 0; i < numStudents; i++) {
		ros->printAverageDaysInCourse(ros->getStudentAt(i)->getStudentID());//Prints the average number of days for specific student
	}
	
	//Print students based on their degree program using printByDegreeProgram() method and looping through the roster
	for (int i = 0; i < 3; i++) ros->printByDegreeProgram((DegreeType)i);

	ros->remove("A3");
	cout << endl;
	ros->remove("A3");
	cout << endl;

	ros->Roster::~Roster();

	return 0; //Program completed
}