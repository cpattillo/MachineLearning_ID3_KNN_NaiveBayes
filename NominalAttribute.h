

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


#ifndef NOMINALATTRIBUTE_H   
#define NOMINALATTRIBUTE_H

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
#include "Attribute.h"

using namespace std;

class NominalAttribute : public Attribute{

	//overriding the <<operator 
	friend ostream &operator<<(ostream &out, const NominalAttribute &na);


private:
	vector<string> domain; //hold the attribute domain 

public:

	//Default Constructor 
	NominalAttribute();

	//Sets name of attribute 
	NominalAttribute(string name);

	//Adds a value to domain of attribute 
	void addValue(string val) throw (logic_error);

	//Gets size of domain 
	virtual int getSize() const;

	//Gets the at certain index
	string getValue(int index) const throw (logic_error);

	//Gets the index of certain value 
	int getIndex(string value) throw (logic_error);

	//Prints the attribute and domain 
	virtual void print(ostream &out = cout) const;

};


#endif
