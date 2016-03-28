
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
#include <new>
#include <vector>
#include <typeinfo> 
#include <math.h>
#include "DataSet.h"

using namespace std;

//Internal file parsing method 
void DataSet::parse(istream &in) throw (logic_error)
{
	string find = ""; //temp string for parsing 
	string att = "";  //temp string for parsing


	//Extracting the dataset
	while (getline(in, find))
	{
		if (!find.empty())
		{
			std::stringstream parser(find); //stringstream object to parse each line 

			parser >> att;

			if (att == "@dataset")
			{
				parser >> att;
				this->name = att;
			}
			else if (att == "@attribute")
			{
				attributes.parse(parser);
			}
			else if (att == "@examples")
			{
				examples.setAttributes(attributes);
				getline(in, find);
				examples.parse(in);
			}
		}
	}

}

//Default Constructor
DataSet::DataSet()
{
	name = "";
	seed = 2026875034;
}

//Other constructor making a copy of the attributes 
DataSet::DataSet(const Attributes &attributes) throw (logic_error)
{
	name = "";
	this->attributes = attributes;
	examples.setAttributes(attributes);
	seed = 2026875034;
	attributeCounts.resize(attributes.get(attributes.getClassIndex())->getSize(),0);
}

//Adds the examples of the specified data set to this data set.
void DataSet::add(const DataSet &dataset) throw  (logic_error)
{
	this->examples = dataset.examples;
}

//Adds an example to the dataset 
void DataSet::add(const Example &example) throw (logic_error)
{
	examples.push_back(example);
	attributeCounts[example[attributes.getClassIndex()]]++;
}

//Gets the Attributes for this DataSet
Attributes DataSet::getAttributes() const
{
	return attributes;
}

//Returns examples 
Examples DataSet::getExamples() const
{
	return examples;
}

//returns the seed 
long DataSet::getSeed() const
{
	return seed;
}

//Returns tree if have NominalAttributes
bool DataSet::getHasNominalAttributes() const
{
	return attributes.getHasNominalAttributes();
}

//Returns true is have Numeric Attributes 
bool DataSet::getHasNumericAttributes() const
{
	return attributes.getHasNumericAttributes();
}

//Loads the file to be processed
void DataSet::load(string filename) throw (logic_error)
{

	ifstream File(filename.c_str());

	if (!File)
	{
		File.close();
		cout << "Input file failed to open" << endl;
	}
	else
	{
		parse(File);
	}

}

//Sets the opinion 
void  DataSet::setOptions(const vector<string> &options) throw (logic_error)
{
	for (int i = 0; i < options.size(); i++)
	{
		if (options[i] == "-s")
		{
			seed = stoi(options[i + 1]);
		}
	}
}

//Setting the seed 
void DataSet::setSeed(long seed)
{
	this->seed = seed;
}

//Overloading the << operator 
ostream &operator<<(ostream &out, const DataSet &ds)
{
	out << endl;
	out << ds.attributes << endl;
	out << ds.examples << endl;

	return out;
}

//Calculating entropy of an attribute split 
double DataSet::entropy(int attribute) const 
{
	//Count the obervations for each domain value of an attribute
	vector<vector<double>> counts(attributes.get(attributes.getClassIndex())->getSize(), vector<double>(attributes.get(attribute)->getSize(),0));

	//Counting observations
	for (int i = 0; i < examples.size(); i++)
	{
		counts[examples.at(i)[attributes.getClassIndex()]][examples.at(i)[attribute]]+=1;
	}
	
	
	double entropy_total = 0.0; 

	//Going through each domain 
	for (int i = 0; i < attributes.get(attribute)->getSize(); i++)
	{
		double sum_column = 0.0; 
		double entropy = 0.0;

		//Cycling through the rows 
		for (int j = 0; j < attributes.get(attributes.getClassIndex())->getSize(); j++)
		{
			sum_column += counts[j][i]; 
		}

		for (int k = 0; k < attributes.get(attributes.getClassIndex())->getSize(); k++)
		{
			double p = 0.0;
			if (sum_column != 0)
			{
				p = (counts[k][i]) / sum_column;

			}
			if (p != 0)
			{
				entropy += -p * log2(p);
			}
		}

		entropy *= sum_column / examples.size();
		entropy_total += entropy; 
	}

	return entropy_total; 

}

//Calculating the Entropy of a DataSet
double DataSet::entropySet() const 
{

	//Keeps track of observations for each class attribute
	vector <double> terms(attributes.get(attributes.getClassIndex())->getSize(),0);

	double entropy = 0.0; 

	for (int i = 0; i < examples.size(); i++)
	{
		terms[examples.at(i).at(attributes.getClassIndex())]++;
	}

	for (int i = 0; i < terms.size(); i++)
	{
		double p = terms[i] / examples.size(); 
		
		if (p != 0)
		{
			entropy += -1*(p * log2(p));
		}
	}
	
	return entropy; 
}

//Returns the gain of each split
double DataSet::gain(int attribute) const
{
	return entropySet() - entropy(attribute);
}

//Decides best attribute to make a split on the data 
int DataSet::bestAttribute() const
{
	double max_gain = -1;
	int max_index = -1; 

	for (int i = 0; i < attributes.getSize()-1; i++)
	{
		if (gain(i) > max_gain)
		{
			max_gain = gain(i);
			max_index = i;
		}

	}

	return max_index; 

}

//Return example
int DataSet::getClassLabel() const 
{
	return examples.at(0)[attributes.getClassIndex()];
}

//Tests to see if the data set is homogeneous
bool DataSet::isHomogeneous() const
{

	//Checks entropy of the DataSet
	if (entropySet() > 0)
	{
		return false;
	}
	else
	{

		return true;
	}
}

//Spits the data set by attribute 
vector<DataSet> DataSet::split(int attribute) const 
{
	vector<DataSet> data(attributes.get(attribute)->getSize(), DataSet(attributes));

	for (int i = 0; i < examples.size(); i++)
	{
		(data[examples.at(i).at(attribute)]).add(examples.at(i));
	}

	return data;
}

//Checks to see of a DataSet is empty
bool DataSet::empty()
{
	if (examples.size() == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}


//Votes on the majority class attribute for a given DataSet
int DataSet::majority() const
{
	vector <double> terms(attributes.get(attributes.getClassIndex())->getSize(), 0);

	for (int i = 0; i < examples.size(); i++)
	{
		terms[examples.at(i)[attributes.getClassIndex()]]++;
	}

	int max_val = -1;
	int index = -1;
	for (int i = 0; i < terms.size(); i++)
	{
		if (terms[i] > max_val)
		{
			max_val = terms[i];
			index = i;
		}
	}

	return index;
}


//Adding examples to the data set
void DataSet::addData(DataSet realData, vector<int> &counts, int& fold)
{
	Examples examples(realData.getAttributes());

	for (int i = 0; i < counts.size(); i++)
	{
		if (counts[i] == fold)
		{
			add((realData.getExamples()[i]));
		}
	}
}