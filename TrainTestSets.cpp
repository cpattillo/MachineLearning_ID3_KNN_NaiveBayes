
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
#include "TrainTestSets.h"

using namespace std;

//Default Constructor
TrainTestSets::TrainTestSets(){}

//Other contructor with data from command arguments 
TrainTestSets::TrainTestSets(const vector<string> &options) throw(logic_error)
{
	for (int i = 0; i < options.size(); i++)
	{
		if (options[i] == "-t")
		{
			train.load(options[i + 1]);
			train.setOptions(options);
		}
		else if (options[i] == "-T")
		{
			test.load(options[i + 1]);
			test.setOptions(options);
		}
	}
		
}

//Returns the training set 
DataSet TrainTestSets::getTrainingSet() const
{
	return train;
}

//returns the test set 
DataSet TrainTestSets::getTestingSet() const
{
	return test;
}

//Setting the training data 
void TrainTestSets::setTrainingSet(const DataSet &train)
{
	this->train = train;
}

//Setting the test data 
void TrainTestSets::setTestingSet(const DataSet &test)
{
	this->test = test;
}

//Sets the options of traing, test and seed information 
void TrainTestSets::setOptions(const vector<string> &options) throw (logic_error)
{
	for (int i = 0; i < options.size(); i++)
	{
		if (options[i] == "-t")
		{
			train.load(options[i + 1]);
			train.setOptions(options);
		}
		else if (options[i] == "-T")
		{
			test.load(options[i + 1]);
			train.setOptions(options);
		}
	}
}

//Printing the datasets 
void TrainTestSets::print(ostream &out) const
{
	out << getTrainingSet() << endl;
	out << getTestingSet() << endl;
}

//Overloading the << operator 
ostream &operator<<(ostream &out, const TrainTestSets &tts)
{
	tts.print(out);
	return out;
}

