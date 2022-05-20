#include "Swap.h"
template <class ItemType>
void Split(ItemType values[], int first, int last, int& splitPoint, ItemType NumberOfSwap[])
{
  ItemType splitVal = values[first];
  int saveFirst = first;
  bool onCorrectSide;

  first++;
  do
  {
    onCorrectSide = true;
    while (onCorrectSide)         // Move first toward last.
		if (values[first] > splitVal)
		{
			NumberOfSwap[1] += 1;
			onCorrectSide = false;
		}
      else
      {  
        first++;
        onCorrectSide = (first <= last);
      }

    onCorrectSide = (first <= last);
    while (onCorrectSide)             // Move last toward first.
		if (values[last] <= splitVal)
		{
			NumberOfSwap[1] += 1;
			onCorrectSide = false;
		}
      else
      {
        last--;
        onCorrectSide = (first <= last);
      }
   
    if (first < last)
    {
      Swap(values[first], values[last]);
	  NumberOfSwap[0] += 1;
      first++;
      last--;
    }
  } while (first <= last);

  splitPoint = last;
  Swap(values[saveFirst], values[splitPoint]);
  NumberOfSwap[0] += 1;
}


template<class ItemType>
void QuickSort(ItemType values[], int first, int last, ItemType NumberOfSwap[])
{
  if (first < last)
  {
    int splitPoint;

    Split(values, first, last, splitPoint, NumberOfSwap);
    // values[first]..values[splitPoint-1] <= splitVal
    // values[splitPoint] = splitVal
    // values[splitPoint+1]..values[last] > splitVal

    QuickSort(values, first, splitPoint-1, NumberOfSwap);
    QuickSort(values, splitPoint+1, last, NumberOfSwap);
  }
}