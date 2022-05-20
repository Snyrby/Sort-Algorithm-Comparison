#include "Swap.h"
typedef int ItemType;

template<class ItemType>
int MinIndex(ItemType values[], int startIndex, int endIndex, ItemType NumberOfSwap[])
// Post: Returns the index of the smallest value in
//       values[startIndex]..values[endIndex].
{
  int indexOfMin = startIndex;
  for (int index = startIndex + 1; index <= endIndex; index++)
  {
	  NumberOfSwap[1] += 1;
	  if (values[index] < values[indexOfMin])
	  {
		  indexOfMin = index;
	  }
  }
  return indexOfMin;
}


template<class ItemType>
void SelectionSort(ItemType values[], int numValues, ItemType NumberOfSwap[])
// Post: The elements in the array values are sorted by key.
{
  int endIndex = numValues-1;
  for (int current = 0; current < endIndex; current++)
  {
	  NumberOfSwap[0] += 1;
	  Swap(values[current], values[MinIndex(values, current, endIndex, NumberOfSwap)]);
  }
} 


