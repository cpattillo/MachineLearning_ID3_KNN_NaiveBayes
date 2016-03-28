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

#ifndef NODE_H
#define NODE_H

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

using namespace std;

class Node{

private:

	int classLabel;				//Class label 
	vector<Node*> children;		//Holds pointers to children
	int attribute;				//Attribute in Node

public:

	//Default Constructor
	Node(); 

	//Destructor
	~Node();
	
	//Setting the Class Label
	void setClassLabel(int label); 

	//Adding children to vector 
	void addChildren(Node* node);

	//Setting the class attribute
	void setAttribute(int att);

	//Getting class label 
	int getLabel();

	//Getting attribute
	int getAttribute();

	//Accessing the vector of nodes 
	vector<Node*> getChildren();
};

#endif 