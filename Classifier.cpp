
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
#include <vector>
#include <stdexcept>
#include <new>
#include <typeinfo> 
#include "Classifier.h"

using namespace std;

//Training the DataSet
void Classifier::train(const DataSet &data){}

//Classify a set of examples
Performance Classifier::classify(const DataSet &data)
{
	int prediction = 0;
	double sums = 0.0;
	double accuracy = 0.0;

	for (int i = 0; i < data.getExamples().size(); i++)
	{
		prediction = classify(data.getExamples()[i]);

		if (prediction == data.getExamples()[i].at(data.getAttributes().getClassIndex()))
		{
			sums++;
		}

	}
	
	accuracy = sums / (data.getExamples().size());
	Performance p(accuracy);
	return p;
}

//Classify each example, return class attribute
int Classifier::classify(const Example& example)
{
	return 0;
}

