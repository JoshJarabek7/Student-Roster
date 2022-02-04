#include "roster.h"
#include <stdbool.h>
#include <stdio.h>
#include "student.h"

// Parses each row, one at a time
void Roster::parse(std::string studentdata)
{
	DegreeProgram degreeProgram = SECURITY;
	if (studentdata.at(1) == '1') degreeProgram = SECURITY;
	else if (studentdata.at(1) == '2') degreeProgram = NETWORK;
	else if (studentdata.at(1) == '3') degreeProgram = SOFTWARE;
	else if (studentdata.at(1) == '4') degreeProgram = SECURITY;
	else if (studentdata.at(1) == '5') degreeProgram = SOFTWARE;


	// rhs is right-hand side, lhs is left-hand side

	// Find the comma
	int rhs = studentdata.find(",");

	//Extract the substrin in front of the comma
	std::string sID = studentdata.substr(0, rhs);

	// Move past the previous comma
	// First Name
	int lhs = rhs + 1;
	rhs = studentdata.find(",", lhs);
	std::string fn = studentdata.substr(lhs, rhs - lhs);

	// Last Name
	lhs = rhs + 1;
	rhs = studentdata.find(",", lhs);
	std::string ln = studentdata.substr(lhs, rhs - lhs);

	// Email
	lhs = rhs + 1;
	rhs = studentdata.find(",", lhs);
	std::string ema = studentdata.substr(lhs, rhs - lhs);

	// Age
	lhs = rhs + 1;
	rhs = studentdata.find(",", lhs);
	std::string ag = studentdata.substr(lhs, rhs - lhs);

	// Days In Course
	lhs = rhs + 1;
	// First Days to Complete
	double d1 = stod(studentdata.substr(lhs, rhs - lhs));
	lhs = rhs + 1;
	rhs = studentdata.find(",", lhs);
	// Second Days to Complete
	double d2 = stod(studentdata.substr(lhs, rhs - lhs));
	lhs = rhs + 1;
	rhs = studentdata.find(",", lhs);
	// Third Days to Complete
	double d3 = stod(studentdata.substr(lhs, rhs - lhs));

	// Days to Complete go in separately
	add(sID, fn, ln, ema, ag, d1, d2, d3, degreeProgram);

}

void Roster::add(std::string ID, std::string firstName, std::string lastName, std::string email, std::string age, double day1, double day2, double day3, DegreeProgram degreeProgram)
{
	// Put Days to Complete back into an array for the constructor
	double parr[3] = { day1,day2,day3 };

	// Make the new Student object
	// lastIndex starts at -1, not zero
	// Don't forget to use the prefix form of ++, not the postfix

	// Use full constructor
	studentRosterArray[++lastIndex] = new Student(ID, firstName, lastName, email, age, parr, degreeProgram);
}


// Display all students using tab-separated output
void Roster::printAll()
{
	
	for (int i = 0; i <= Roster::lastIndex; i++)
	{
		studentRosterArray[i]->print();
	
	}
}

// Display only the students which match the given degree program
void Roster::printByDegreeProgram(DegreeProgram degreeProgram)
{
	
	for (int i = 0; i <= Roster::lastIndex; i++)
	{
		if (Roster::studentRosterArray[i]->getDegreeProgram() == degreeProgram) studentRosterArray[i]->print();
	}
	std::cout << std::endl;
}

// Each Student's email must contain an @ sign, a period, and no spaces
void Roster::printInvalidEmails()
{
	for (int i = 0; i <= Roster::lastIndex; i++)
	{
		std::string ema = (studentRosterArray[i]->getEmail());
		if ((ema.find("@") == std::string::npos || ema.find(".") == std::string::npos || ema.find(" ") != std::string::npos))
		{
			std::cout << ema << ": " << studentRosterArray[i]->getEmail() << std::endl;
		}
	}
}

void Roster::printAverageDaysInCourse(std::string sID)
{
	for (int i = 0; i <= Roster::lastIndex; i++)
	{
		if (studentRosterArray[i]->getID() == sID)
		{
			std::cout << sID << ":";
			std::cout << (studentRosterArray[i]->getDays()[0] + studentRosterArray[i]->getDays()[1] + studentRosterArray[i]->getDays()[2]) / 3 << std::endl;
		}
		
	}
	std::cout << std::endl;
}

void Roster::remove(std::string sID)
{
	bool success = false;
	for (int i = 0; i <= Roster::lastIndex; i++)
	{
		if (studentRosterArray[i]->getID() == sID)
		{
			success = true;
			if (i < numStudents - 1)
			{
				Student* temp = studentRosterArray[i];
				studentRosterArray[i] = studentRosterArray[numStudents - 1];
				studentRosterArray[numStudents - 1] = temp;
			}
			Roster::lastIndex--;
			// Last book should no longer be visible
		}
	}
	if (success)
	{
		std::cout << sID << " removed from roster." << std::endl << std::endl;
		
		// Display the students - the removed one should not display
		this->printAll();
	}
	else std::cout << sID << " not found." << std::endl << std::endl;
}

Roster::~Roster()
{
	std::cout << "Destructor has been called." << std::endl << std::endl;
	for (int i = 0; i < numStudents; i++)
	{
		std::cout << "Destroying student #" << i + 1 << std::endl;
		delete studentRosterArray[i];
		studentRosterArray[i] = nullptr;
	}
}