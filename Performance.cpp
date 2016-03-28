
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
#include<math.h>
#include "Performance.h"

using namespace std;

//Print the Performance obj
void Performance::print(ostream& os) const
{
	os << "Accuracy rate of: " << accuracy << endl;
	os << "With a Stand Deviation of: " << standard_dev << endl;
}

//Other Constructor 
Performance::Performance(double accuracyVal)
{
	accuracy = accuracyVal;
}

// Returning the accuracy
double Performance::getAccuracy()
{
	return accuracy;
}

//Returning the Standard Deviation
void Performance::set_stand_dev(double stand)
{
	standard_dev = stand;
}

//Overloading the << operator 
ostream &operator<<(ostream &out, const Performance &per)
{
	per.print(out);
	return out;
}

//Calculating the accuracy
void Performance::calc_accuracy(vector<double> accuracyVec)
{
	double sums = 0.0;

	for (int i = 0; i < accuracyVec.size(); i++)
	{
		sums += accuracyVec[i];
	}

	//cout << "In calc accuracy: it is: " << sums << endl;
	//cout << "Divide " << sums / accuracyVec.size() << endl;
	accuracy = (sums / accuracyVec.size()) * 100;
	//cout << "What is acc: " << accuracy << endl;
}

//Calculating the standard deviation
void Performance::calc_standard_dev(vector<double> accuracyVec)
{
	double mean = accuracy / 100;
	double sum_dev = 0.0;

	for (int i = 0; i < accuracyVec.size(); ++i)
	{
		sum_dev += (pow((accuracyVec[i] - mean), 2));
	}

	standard_dev = sqrt(sum_dev / accuracyVec.size());

}

