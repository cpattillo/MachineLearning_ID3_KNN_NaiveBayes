
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


#ifndef ATTRIBUTES_H
#define ATTRIBUTES_H

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
#include "NominalAttribute.h"
#include "NumericAttribute.h"
#include "AttributeFactory.h"
#include <vector>

using namespace std;

class Attributes{

	//Overloading the << operator 
	friend ostream &operator<<(ostream &out, const Attributes &a);

private:
	vector<Attribute*> attributes;	//holds the attributes 
	bool hasNumericAttributes;		//true if have Numeric Attributes   
	bool hasNominalAttributes;		//true if have Nominal Attributes 
	int classIndex;					//last element processed 

public:

	//Default Constructor 
	Attributes();

	//Changing the function declaration 
	void add(Attribute* attribute) throw (logic_error);

	//Returning the class index 
	int getClassIndex() const throw (logic_error);
	
	//Returns true if has a nominal attribute 
	bool getHasNominalAttributes() const;
	
	//Returns true if has a numeric attribute
	bool getHasNumericAttributes() const;

	//Returns the ith Attribute
	Attribute *get(int i) const throw (logic_error);
	
	//Returns the class attribute 
	Attribute *getClassAttribute() const throw (logic_error);
	
	//Returns the attribute's position in the array
	int getIndex(string name) const throw (logic_error);

	//Returns the size of the attributes array 
	int getSize() const;
	
	//Parsing the attributes 
	void parse(istream &in) throw (logic_error);

	//Setting a class index 
	void setClassIndex(int classIndex) throw (logic_error);

	//Added print class to print out the attributes 
	void printd(ostream &out = cout) const;

};



#endif
