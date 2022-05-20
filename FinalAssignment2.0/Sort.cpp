#include "Sort.h"
#include <iostream>
#include <string>

typedef int ItemType;
using std::cerr;
using std::cin;
using std::cout;
using std::endl;
using std::string;


//loops through input file and puts each number into an array
void SortAlgorithm::InitValues(ifstream& inFile)
// initializes the values array with random integers from 0 to 99
{
	try
	{
		int index = 0;
		int CurrentNumber;

		while (inFile >> CurrentNumber)
		{
			values[index] = CurrentNumber;
			index += 1;
		}
		Length = index;
	}
	catch (string ex)
	{
		cerr << "An error occurred. " << ex;
		system("pause");
	}	
}

//books code
void SortAlgorithm::Print(ofstream& outFile)
{
	for (int i = 0; i < 35; i++)
	{
		outFile << "-";
	}
	outFile << endl;
	for (int count = 0; count < Length; count = count + 10)
		outFile << values[count] << ", " << values[count + 1] << ", " << values[count + 2] << ", "
		<< values[count + 3] << ", " << values[count + 4] << ", " << values[count + 5] << ", "
		<< values[count + 6] << ", " << values[count + 7] << ", " << values[count + 8]
		<< ", " << values[count + 9] << endl << endl; 
	for (int i = 0; i < 35; i++)
	{
		outFile << "-";
	}
	outFile << endl;
}


//copies the initial values into another array
void SortAlgorithm::CopyValues()
{
	for (int count = 0; count < Length; count++)
		copyValues[count] = values[count];
}

// refreshes the values with the initial values
void SortAlgorithm::RefreshValues()
{
	for (int count = 0; count < Length; count++)
		values[count] = copyValues[count];
}

//calls for each sort and prints the results, then refreshes with the initial values
void SortAlgorithm::SortValues(ofstream& outFile)
{
	//resets the swap and comparison counter counter
	NumberOfSwap[0] = 0, NumberOfSwap[1] = 0;
	BubbleSort(values, Length, NumberOfSwap);
	outFile << "Results from " << Length << " Number BubbleSort: " << endl << "Times Swapped: " << NumberOfSwap[0] << "\nTimes Compared: " << NumberOfSwap[1] << endl;
	Print(outFile);
	RefreshValues();
	
	NumberOfSwap[0] = 0, NumberOfSwap[1] = 0;
	SelectionSort(values, Length, NumberOfSwap);
	outFile << "Results from " << Length << " Number SelectionSort: " << endl << "Times Swapped: " << NumberOfSwap[0] << "\nTimes Compared: " << NumberOfSwap[1] << endl;
	Print(outFile);
	RefreshValues();

	NumberOfSwap[0] = 0, NumberOfSwap[1] = 0;
	InsertionSort(values, Length, NumberOfSwap);
	outFile << "Results from " << Length << " Number InsertionSort: " << endl << "Times Swapped: " << NumberOfSwap[0] << "\nTimes Compared: " << NumberOfSwap[1] << endl;
	Print(outFile);
	RefreshValues();

	NumberOfSwap[0] = 0, NumberOfSwap[1] = 0;
	MergeSort(values, 0, Length - 1, NumberOfSwap, Length);
	outFile << "Results from " << Length << " Number MergeSort: " << endl << "Times Swapped: " << NumberOfSwap[0] << "\nTimes Compared: " << NumberOfSwap[1] << endl;
	Print(outFile);
	RefreshValues();

	NumberOfSwap[0] = 0, NumberOfSwap[1] = 0;
	QuickSort(values, 0, Length - 1, NumberOfSwap);
	outFile << "Results from " << Length << " Number QuickSort: " << endl << "Times Swapped: " << NumberOfSwap[0] << "\nTimes Compared: " << NumberOfSwap[1] << endl;
	Print(outFile);
	RefreshValues();

	NumberOfSwap[0] = 0, NumberOfSwap[1] = 0;
	HeapSort(values, Length, NumberOfSwap);
	outFile << "Results from " << Length << " Number HeapSort: " << endl << "Times Swapped: " << NumberOfSwap[0] << "\nTimes Compared: " << NumberOfSwap[1] << endl;
	Print(outFile);
	RefreshValues();
	
}