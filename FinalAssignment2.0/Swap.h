#ifndef SWAP_H
#define SWAP_H

typedef int ItemType;

const int SIZE = 1000;

template<class ItemType>
void Swap(ItemType& item1, ItemType& item2)
// Post: Contents of item1 and item2 have been swapped.
{
	ItemType tempItem;

	tempItem = item1;
	item1 = item2;
	item2 = tempItem;
	
}

#endif
