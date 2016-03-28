
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

#include "ID3.h"

//Building a decision tree
void ID3::training(Node * &node, const DataSet& ds)
{
	//Base Case, reached a pure and homogeneous set
	if (ds.isHomogeneous())
	{
		node->setClassLabel(ds.getClassLabel());
		return;
	}
	else if (ds.getExamples().size() == 0)					//Outputs that there is nothing in the DataSet
	{
		cout << "Error no more examples to split" << endl;
	}
	else
	{
		//Finds the best attribute to split on  
		int bestAttribute = ds.bestAttribute();
		node->setAttribute(bestAttribute);

		//Vector of data sets divided by the domina values of an attribute 
		vector<DataSet>splits = ds.split(bestAttribute);

		//Traversing the splits vector 
		for (int i =0; i < splits.size(); i++)
		{
			node->addChildren(new Node());
			
			if (splits[i].empty())
			{
				node->getChildren().at(i)->setClassLabel(ds.majority());
			}
			
			else
			{
				training(node->getChildren().at(i), splits.at(i));
			}
			
		}
		
	}

}



//Default Constructor 
ID3::ID3()
{
	root = new Node();
}

//Destructor
ID3::~ID3()
{
	delete root;
}

//Store the training examples in the model 
void ID3::train(const DataSet& dataset)
{
	training(root, dataset);
}

//Classifies an examples
int ID3::classifying(Node* node, const Example& ex)
{
	//If a leaf node then return lead node, else recurse on the subtree
	if (node->getChildren().empty())
	{
		return node->getLabel();
	}
	else
	{
		return classifying(node->getChildren().at(ex[node->getAttribute()]), ex);
	}

}

//classifies a specific element
int ID3::classify(const Example &ex)
{
	return classifying(root, ex);
}

