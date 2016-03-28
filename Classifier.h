
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


#ifndef CLASSIFIER_H   
#define CLASSIFIER_H

#include <sstream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <vector>
#include <stdexcept>
#include <new>
#include <typeinfo> 
#include "Performance.h"
#include "DataSet.h"


using namespace std;

class Classifier{

private:

public:

	//Train the data set 
	virtual void train(const DataSet &data);

	//Classify a set of examples 
	Performance classify(const DataSet &data);
	
	//Classify an example, return a class label
	virtual int classify(const Example& example);

};

#endif 