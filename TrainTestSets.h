
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


#ifndef TRAINTESTSETS_H
#define TRAINTESTSETS_H

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
#include "Attribute.h"
#include "Attributes.h"
#include "Examples.h"
#include "DataSet.h"


using namespace std;

class TrainTestSets{

	//Overriding the << operator 
	friend ostream &operator<<(ostream &out, const TrainTestSets &tts);

protected:
	DataSet train;
	DataSet test;

public:

	//Default Constructor
	TrainTestSets();

	//Other contructor with data from command arguments 
	TrainTestSets(const vector<string> &options) throw(logic_error);
	
	//Returns the training set 
	DataSet getTrainingSet() const;

	//returns the test set 
	DataSet getTestingSet() const;

	//Setting the training data 
	void setTrainingSet(const DataSet &train);

	//Setting the test data 
	void setTestingSet(const DataSet &test);

	//Sets the options of traing, test and seed information 
	void setOptions(const vector<string> &options) throw (logic_error);

	//Printing the dataset
	void print(ostream &out) const;

};

#endif
