
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

#include "nb.h"

using namespace std;

//Building the 3D vector of counts
void NB::loadVector(const DataSet & data)
{
	class_dem = 0.0;
	class_rep = 0.0;
			
	for (int i = 0; i < data.getAttributes().getSize() - 1; i++)
	{
		vector < vector<int>> myAttribute;

		//create all the vectors and push them back 
		for (int j = 0; j < data.getAttributes().get(i)->getSize(); j++)
		{
			vector<int> myClassCounts;
			for (int k = 0; k < 2; k++)
			{
				myClassCounts.push_back(1);
			}

			myAttribute.push_back(myClassCounts);
		}

		myVector.push_back(myAttribute);
	}

}

//Adding counts to 3D vector to capture the training set examples
void NB::loadCounts(const Example &observation)
{
	for (int i = 0; i < observation.size() - 1; i++)
	{
		
		int classIndex = observation.at(observation.size() - 1);
		myVector[i][observation[i]][classIndex] = myVector[i][observation[i]][classIndex] + 1;

	}
	if (observation.at(observation.size() - 1) == 1)
	{
		class_rep += 1;
	}
	else
	{
		class_dem += 1;
	}
	
}

//Default Constructor
NB::NB()
{
	double class_dem = 0;
	double class_rep = 0;
}

//Loading the training set examples
void NB::train(const DataSet & data)
{
	loadVector(data);
	
	for (int i = 0; i < data.getExamples().size(); i++)
	{
		loadCounts(data.getExamples().at(i));
	}

}

//Classify an example
int NB::classify(const Example &ex)
{
	vector<int> dem_count;
	vector<int> rep_count;

	double numerator = 1.0;
	double denominator = 1.0;
	double probability = 0.0;
	double probability_class = 0.0;
	double probability_class2 = 0.0;
	double num_rep = 1.0;
	double dem_rep = 1.0;
	double prob_rep = 0.0;
	double p1_rep = 0.0;
	double p2_rep = 0.0;

	for (int i = 0; i < ex.size() - 1; i++)
	{
		dem_count.push_back(myVector[i][ex.at(i)][0]);
		rep_count.push_back(myVector[i][ex.at(i)][1]);
	}

	for (int j = 0; j < dem_count.size(); j++)
	{
		probability_class = (class_dem / (class_dem + class_rep));
		numerator *= ((dem_count[j]) / class_dem) / probability_class;
	}
	
	numerator *= probability_class;

	for (int i = 0; i < rep_count.size(); i++)
	{
		probability_class2 = ((class_rep) / (class_rep + class_dem));
		denominator *= ((rep_count[i]) / class_rep) / probability_class2;
	}

	denominator *= probability_class2;
	denominator += numerator;

	probability = numerator / denominator;

	//Calcualting opposite Class Attribute
	for (int j = 0; j < rep_count.size(); j++)
	{
		p1_rep = (class_rep / (class_dem + class_rep));
		num_rep *= ((rep_count[j]) / class_rep) / p1_rep;
	}
	
	num_rep *= p1_rep;

	for (int i = 0; i < dem_count.size(); i++)
	{
		p2_rep = ((class_dem) / (class_rep + class_dem));
		dem_rep *= ((dem_count[i]) / class_dem) / p2_rep;
	}

	dem_rep *= p2_rep;

	dem_rep += num_rep;

	prob_rep = num_rep / dem_rep;

	if (probability > prob_rep)
	{
			return 0;
	}
	else
	{
		return 1;
	}

}

