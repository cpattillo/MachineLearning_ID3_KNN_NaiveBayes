

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
#include <stdexcept>
#include <typeinfo> 
#include "AttributeFactory.h"

using namespace std;

//Making a Nominal or Numeric Attribute
Attribute* AttributeFactory::make(istream &in) throw (logic_error)
{
	string testing = "";

	//Temp string variables
	string val = "";
	string line = "";

	//Extracting name of the Attribute 
	in >> val;
	Attribute myAtt(val); //making temporary attribute 

	//Extracting first element in domain  
	in >> val;

	//Testing to see if numeric or nominal 
	if (val == "numeric")
	{
		NumericAttribute* myNum = new NumericAttribute(myAtt.getName());
		return myNum;
	}
	else
	{
		NominalAttribute* nomNom = new NominalAttribute(myAtt.getName());
		(*nomNom).addValue(val);

		while (in >> val)
		{
			(*nomNom).addValue(val);
		}

		return nomNom;
	}

}
