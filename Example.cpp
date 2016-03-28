
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
#include <vector>
#include <typeinfo> 
#include "Example.h"

using namespace std;

//Default Constructor 
Example::Example(int n)
{
	reserve(n);
}

//Overloading the << operator 
ostream &operator<<(ostream &out, const Example &e){
	out << "NULL";
	return out;
}

