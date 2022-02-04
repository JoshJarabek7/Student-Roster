#pragma once
#include <iomanip>
#include "degree.h"
#include <iostream>

class Student
{
public:
	const static int daysArraySize = 3;

private:
	std::string ID;
	std::string firstName;
	std::string lastName;
	std::string email;
	std::string age;
	double days[daysArraySize];
	DegreeProgram degreeProgram;

public:
	//Parameterless constructor (setting to defaul values)
	Student();

	//Full constructor
	Student(std::string ID, std::string firstName, std::string lastName, std::string email, std::string age, double days[], DegreeProgram degreeProgram);

	//Destructor
	~Student();

	//Getters (or Accessors)
	std::string getID();
	std::string getFirstName();
	std::string getLastName();
	std::string getEmail();
	std::string getAge();
	double* getDays();
	DegreeProgram getDegreeProgram();


	//Setters (or Mutators)
	void setID(std::string ID);
	void setFirstName(std::string firstName);
	void setLastName(std::string lastName);
	void setEmail(std::string email);
	void setAge(std::string age);
	void setDays(double days[]);
	void setDegreeProgram(DegreeProgram degreeProgram);

	//Displays 'this' student's data
	void print();
};

