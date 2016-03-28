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

#include "Attribute.h"

using namespace std;

//Default Constructor 
Attribute::Attribute()
{
	//No updates 
}

//Other Constructor 
Attribute::Attribute(string name)
{
	this->name = name;
}

//Gets name of Attribute
string Attribute::getName() const
{
	return name;
}

//Gets size of attribute 
int Attribute::getSize() const
{
	return 0;
}

//Sets name of attribute 
void Attribute::setName(string name)
{
	this->name = name;
}

//Overloading the << operator 
ostream &operator<<(ostream &out, const Attribute &a)
{
	a.print(out);
	return out;
}
