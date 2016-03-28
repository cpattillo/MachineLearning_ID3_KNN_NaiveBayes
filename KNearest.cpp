
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

#include "kNN.h"

using namespace std;

//Calulating the mismatches between obervations and the training set 
int kNN::distance_c(const Example &ex)
{
	int mismatches = 0;
	int max_in_min = -1;
	double classLabel = -1;

	//out loop is looping through each example in the data set
	for (int j = 0; j < data.getExamples().size(); j++)
	{
		//comparing the indiviudal element 
		for (int i = 0; i < ex.size(); i++)
		{
			if ((i != data.getAttributes().getClassIndex()) && (ex[i] != data.getExamples()[j][i]))
			{
				mismatches++;
			}
		}//end inner for

		//check to see if the distance vector is fully loaded 
		if (distance.size() < k_nearest)
		{
			distance.push_back(mismatches);
			label.push_back(ex[data.getAttributes().getClassIndex()]);
			max_in_min = scan(distance);
		}
		else
		{
			//scanning to replace 
			for (int k = 0; k < distance.size(); k++)
			{

				if (mismatches < max_in_min)
				{
					max_in_min = mismatches;
					distance[k] = max_in_min;
					classLabel = ex[data.getAttributes().getClassIndex()];
				}
			}
		}

	}//end large for
	return vote(label);

}

//Vote for class label
int kNN::vote(vector<int> labels)
{
	int count1 = 0;
	int count2 = 0;

	for (int i = 0; i < labels.size(); i++)
	{
		if (labels[i] == 0)
		{
			count1++;
		}
		else
		{
			count2++;
		}
	}

	labels.clear();
	distance.clear();

	if (count1 > count2)
	{
		return 0;
	}

	return 1;

}

//Default Constructor 
kNN::kNN()
{
	k_nearest = 1;
}

//Constructor 
kNN::kNN(const vector<string> &options) throw (logic_error)
{
	for (int i = 0; i < options.size(); i++)
	{
		if (options[i] == "-k")
		{
			k_nearest = stoi(options[i + 1]);
		}
	}

}

//train training set
void kNN::train(const DataSet& dataset)
{
	this->data = dataset;
}

//Classify an example
int kNN::classify(const Example &ex)
{
	return distance_c(ex);
}

//Returns the max value in distance vector 
int kNN::scan(vector<int> distances)
{
	int max_val = distance[0];

	for (int i = 0; i < distance.size(); i++)
	{
		if (distance[i] > max_val)
		{
			max_val = distance[i];
		}
	}

	return max_val;
}
