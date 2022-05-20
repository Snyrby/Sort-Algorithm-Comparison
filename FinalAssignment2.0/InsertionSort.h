#include "Swap.h"
template<class ItemType>
void InsertItem(ItemType values[], int startIndex, int 
endIndex, ItemType NumberOfSwap[])
// Post: values[0]..values[endIndex] are now sorted.
{
  bool finished = false;
  int current = endIndex;
  bool moreToSearch = (current != startIndex);

  while (moreToSearch && !finished)
  {
	  NumberOfSwap[1] += 1;
    if (values[current] < values[current-1])
    {
      Swap(values[current], values[current-1]);
	  NumberOfSwap[0] += 1;
      current--;
      moreToSearch = (current != startIndex);
    }
    else
      finished = true;
  }
}

template<class ItemType>
void InsertionSort(ItemType values[], int numValues, ItemType NumberOfSwap[])
// Post: The elements in the array values are sorted by key.
{
  for (int count = 0; count < numValues; count++)
    InsertItem(values, 0, count, NumberOfSwap);
}

