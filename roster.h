#pragma once
#include "student.h"

class Roster
{
public:
	int lastIndex = -1;
	const static int numStudents = 5;
		Student * studentRosterArray[numStudents];

public:


	//Parse method goes through a set of comma delimited strings and extracts the data of a student
	void parse(std::string row);
	//All student data is passed into an add method, creating the student object, and then placing it in the roster
	void add
	(
		std::string sID,
		std::string sFirstName,
		std::string sLastName,
		std::string sEmail,
		std::string sAge,
		double sdays1,
		double sdays2,
		double sdays3,
		DegreeProgram degreeProgram
	);
	// Prints a tab-separated list of student data
	void printAll();

	// Prints out student information for a degree program specified by an enumerated type
	void printByDegreeProgram(DegreeProgram degreeProgram);

	//Each Student's email needs to include and '@' sign and a period '.', and should not include a space
	void printInvalidEmails();

	// Removes students from the roster by student ID. If student ID doesn't exist, the function prints an error message, indicating student not found
	void remove(std::string sID);

	// Prints a student's average number of days in the three courses. Identified by the sID parameter
	void printAverageDaysInCourse(std::string sID);

	~Roster();

};