

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


#ifndef ATTRIBUTEFACTORY_H
#define ATTRIBUTEFACTORY_H

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
#include "Attribute.h"
#include "NominalAttribute.h"
#include "NumericAttribute.h"

using namespace std;


class AttributeFactory{

public:

	//Making a Numeric or Nominal Attribute
	static Attribute* make(istream &in) throw (logic_error);
	
};

#endif
