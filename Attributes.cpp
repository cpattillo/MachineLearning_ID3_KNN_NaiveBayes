
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
#include "Attributes.h"
#include <vector>

using namespace std;

//Default Constructor 
Attributes::Attributes()
{
	classIndex = -1;
	hasNumericAttributes = false;
	hasNominalAttributes = false;
}

//Changing the function declaration 
void Attributes::add(Attribute* attribute) throw (logic_error)
{
	attributes.push_back(attribute);

	setClassIndex(attributes.size() - 1);

	if (typeid(*attribute) == typeid(NominalAttribute))
	{
		hasNominalAttributes = true;
	}
	else if (typeid(*attribute) == typeid(NumericAttribute))
	{
		hasNumericAttributes = true;
	}

	setClassIndex(attributes.size() - 1);
}

//Returning the class index 
int Attributes::getClassIndex() const throw (logic_error)
{
	return classIndex;
}

//Returns true if has a nominal attribute 
bool Attributes::getHasNominalAttributes() const
{
	return hasNominalAttributes;
}

//Returns true if has a numeric attribute
bool Attributes::getHasNumericAttributes() const
{
	return hasNumericAttributes;
}

//Returns the ith Attribute
Attribute * Attributes::get(int i) const throw (logic_error)
{
	return (attributes.at(i));
}

//Returns the class attribute 
Attribute * Attributes::getClassAttribute() const throw (logic_error)
{
	return (attributes[classIndex]);
}

//Returns the attribute's position in the array
int Attributes::getIndex(string name) const throw (logic_error)
{
	for (int i = 0; i < getSize(); i++)
	{
		if ((*(attributes.at(i))).getName() == name)
		{
			return i;
		}
	}

	cout << "in wrong index" << endl;
	return -1;
}

//Returns the size of the attributes array 
int Attributes::getSize() const
{
	return attributes.size();
}

//Parsing the attributes 
void Attributes::parse(istream &in) throw (logic_error)
{
	string find = "";
	string letter = "";
	int i = 0;

	Attribute* myAttrib = AttributeFactory::make(in);

	add(myAttrib);

}

//Setting a class index 
void Attributes::setClassIndex(int classIndex) throw (logic_error)
{
	this->classIndex = classIndex;
}

//Added print class to print out the attributes 
void Attributes::printd(ostream &out) const
{
	for (int i = 0; i < getSize(); i++)
	{
		if (typeid(*get(i)) == typeid(NominalAttribute))
		{
			NominalAttribute* temp = dynamic_cast<NominalAttribute *>(get(i));
			out << *temp << endl;
		}
		else
		{
			NumericAttribute* temp2 = dynamic_cast<NumericAttribute *>(get(i));
			out << *temp2 << endl;
		}

	}
}

//Overloading the << operator 
ostream &operator<<(ostream &out, const Attributes &a)
{
	a.printd(out);
	return out;
}

