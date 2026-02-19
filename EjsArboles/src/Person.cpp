/*
 * Person.cpp
 *
 * 	Author: 		Profesores de EDI
 *  Description:	Implementation of the Person Class
 *  Version: 		1.0
 */

#include "Person.h"

Person::Person ( ) {
//	cout << "Person: Default constructor" << endl;
	this->name = "";
	this->id = "11111111A";
}

Person::Person ( string name, string id ) {
//	cout << "Person: Parameterized constructor" << endl;
	this->name = name;
	this->id = id;
}

Person::Person( const Person &otherPerson ) {
//	cout << "Person: Copy constructor" << endl;
	this->name = otherPerson.name;
	this->id = otherPerson.id;
}

Person::~Person ( ) {
//	cout << "Person: Destructor" << endl;
}

string Person::getName () {
	return this->name;
}

string Person::getId () {
	return this->id;
}

void Person::display () {
	cout << this->name << " " << this->id << endl;;
}
