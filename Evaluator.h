
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


#ifndef EVALUATOR_H   
#define EVALUATOR_H

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
#include <math.h>

#include "Performance.h"
#include "Classifier.h"
#include "TrainTestSets.h"
#include "DataSet.h"
#include "Examples.h"


using namespace std;

class Evaluator{
	
public:    

	//Default Constructor 
	Evaluator();

	//Evaluating the performance of a classifier 
	Performance evaluator(Classifier * classifier, const vector<string> &options) throw(logic_error);
	
	//K fold cross validation
	Performance k_cross(Classifier * classifier, const vector<string> &options) throw(logic_error);

	//Holdout method
	Performance holdout(Classifier * classifier, const vector<string> &options) throw(logic_error);

	//Separate TestSet
	Performance testSet(Classifier * classifier, const vector<string> &options) throw(logic_error);
};

#endif