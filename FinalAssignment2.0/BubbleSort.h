#include "Swap.h"


template<class ItemType>
void BubbleUp(ItemType values[], int startIndex, int endIndex, ItemType NumberOfSwap[])
// Post: Adjacent pairs that are out of order have been 
//       switched between values[startIndex]..values[endIndex]
//       beginning at values[endIndex].
{
	for (int index = endIndex; index > startIndex; index--)
	{
		NumberOfSwap[1] += 1;
		if (values[index] < values[index - 1])
		{
			Swap(values[index], values[index - 1]);
			NumberOfSwap[0] += 1;
		}
	}
}

template<class ItemType>
void BubbleSort(ItemType values[], int numValues, ItemType NumberOfSwap[])
// Post: The elements in the array values are sorted by key.
{
  int current = 0;

  while (current < numValues - 1)
  {
    BubbleUp(values, current, numValues-1, NumberOfSwap);
    current++;
  }
 
}
