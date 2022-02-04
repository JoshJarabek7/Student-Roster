// studentData.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "roster.h"
#include "degree.h"
#include "student.h"

int main()
{
	const std::string studentData[] =
	{
		"A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
		"A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
		"A3,Jack,Napoli,The_lawyer99@yahoo.com,19,20,40,33,SOFTWARE",
		"A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
		"A5,Joshua,Jarabek,jjarab4@student.wgu.edu,25,15,30,35,SOFTWARE"
	};

	const int numStudents = 5;
	Roster classRoster;


	std::cout << "C-867: Scripting and Programming \n";
	std::cout << "Language Used: C++ \n";
	std::cout << "Student ID: #002635884 \n";
	std::cout << "Student Name: Joshua Jarabek \n \n \n \n \n";

	for (int i = 0; i < numStudents; i++) classRoster.parse(studentData[i]);
	std::cout << "Displaying all students: " << std::endl;
	classRoster.printAll();
	std::cout << std::endl;


	for (int i = 0; i < 3; i++)
	{
		std::cout << "Displaying by Degree Program: " << degreeProgramStrings[i] << std::endl;
		// Cast integer to a Degree Program
		classRoster.printByDegreeProgram((DegreeProgram)i);
	}

	std::cout << "Displaying students with invalid emails" << std::endl;
	classRoster.printInvalidEmails();
	std::cout << std::endl;

	std::cout << "Displaying average Days in Course: " << std::endl;
	for (int i = 0; i < numStudents; i++)
	{
		classRoster.printAverageDaysInCourse(classRoster.studentRosterArray[i]->getID());
	}
	std::cout << std::endl;

	std::cout << "Removing students without ID number: " << std::endl;
	classRoster.remove("A3");
	classRoster.printAll();
	classRoster.remove("A3");
	std::cout << std::endl;

	system("pause");
	return 0;
}