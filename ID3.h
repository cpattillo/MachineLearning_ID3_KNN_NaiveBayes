
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

#ifndef ID3_H
#define ID3_H

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
#include "Node.h"

using namespace std;

class ID3 :public Classifier{
private:
	Node * root;
	void training(Node * &node, const DataSet& ds);
	int classifying(Node* node, const Example& ex);

public:
	//Default
	ID3();

	//Destructor
	~ID3();

	//Store the training examples in the model 
	void train(const DataSet& dataset);

	//classifies a specific element
	int classify(const Example &ex);

};




#endif  
