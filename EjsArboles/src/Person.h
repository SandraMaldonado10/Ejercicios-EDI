/*
 * Person.h
 *
 * 	Author: 		Profesores de EDI
 *  Description:	Specification of the Person Class
 *  Version: 		1.0
 */

#ifndef PERSON_H_
#define PERSON_H_

#include <iostream>

using namespace std;

class Person {
private:
	string name;			// Name of the person
	string id;				// id of the person (e.g., 11111111A)

public:
	// PRE: ---
	// DES: Default constructor. Creates a "default" person with name = "" and
	//		id = "11111111A"
	// COM: O(1)
	Person ( );

	// PRE: ---
	// DES: Parameterized constructor. Creates a Person with name "name" and
	//		id "id"
	// COM: O(1)
	Person ( string name, string id );

	// PRE: otherPerson correctly initialized
	// DES: Copy constructor. Creates a person as a copy of "otherPerson"
	// COM: O(1)
	Person( const Person &otherPerson );

	// PRE: ---
	// DES: Returns the name of the person
	// COM: O(1)
	string getName ( );

	// PRE: ---
	// DES: Returns the id of the person
	// COM: O(1)
	string getId ( );

	// PRE: ---
	// DES: Displays the name and id of the person
	// COM: O(1)
	void display ( );

	// PRE: ---
	// DES: Destructor.
	// COM: O(1)
	~Person ( );
};

#endif /* PERSON_H_ */
