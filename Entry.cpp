/*
File Name: Entry.cpp

Class Description: This is the base class Entry
Implemented based on Listing 18-2 of our textbook.
Represents: A class of entry objects for an array-based
implementation of the ADT dictionary.

Created: July 31, 2016

Mehrshad Matin
Email:  mmatin@sfu.ca
ST ID:  301117102
*/

template <class KeyType, class ItemType>
Entry<KeyType, ItemType>::Entry()
{
    // private and empty on purpose: prevent someone creating an entry without data.
}


//Description: Constrcutor
template <class KeyType, class ItemType>
Entry<KeyType, ItemType>::Entry(ItemType newEntry, KeyType newSearchKey)
{

        item = newEntry;
        searchKey = newSearchKey;
}
    
//Description: sets the item
template <class KeyType, class ItemType>
void Entry<KeyType, ItemType>::setItem(const ItemType& newEntry)
{
    item = newEntry;
}

//Description: returns the item
template <class KeyType, class ItemType>
ItemType Entry<KeyType, ItemType>::getItem() const
{
    return item;
}

//Description: returns the key
template <class KeyType, class ItemType>
KeyType Entry<KeyType, ItemType>::getKey() const
{
    return searchKey;
}

