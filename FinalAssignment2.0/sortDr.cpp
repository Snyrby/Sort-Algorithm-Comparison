// This program is a sorting algorithm tester.

// Input are sorting algorithm names plus Refresh for resetting the
//   values to be sorted to their previous values and Reinitialize for
//   creating a new set of values.

/*****************************************************************************************
*  Program Name: FinalAssignment
*  Created Date: 5/21/19
*  Created By: Shawn Ruby
*  Purpose: Input are sorting algorithm names plus Refresh for resetting the values to be sorted to their previous values and Reinitialize for creating a new set of values.
*  Acknowledgements: None
*****************************************************************************************/

#include <fstream>
#include <iostream>
#include "Sort.h"


typedef int ItemType;
using std::ifstream;
using std::ofstream;
using std::cerr;
using std::endl;
using std::exception;

// SIZE should be a multiple of 10.

int main()
{
	try
	{
		ifstream inFile; //Get an input file of data to process
		inFile.open("100Words.txt"); //Get file ready to read input

		ofstream outFile; //Get an output file to write data out to
		outFile.open("Output.txt"); //Get file ready to write data to

		SortAlgorithm OneHundredNumbers;
		SortAlgorithm OneThousandNumbers;
		OneHundredNumbers.InitValues(inFile);
		OneHundredNumbers.Print(outFile);
		OneHundredNumbers.CopyValues();
		OneHundredNumbers.SortValues(outFile);
		inFile.close(); //Need to close our input and output files

		inFile.open("1000Words.txt");
		OneThousandNumbers.InitValues(inFile);
		OneThousandNumbers.Print(outFile);
		OneThousandNumbers.CopyValues();
		OneThousandNumbers.SortValues(outFile);
		inFile.close();
		outFile.close();
	}
	catch (exception& ex) //Catch any errors that occure and display them in the console to the user
	{
		cerr << "An error occured: " << ex.what() << endl;
		system("pause");
		return 1;
	}

	return 0;
}

    
