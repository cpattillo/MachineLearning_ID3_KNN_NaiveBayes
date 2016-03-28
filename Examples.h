
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


#ifndef EXAMPLES_H
#define EXAMPLES_H


#include <sstream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <iomanip>
#include <vector>
#include <stdexcept> 
#include <new>
#include <typeinfo> 
#include "Attribute.h"
#include "Attributes.h"
#include "Example.h"
#include "NominalAttribute.h"
#include "NumericAttribute.h"

using namespace std;

class Examples : public vector<Example> {

	//Overriding the << operator 
	friend ostream &operator<<(ostream &out, const Examples &e);

private:
	Attributes attributes; //Attributes 

public:

	//Default Constructor 
	Examples();

	//Explicit Constructor 
	Examples(const Attributes &attributes) throw (logic_error);

	//Parse the Examples 
	void parse(istream &in) throw (logic_error);
	
	//Set the attributes 
	void setAttributes(const Attributes &attributes) throw (logic_error);

	//Prints out examples 
	void print(ostream & out = cout) const;

};//end class 


#endif
