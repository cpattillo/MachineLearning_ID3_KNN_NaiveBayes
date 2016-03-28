/*
Caroline Pattillo
cbp53@georgetown.edu
Platform: Windows
Language/Environment: C++, Visual Studios

In accordance with the class policies and
Georgetown's Honor Code, I certify that, with
the exceptions of the class resources and those
items noted below, I have neither given nor received
any assistance on this project.
*/

#ifndef ATTRIBUTE_H
#define ATTRIBUTE_H

#include <sstream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <new>
#include <typeinfo> 

using namespace std;

class Attribute{

	//Overriding the << operator 
	friend ostream &operator<<(ostream &out, const Attribute &a);

protected:

	string name; //Name of Attribute 

	//Print Attribute
	virtual void print(ostream &out = cout) const {} //Prints Attribute 


public:

	//Default Constructor 
	Attribute();

	//Other Constructor 
	Attribute(string name);

	//Gets name of Attribute
	string getName() const;

	//Gets size of attribute 
	virtual int getSize() const;

	//Sets name of attribute 
	void setName(string name);

};

#endif;
