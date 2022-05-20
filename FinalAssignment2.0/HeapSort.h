#include "Swap.h"
typedef int ItemType;

template<class ItemType>
void ReheapDown(ItemType elements[], int root, int bottom, ItemType NumberOfSwap[])
// Post: Heap property is restored.
{
  int maxChild;
  int rightChild;
  int leftChild;

  leftChild = root*2+1;
  rightChild = root*2+2;
  if (leftChild <= bottom)
  {
    if (leftChild == bottom)
      maxChild = leftChild;
    else
    {
      if (elements[leftChild] <= elements[rightChild])
        maxChild = rightChild;
      else
        maxChild = leftChild;
    }
	NumberOfSwap[1] += 1;
    if (elements[root] < elements[maxChild])
    {
		NumberOfSwap[0] += 1;
      Swap(elements[root], elements[maxChild]);
      ReheapDown(elements, maxChild, bottom, NumberOfSwap);
    }
  }
}

template<class ItemType>
void HeapSort(ItemType values[], int numValues, ItemType NumberOfSwap[])
// Pre:  Struct HeapType is available.
// Post: The elements in the array values are sorted by key.
{
  int index;

  // Convert the array of values into a heap.
  for (index = numValues/2 - 1; index >= 0; index--)
    ReheapDown(values, index, numValues-1, NumberOfSwap);

  // Sort the array.
  for (index = numValues-1; index >=1; index--)
  {
	  NumberOfSwap[0] += 1;
    Swap(values[0], values[index]);
    ReheapDown(values, 0, index-1, NumberOfSwap);
  }
}
