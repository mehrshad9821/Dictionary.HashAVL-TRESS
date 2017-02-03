/*
File Name: Entry.h

Class Description: This is the base class Entry
Implemented based on Listing 18-2 of our textbook.
Represents: A class of entry objects for an array-based
implementation of the ADT dictionary.

Created: July 31, 2016
Authors:
Alireza Rahbar
Email:   ara14@sfu.ca
ST ID:   301040709
-----------
Mehrshad Matin
Email:  mmatin@sfu.ca
ST ID:  301117102
*/

#ifndef _ENTRY
#define _ENTRY

template <class KeyType, class ItemType>
class Entry
{
private:
   ItemType item;
   KeyType searchKey;
   
protected:
   void setKey(const KeyType& searchKey);
   Entry(); // private on purpose: prevent someone creating an entry without data.
public:
   //Constrcutor
   Entry(ItemType newEntry, KeyType searchKey);
   //Getters and setters
   ItemType getItem() const;
   KeyType getKey() const;
   void setItem(const ItemType& newEntry);
}; // end Entry

#include "Entry.cpp"
#endif