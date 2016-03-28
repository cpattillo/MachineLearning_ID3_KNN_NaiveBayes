
/*
Caroline Pattillo
cbp53@georgetown.edu
Platform : Windows
Language / Environment : C++, Visual Studios

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
#include "NumericAttribute.h"

using namespace std;

//Dafault constructor 
NumericAttribute::NumericAttribute(){}

//Other constructor
NumericAttribute::NumericAttribute(string name)
{
	Attribute::setName(name);
}

//Gets size of domain
int NumericAttribute::getSize() const
{
	return 0;
}

//Prints the numeric attribute 
void NumericAttribute::print(ostream &out) const
{
	out << getName() << " numeric";
}

//Overloading the << operator 
ostream &operator<<(ostream &out, const NumericAttribute &na)
{
	na.print(out);
	return out;
}
