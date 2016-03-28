
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


#ifndef KNN_H   
#define KNN_H

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


using namespace std;

class kNN : public Classifier{
private: 

	vector<int> distance; // holds the number of mismatches 
	vector<int> label;    // holds the class label 

	int k_nearest; //Keeps track of the K nearest neighbor 

	DataSet data; //DataSet object 

	//Calculating the number of mismatches
	int distance_c(const Example &ex);

	//voting on the mismatches for k > 1
	int vote(vector<int> labels);

public:

	//Default
	kNN();

	//Constructor 
	kNN(const vector<string> &options) throw (logic_error);

	//Train the DataSet
	void train(const DataSet& dataset);

	//Classify an example
	int classify(const Example &ex);
	
	//Returns the max value in distance vector 
	int scan(vector<int> distances);

};

#endif