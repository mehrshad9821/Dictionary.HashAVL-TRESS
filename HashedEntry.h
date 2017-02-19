/*
File Name: HashedEntry.h

Class Description: This is a hashed Entry class
Implemented based on Listing 18-5 of our textbook.
Represents: A class of entry objects for a hashing 
implementation of the ADT dictionary
This is a drived class based on Entry. 
It basically adds the hashed part to the implementation


Mehrshad Matin
Email:  mmatin@sfu.ca
ST ID:  301117102

*/
 
#ifndef _HASHED_ENTRY
#define _HASHED_ENTRY

#include "Entry.h"


template<class KeyType, class ItemType>
class HashedEntry : public Entry<KeyType, ItemType>
{
private:
   //next pointer: to create the chain hashing
   HashedEntry<KeyType, ItemType>* nextPtr;
   
public:
  //Constructors
   HashedEntry();
   HashedEntry(ItemType newEntry, KeyType newSearchKey);
   HashedEntry(ItemType newEntry, KeyType newSearchKey,
               HashedEntry<KeyType, ItemType>* nextEntryPtr);
   //Setterd and getters:
   void setNext(HashedEntry<KeyType, ItemType>* nextEntryPtr);
   HashedEntry<KeyType, ItemType>* getNext() const;
   //Overloaded operators.
   bool operator==(const HashedEntry<KeyType, ItemType>& rhs) const;
   bool operator>(const HashedEntry<KeyType, ItemType>& rhs) const;
   bool operator<(const HashedEntry<KeyType, ItemType>& rhs) const;
}; // end HashedEntry

//Constructor
template <class KeyType, class ItemType>
HashedEntry<KeyType, ItemType>::HashedEntry(ItemType newEntry, KeyType newSearchKey)
			:Entry<KeyType, ItemType>(newEntry, newSearchKey)
{
	nextPtr= NULL;
}
//Constructor
template <class KeyType, class ItemType>
HashedEntry<KeyType, ItemType>::HashedEntry(ItemType newEntry, KeyType newSearchKey,
               HashedEntry<KeyType, ItemType>* nextEntryPtr): Entry<KeyType, ItemType>(newEntry, newSearchKey)
{
	nextPtr= nextEntryPtr;
}
//Constructor
template <class KeyType, class ItemType>
HashedEntry<KeyType, ItemType>::HashedEntry()
{
	nextPtr= NULL;
}

//Setter: Sets the nextpointer.
template <class KeyType, class ItemType>
void HashedEntry<KeyType, ItemType>::setNext(HashedEntry<KeyType, ItemType>* nextEntryPtr)
{
    nextPtr = nextEntryPtr;
}

//Getter: Gets the next pointer
template<class KeyType, class ItemType>
HashedEntry<KeyType, ItemType>* HashedEntry<KeyType, ItemType>::getNext() const
{
    return nextPtr;
}

//Description: Compares the rhs argument and the current object. Return true if the compariosn 
// of their associated items is satisfied
template <class KeyType, class ItemType>
bool HashedEntry<KeyType, ItemType>::operator > (const HashedEntry<KeyType, ItemType>& rhs) const
{
    return (this->getItem() > rhs.getItem());
}

//Description: Compares the rhs argument and the current object. Return true if the compariosn 
// of their associated items is satisfied
template <class KeyType, class ItemType>
bool HashedEntry<KeyType, ItemType>::operator < (const HashedEntry<KeyType, ItemType>& rhs) const
{
    return (this->getItem() < rhs.getItem());
}

// Description: Compares the rhs argument and the current object. Return true if the compariosn 
// of their associated items is satisfied
template <class KeyType, class ItemType>
bool HashedEntry<KeyType, ItemType>::operator == (const HashedEntry<KeyType, ItemType>& rhs) const
{
    return (this->getItem() == rhs.getItem());
}


#endif
