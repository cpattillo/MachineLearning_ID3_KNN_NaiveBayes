

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
#include <vector>
#include <stdexcept>
#include <new>
#include <typeinfo> 
#include "NominalAttribute.h"

using namespace std;

//Default Constructor 
NominalAttribute::NominalAttribute()
{
	Attribute::name = "";
}

//Sets name of attribute 
NominalAttribute::NominalAttribute(string name)
{
	setName(name);
}

//Adds a value to domain of attribute 
void NominalAttribute::addValue(string val) throw (logic_error)
{
	domain.push_back(val);
}

//Gets size of domain 
int NominalAttribute::getSize() const
{
	return domain.size();
}

//Gets the at certain index
string NominalAttribute::getValue(int index) const throw (logic_error)
{
	return domain[index];
}

//Gets the index of certain value 
int NominalAttribute::getIndex(string value) throw (logic_error)
{
	for (int i = 0; i < domain.size(); i++)
	{
		if (domain.at(i) == value)
		{
			return i;
		}
	}

	return -1;
}

//Prints the attribute and domain 
void NominalAttribute::print(ostream &out) const
{
	out << getName() << " ";

	for (int i = 0; i < getSize(); i++)
	{
		out << domain[i] << " ";
	}

}

//Overloading the << operator 
ostream &operator<<(ostream &out, const NominalAttribute &na)
{
	na.print(out);
	return out;
}



