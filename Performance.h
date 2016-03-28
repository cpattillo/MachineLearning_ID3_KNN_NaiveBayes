
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


#ifndef PERFORMANCE_H   
#define PERFORMANCE_H

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


using namespace std;

class Performance{

	//Overloading the << operator 
	friend ostream &operator<<(ostream &out, const Performance &per);

private:  

	double accuracy;  //the accuracy 
	double standard_dev; //the standard deviation 

	//Printing the Performance object 
	void print(ostream& os = cout) const; 

public:

	//Other Constructor 
	Performance(double accuracyVal=0);

	//Returning the accuracy 
	double getAccuracy();

	//Returning the standard deviation 
	void set_stand_dev(double stand);

	//Calculating the accuracy
	void calc_accuracy(vector<double> accuracy); 

	//Calculating the standard deviation
	void calc_standard_dev(vector<double> accuracy);

};

#endif