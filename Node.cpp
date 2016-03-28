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

#include "Node.h"

using namespace std;

//Default Constructor
Node::Node()
{
	classLabel = -1;
	attribute = 0;
}

//Destructor
Node::~Node()
{
}

//Setting Class Label
void Node::setClassLabel(int label)
{
	classLabel = label;
}

//Adding children nodes
void Node::addChildren(Node* node)
{
	children.push_back(node);
}

//
void Node::setAttribute(int att)
{
	attribute = att;
}

//Getting the classLabel
int Node::getLabel() 
{
	return classLabel;
}

//Getting the attribute 
int Node::getAttribute() 
{
	return attribute; 
}

//Getting the children
vector<Node*> Node::getChildren() 
{
	return children;
}

