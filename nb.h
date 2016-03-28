
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


#ifndef NB_H   
#define NB_H

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
#include <algorithm>   

#include "Performance.h"
#include "Classifier.h"
#include "TrainTestSets.h"
#include "DataSet.h"
#include "Examples.h"
#include "Attributes.h"


using namespace std;

class NB : public Classifier{

private:

	vector<vector<vector<int>>> myVector; //3D vector of counts 
	double class_dem; //Class Attribute 1
	double class_rep; //Class Attribute 2

	//Building the 3D vector
	void loadVector(const DataSet & data);

	//Loading the counts into vector 
	void loadCounts(const Example &observation);

public:

	//Default Constructor 
	NB();
	
	//Loading the training set
	void train(const DataSet & data);

	//Classify each example
	int classify(const Example &ex);
	

};
#endif 