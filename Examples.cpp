
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
#include <vector>
#include <stdexcept> 
#include <new>
#include <typeinfo> 
#include "Examples.h"

using namespace std;

//Default Constructor 
Examples::Examples(){}

//Explicit Constructor 
Examples::Examples(const Attributes &attributes) throw (logic_error)
{
	this->attributes = attributes;
}

//Parse the Examples 
void Examples::parse(istream &in) throw (logic_error)
{
	string line = "";
	string word = "";
	double x = 0.0;

	int number = attributes.getSize();

	while (getline(in, line))
	{
		std::stringstream iss(line);

		Example ex(attributes.getSize());

		for (int i = 0; i < number; i++)
		{

			if (iss >> word)
			{
				if ((typeid(*(attributes.get(i))) == typeid(NominalAttribute)))
				{
					NominalAttribute* temp = static_cast<NominalAttribute *>(attributes.get(i));
					ex.push_back((*temp).getIndex(word));
				}
				else
				{
					double d = 0.0;
					d = std::stod(word);
					ex.push_back(d);
				}
			}

		} //end for

		push_back(ex);//Push back example in vector 

	}//end while 

}

//Set the attributes 
void Examples::setAttributes(const Attributes &attributes) throw (logic_error)
{
	this->attributes = attributes;
}

//Prints out examples 
void Examples::print(ostream & out) const
{

	for (int i = 0; i < size(); i++)
	{
		for (int j = 0; j < attributes.getSize(); j++)
		{
			if (typeid (*(attributes.get(j))) == typeid(NominalAttribute))
			{
				NominalAttribute* temp = dynamic_cast<NominalAttribute *>(attributes.get(j));
				int t = int(at(i).at(j));
				string c = (*temp).getValue(t);
				out << c << " ";
			}
			else
			{
				out << at(i).at(j) << " ";

			}
		}

		out << endl;
	}

}//End print 
 
//Overloading the << operator 
ostream &operator<<(ostream &out, const Examples &e)
{
	e.print(out);
	return out;
}

