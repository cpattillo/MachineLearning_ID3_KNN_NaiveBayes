
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


#ifndef NUMERICATTRIBUTE_H
#define NUMERICATTRIBUTE_H

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


class NumericAttribute : public Attribute{

	//Overrding the << Operator 
	friend ostream &operator<<(ostream &out, const NumericAttribute &na);

public:

	//Dafault constructor 
	NumericAttribute();

	//Other constructor
	NumericAttribute(string name);
	
	//Gets size of domain
	virtual int getSize() const;

	//Prints the numeric attribute 
	virtual void print(ostream &out = cout) const;

};


#endif 
