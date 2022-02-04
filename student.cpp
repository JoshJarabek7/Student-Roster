#include "student.h"
#include "degree.h"


//Parameterless constructor sets to default values
Student::Student()
{
	this->ID = "";
	this->firstName = "";
	this->lastName = "";
	this->email = "";
	this->age = "";
	for (int i = 0; i < daysArraySize; i++) this->days[i] = 0;
	this->degreeProgram = DegreeProgram::SECURITY;
}

Student::Student(std::string ID, std::string firstName, std::string lastName, std::string email, std::string age, double days[], DegreeProgram degreeProgram)
{
	this->ID = ID;
	this->firstName = firstName;
	this->lastName = lastName;
	this->email = email;
	this->age = age;
	for (int i = 0; i < daysArraySize; i++) this->days[i] = days[i];
	this->degreeProgram = degreeProgram;

}

//Destructor does nothing, because the Student class creates nothing dynamically
Student::~Student() 
{

}

std::string Student::getID() {
	return this->ID;
}

std::string Student::getFirstName() {
	return this->firstName;
}

std::string Student::getLastName() {
	return this->lastName;
}

std::string Student::getEmail() {
	return this->email;
}

std::string Student::getAge() {
	return this->age;
}

double* Student::getDays() {
	return this->days;
}

DegreeProgram Student::getDegreeProgram() {
	return this->degreeProgram;
}

void Student::setID(std::string ID) {
	this->ID = ID;
}

void Student::setFirstName(std::string firstName) {
	this->firstName = firstName;
}

void Student::setLastName(std::string lastName) {
	this->lastName = lastName;
}

void Student::setEmail(std::string email) {
	this->email = email;
}

void Student::setAge(std::string age) {
	this->age = age;
}

void Student::setDays(double days[]) {
	for (int i = 0; i < daysArraySize; i++)
		this->days[i] = days[i];
}

void Student::setDegreeProgram(DegreeProgram degreeProgram) {
	this->degreeProgram = degreeProgram;
}

void Student::print() {
	//Using tabs to separate the output and the getters
	std::cout << this->getID() << '\t';
	std::cout << "First Name: " << this->getFirstName() << '\t';
	std::cout << "Last Name: " << this->getLastName() << '\t';
	std::cout << "Email: " << this->getEmail() << '\t';
	std::cout << "Age: " << this->getAge() << "\t";
	std::cout << "daysInCourse: " << this->getDays()[0] << ", " << this->getDays()[1] << ", " << this->getDays()[2] << "\t";
	std::cout << "Degree Program: " << degreeProgramStrings[this->getDegreeProgram()] << '\n'; //DegreeProgram to string
}