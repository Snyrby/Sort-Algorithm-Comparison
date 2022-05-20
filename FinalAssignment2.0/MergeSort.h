#ifndef MERGESORT_H
#define MERGESORT_H

#include "Swap.h"

template<class ItemType>
void Merge(ItemType values[], int leftFirst, int leftLast,
	int rightFirst, int rightLast, ItemType NumberOfSwap[], int Length)
	// Post: values[leftFirst]..values[leftLast] and 
	//       values[rightFirst]..values[rightLast] have been merged.
	//       values[leftFirst]..values[rightLast] is now sorted.
{
	ItemType tempArray[SIZE];

	int index = leftFirst;
	int saveFirst = leftFirst;

	while ((leftFirst <= leftLast) && (rightFirst <= rightLast))
	{
		if (values[leftFirst] < values[rightFirst])
		{
			tempArray[index] = values[leftFirst];
			leftFirst++;
			NumberOfSwap[0] += 1;
		}
		else
		{
			tempArray[index] = values[rightFirst];
			rightFirst++;
			NumberOfSwap[0] += 1;
		}
		index++;
		NumberOfSwap[1] += 1;
	}
	while (leftFirst <= leftLast)
		// Copy remaining items from left half.
	{
		tempArray[index] = values[leftFirst];
		leftFirst++;
		index++;
	}
	while (rightFirst <= rightLast)
		// Copy remaining items from right half.
	{

		tempArray[index] = values[rightFirst];
		rightFirst++;
		index++;
	}
	for (index = saveFirst; index <= rightLast; index++)
		values[index] = tempArray[index];
}
template<class ItemType>
void MergeSort(ItemType values[], int first, int last, ItemType NumberOfSwap[], int Length)
// Post: The elements in values are sorted by key.
{
	/*int Size = Length;*/
  if (first < last)
  {
    int middle = (first + last) / 2;
    MergeSort(values, first, middle, NumberOfSwap, Length);
    MergeSort(values, middle + 1, last, NumberOfSwap, Length);
    Merge(values, first, middle, middle + 1, last, NumberOfSwap, Length);
  }
}
#endif

