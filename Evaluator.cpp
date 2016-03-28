
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
#include <algorithm>   
#include <math.h>
#include "Evaluator.h"

using namespace std;


//Default Constructor 
Evaluator::Evaluator(){}

//Returns a performance object to test the classifer 
Performance Evaluator::evaluator(Classifier * classifier, const vector<string> &options) throw(logic_error)
{

	//Check and evaluate the options string. if there is an p or a T call those methods and return those methods 

	for (int i = 0; i < options.size(); i++)
	{
		if (options[i] == "-p")
		{
			return holdout(classifier, options);
		}
		if (options[i] == "-T")
		{
			return testSet(classifier, options);
		}
		
	}

	return k_cross(classifier, options);


}//end evaluator method 

//Holdout Method 
Performance Evaluator::holdout(Classifier * classifier, const vector<string> & options) throw(logic_error)
{
	double p = 0.0;
	vector<double> accuracy_vals;

	for (int i = 0; i < options.size(); i++)
	{
		if (options[i] == "-p")
		{
			p = stod(options[i + 1]);
		}
	}

	TrainTestSets data(options); //declaring the dataset 

	vector<int> random_ints;

	int a = ceil(p * (data.getTrainingSet().getExamples().size()));
	int b = (data.getTrainingSet().getExamples().size()) - a; 

	for (int i = 0; i < data.getTrainingSet().getExamples().size(); i++)
	{
		if (i <= a)
		{
			random_ints.push_back(a);
		}
		else
		{
			random_ints.push_back(b);
		}
	}

	std::random_shuffle(random_ints.begin(), random_ints.end());

	DataSet TrainData(data.getTrainingSet().getAttributes());
	DataSet TestData(data.getTrainingSet().getAttributes());
	TrainData.addData(data.getTrainingSet(), random_ints, a);
	TestData.addData(data.getTrainingSet(), random_ints, b);


	classifier->train(TrainData);
	accuracy_vals.push_back(classifier->classify(TestData).getAccuracy());

	Performance performance;
	performance.calc_accuracy(accuracy_vals);
	performance.calc_standard_dev(accuracy_vals);
	return performance;
	
}

//Evaluates the performance on a separate TestSet
Performance Evaluator::testSet(Classifier * classifier, const vector<string> &options) throw(logic_error)
{
	vector<double> accuracy_vals;

	string testing; 
	for (int i = 0; i < options.size(); i++)
	{
		if (options[i] == "-T")
		{
			testing = options[i + 1];
		}
	}

	TrainTestSets data(options);


	classifier->train(data.getTrainingSet());
	accuracy_vals.push_back(classifier->classify(data.getTestingSet()).getAccuracy());

	Performance performance;
	performance.calc_accuracy(accuracy_vals);
	performance.calc_standard_dev(accuracy_vals);
	return performance;


}

//Evaluates DataSet on k fold cross validation 
Performance Evaluator::k_cross(Classifier * classifier, const vector<string> &options) throw(logic_error)
{
	int folds = 0;
	double total_accuracy = 0.0;
	double accuracy = 0.0;
	vector<double> accuracy_vals;

	for (int i = 0; i < options.size(); i++)
	{
		if (options[i] == "-x")
		{
			folds = stoi(options[i + 1]);
		}


	}

	if (folds == 0)
	{
		folds = 10;
	}

	TrainTestSets data(options); //declaring the dataset 


	//Building the parallel vector of randomized integers, representing each fold. 
	vector<int> random_ints;

	srand(100);

	for (int i = 0; i < data.getTrainingSet().getExamples().size(); i++)
	{
		random_ints.push_back(rand() % folds);
	}
	
	//Dividing the partitioning 
	for (int i = 0; i < folds; i++)
	{
		DataSet TrainData(data.getTrainingSet().getAttributes());
		DataSet TestData(data.getTrainingSet().getAttributes());

		int count = 0;

		for (int j = 0; j < folds; j++)
		{

			if (i != j)
			{
				TrainData.addData(data.getTrainingSet(), random_ints, j);

			}
			else
			{
				TestData.addData(data.getTrainingSet(), random_ints, j);
			}
		}//end inner for

		classifier->train(TrainData);
		accuracy_vals.push_back(classifier->classify(TestData).getAccuracy());

	}//end large for

	Performance performance;
	performance.calc_accuracy(accuracy_vals);
	performance.calc_standard_dev(accuracy_vals);
	return performance;

}
