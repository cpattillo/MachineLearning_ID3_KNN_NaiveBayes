
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


#ifndef DATASET_H
#define DATASET_H

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
#include "Example.h"


using namespace std;


class DataSet{

	//Prints like the file, so name, attributes, and then examples 
	friend ostream &operator<<(ostream &out, const DataSet &ds);

protected:

	string name; //Name of file 
	Attributes attributes; //Attributes 
	Examples examples;  //Examples 
	long seed; //seed for randomization

	vector<int> attributeCounts;

	//Internal file parsing method 
	void parse(istream &in) throw (logic_error);
	

public:

	//Default Constructor
	DataSet();

	//Other constructor making a copy of the attributes 
	DataSet(const Attributes &attributes) throw (logic_error);

	//Adds the examples of the specified data set to this data set.
	void add(const DataSet &dataset) throw  (logic_error);

	//Adds an example to the dataset 
	void add(const Example &example) throw (logic_error);

	//Gets the Attributes for this DataSet
	Attributes getAttributes() const;

	//Returns examples 
	Examples getExamples() const;

	//returns the seed 
	long getSeed() const;

	//Returns tree if have NominalAttributes
	bool getHasNominalAttributes() const;

	//Returns true is have Numeric Attributes 
	bool getHasNumericAttributes() const;

	//Loads the file to be processed
	void load(string filename) throw (logic_error);

	//Sets the opinion 
	void  setOptions(const vector<string> &options) throw (logic_error);

	//Setting the seed 
	void setSeed(long seed);

	//Calculating entrophy 
	double entropy(int attribute) const; 

	//Calculating the entrophy of set
	double entropySet() const;

	//Calculating the gain of each split 
	double gain(int attribute) const; 

	//Get the best attribute to split on 
	int bestAttribute() const;

	//Return the class label
	int getClassLabel () const;

	//Splits the dataSet on a given attribute
	vector<DataSet> split(int attribute) const;

	//Checks to see if a DataSet is homogeneous
	bool isHomogeneous() const;

	//Checks to see if DataSet is empty
	bool empty();

	//Calculates the majority class label for a DataSet
	int majority() const;


	//Adding examples to a data set
	void addData(DataSet realData, vector<int> &counts, int &fold);

};


#endif
