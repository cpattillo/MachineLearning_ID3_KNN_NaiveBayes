
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

#include "Performance.h"
#include "Attribute.h"
#include "Attributes.h"
#include "Examples.h"
#include "Example.h"
#include "AttributeFactory.h"
#include "DataSet.h"
#include "NominalAttribute.h"
#include "NumericAttribute.h"
#include "TrainTestSets.h"
#include "Evaluator.h"
#include "Classifier.h"
#include "kNN.h"
#include "nb.h"
#include "ID3.h"


using namespace std;


int main(int argc, const char *argv[])
{

	try{

		string badArgMessage = "";

		//Checks to make command line has an argument 
		if (argc < 2)
		{
			badArgMessage = "There is no argument for the file";
			throw badArgMessage;
		}
		else
		{
			char t;
			char c;
			char T;
			string s = "";
			string FileName = "";
			string TestSet = "";
			int seed = 0;
			vector <string> options;

			while (--argc > 0)
			{
				options.push_back(*++argv);
				options.push_back(*++argv);
				argc--;
			}

			cout << endl;
			Evaluator Evaluator;
			Classifier *classifier = new kNN(options);
			Performance performance = Evaluator.evaluator(classifier, options);
			cout << performance << endl;
			
			//Output filling 
			string outputFile = "";
			std::ofstream outFile;


		}



	}//end try block 

	catch (string errorMessage)
	{
		cout << errorMessage << endl;
	}

	return 0;
}


