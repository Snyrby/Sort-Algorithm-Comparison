#ifndef SORT_H
#define SORT_H

#include <fstream>
#include "SelectionSort.h"
#include "InsertionSort.h"
#include "MergeSort.h"
#include "QuickSort.h"
#include "BubbleSort.h"
#include "HeapSort.h"
#include "Swap.h"

using std::ifstream;
using std::ofstream;



class SortAlgorithm
{
private:
	
public:
	void Print(ofstream&);	// Prints array
	void InitValues(ifstream&);	// Creates random array 
	void CopyValues();	// Makes a copy of random array
	void SortValues(ofstream&);
	void RefreshValues();
	ItemType NumberOfSwap[2];
	ItemType copyValues[SIZE];
	ItemType values[SIZE];
	int Length;
};
#endif
