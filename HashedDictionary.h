/*
File Name: hashedDictionary.h

Class Description: This is a hash tabel data collection with
default size of 199, used to implement the English-to-klingon 
dictionary. The purpose of this hash table is to provide translation
in O(1). This ADT class is implemented based on the guidlines and 
samples provided in the textbook, chapter 18.

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

#ifndef _HASHED_DICTIONARY
#define _HASHED_DICTIONARY


#include "HashedEntry.h"
#include "exceptions.h"

template<class KeyType, class ItemType>
class HashedDictionary {

    private:

		static const int hashTableSize = 199;         // Picked a prime number that is suitable for the size of the imput files
                                                      // that are used in this assignment.
		int itemCount;					              // Count of dictioanry enteries
		HashedEntry<KeyType, ItemType>* hashTable[hashTableSize]; // Array of pointers to Hashedentries

	public:

        //Constructor
		HashedDictionary();
        //Getters:
        int getHashIndex(const KeyType& key) const;
        int getItemCount() const;
        //Helper Methods
		bool insert(const KeyType& searchKey, const ItemType& newItem);
        ItemType search(const KeyType& searchKey, const ItemType& target) const throw (NotFoundException);

};	//-------------------end class definition-------------------


//Description: Default Constructor
template<class KeyType, class ItemType>
HashedDictionary<KeyType, ItemType>::HashedDictionary()
{
    for (int i= 0; i<hashTableSize; i++)
    {
        hashTable[i] = NULL; //Set the pointer elements to NULL
    }
	itemCount = 0;
}

//Description: Returns the number of elements in the hash table
template<class KeyType, class ItemType>
int HashedDictionary<KeyType, ItemType>::getItemCount() const
{
    return itemCount;
}

//Description: this is the hash Key generator function.
//it generates a hash key for the input key by indin the mod of: (sum of chars hash number)/(hashTableSize).
//@Pre: key should be only letters: 'a' to 'z'. No special chars or numbers, etc.
//@post: return hash key. Not case sensitive. Returns -1 if found special chars.

template<class KeyType, class ItemType>
int HashedDictionary<KeyType, ItemType>::getHashIndex(const KeyType& key) const 
{

	char character;
    int  hashValue=0;

    //cout<<"THis is key "<<key<<endl;
    for (unsigned int i = 0; i < key.length(); i++)
	{
        character = tolower(key [i]); //convert everything to lower case.
    	if (character >= 'a' && character <= 'z') 
        {
    		hashValue += (character - 'a'); //accumulate the ahsh values
    	}
        else
        {
            return -1; //Invalid char. Terminate.
        }
    }
    hashValue = hashValue % hashTableSize; //find the mod
	return hashValue;
}


//Description: this is the insert method
//@pre: search key should be chars 'a' to 'z' (ie: no special chars)
//@post: returns false if unable to insert ( hash key is not calculated correctly.)
 template <class KeyType, class ItemType>
 bool HashedDictionary<KeyType, ItemType>::insert(const KeyType& searchKey, const ItemType& newItem)
 {
	// Create entry to insert to dictionary
	HashedEntry<KeyType, ItemType>* entryToAddPtr =
		new HashedEntry<KeyType, ItemType>(newItem, searchKey);

	// Compute the hashed index into the array
	int itemHashIndex = getHashIndex(searchKey);

    if(itemHashIndex == -1)
    {
        cout<<"Invalid English word. Unable to insert."<<endl;
        return false;
    }

	// if the tabel is empty at that index: add the entry to the chain at itemHashIndex
	if(hashTable[itemHashIndex] == NULL)
	{
		hashTable[itemHashIndex] = entryToAddPtr;
        itemCount ++;
        return true;
	}
	else
	{
        //Elese if the chain already has an element:
        //Must traverse the cahin to insert it inorder (in order to be able to reject duplicate enteries.)

        HashedEntry<KeyType, ItemType>* currentEntry = hashTable[itemHashIndex];

        if(*entryToAddPtr<*currentEntry)
        {
            //If item is smalles in the chain:
            //must insert it at the begining of the chain
            entryToAddPtr->setNext(hashTable[itemHashIndex]);
            hashTable[itemHashIndex] = entryToAddPtr;
            itemCount ++;
            return true;
        }
        else
        {
            //traverse through the chain until we find the correct position. 
            while(true)
            {
                if(*entryToAddPtr == *currentEntry)
                {
                    //this is a duplicate item. DO not add it to the hash table.
                    return false;     
                }
                //If already at the end of the chain: add it at the here at the end.
                if(currentEntry->getNext() == NULL)
                {
                    currentEntry->setNext(entryToAddPtr);
                    itemCount ++;
                    return true;
                }
                else
                {
                    //compare the valuse see if we can insert here
                    if(*entryToAddPtr < *currentEntry->getNext()) 
                    {
                        entryToAddPtr->setNext(currentEntry->getNext());
                        currentEntry->setNext(entryToAddPtr);
                        itemCount ++;
                        return true;
                    }
                    else
                    {
                        //if not: move by one elemetn and continue the loop until we insert it.
                        currentEntry = currentEntry->getNext();
                    }

                }
                    
            }
        }
		
	}
    //If unable to insert it abovethen return false.
	return false;

} // end add

template <class KeyType, class ItemType>
ItemType HashedDictionary<KeyType, ItemType>::search(const KeyType& searchKey, const ItemType& target) const throw (NotFoundException)
{

    //calulate the hash index of the target item
    int itemHashIndex = getHashIndex(searchKey);

    //if invalid item then we cannot find the target:
    if(itemHashIndex == -1)
    {
        cout<<"Invalid English word."<<endl;
        throw NotFoundException();
    }

    // go to the hashtable at that index
    // Traverse the chain until we find the target item
    HashedEntry<KeyType, ItemType>* currentEntry = hashTable[itemHashIndex];
    while (currentEntry != NULL)    
    {
        if(currentEntry->getItem() == target)
        {
            return currentEntry->getItem(); //foud it
        }
        else if (currentEntry->getNext() != NULL)
        {   // if not the end of the chain: move to the end of the chain and continue.
            currentEntry = currentEntry->getNext();

        }
        else
        {   //if at the end of the chain: exit the while loop. Not found.
            break; // throw exception after this.
        }

    }
    //cout<<"could not find it!!!\n";
    throw NotFoundException();

}//end search




#endif