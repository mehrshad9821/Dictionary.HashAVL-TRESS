/*
File Name: BinaryNode.h

Class Description: holds an ADT type node tha is used in the dictionary
Binary Search Tree.

Created: July 15, 2016
Authors:
Alireza Rahbar
Email:   ara14@sfu.ca
ST ID:   301040709
-----------
Mehrshad Matin
Email:  mmatin@sfu.ca
ST ID:  301117102

*/


#ifndef _BINARY_NODE
#define _BINARY_NODE
#include <iostream>

template < class ItemType>
class BinaryNode
{
	private :
		ItemType item; // Data portion
		BinaryNode<ItemType>* leftChildPtr;  // Pointer to left child
		BinaryNode<ItemType>* rightChildPtr; // Pointer to right child
		BinaryNode<ItemType>* parentPtr;     // Pointer to parent
		
	public :
		//------------------------------------------------------------
		// Constructor Section.
		//------------------------------------------------------------
		BinaryNode();
		BinaryNode( const ItemType& anItem);
		BinaryNode( const ItemType& anItem,
					BinaryNode<ItemType>* leftPtr,
					BinaryNode<ItemType>* rightPtr,
					BinaryNode<ItemType>* prntPtr);
		//------------------------------------------------------------
		// Getters and Setters section
		//------------------------------------------------------------			
		void setItem( const ItemType& anItem);
		ItemType getItem() const;

		BinaryNode<ItemType>* getLeftChildPtr() const ;
		BinaryNode<ItemType>* getRightChildPtr() const ;
		BinaryNode<ItemType>* getParentPtr() const ;
		
		void setLeftChildPtr(BinaryNode<ItemType>* leftPtr);
		void setRightChildPtr(BinaryNode<ItemType>* rightPtr);
		void setParentPtr(BinaryNode<ItemType>* aParentPtr);
		
		//------------------------------------------------------------
		// Other methods:
		//------------------------------------------------------------
		bool isLeaf() const ;
		
}; // end BinaryNode
//#include "BinaryNode.cpp"

// Description: returns true if the node is a leaf
template <class ItemType>
bool BinaryNode<ItemType>::isLeaf() const
{
	return ((leftChildPtr==NULL) & (rightChildPtr==NULL));

}

// Description: Gets the Item of type ItemType ( dictionaryEntery)
template <class ItemType>
ItemType BinaryNode<ItemType>::getItem() const
{
	return item;
}



template <class ItemType>
void BinaryNode<ItemType>::setItem( const ItemType& anItem)
{
	item= anItem;
}

// Description: Gets the left child pointer
template <class ItemType>
BinaryNode<ItemType>* BinaryNode<ItemType>::getLeftChildPtr() const
{
	return leftChildPtr;
}

// Description: Gets the parent pointer
template <class ItemType>
BinaryNode<ItemType>* BinaryNode<ItemType>::getParentPtr() const
{
	return parentPtr;
}

// Description: Gets the right child pointer
template <class ItemType>
BinaryNode<ItemType>* BinaryNode<ItemType>::getRightChildPtr() const
{
	return rightChildPtr;
}

// Description: Sets the left child pointer
template <class ItemType>
void BinaryNode<ItemType>::setLeftChildPtr(BinaryNode<ItemType>* leftPtr)
{
	leftChildPtr = leftPtr;
	return;
}

// Description: Sets the right child pointer
template <class ItemType>
void BinaryNode<ItemType>::setRightChildPtr(BinaryNode<ItemType>* rightPtr)
{
	rightChildPtr=rightPtr;
	return;
}

// Description: Sets the paretn pointer
template <class ItemType>
void BinaryNode<ItemType>::setParentPtr(BinaryNode<ItemType>* aParentPtr)
{
	parentPtr=aParentPtr;
	return;
}

// Description: Constructor that initializes the node variables
template <class ItemType>
BinaryNode<ItemType>::BinaryNode()
{
	leftChildPtr = NULL;
	rightChildPtr = NULL;
	parentPtr = NULL;
}

// Description: Constructor that initializes the node variables
template <class ItemType>
BinaryNode<ItemType>::BinaryNode( const ItemType& anItem)
{
	item= anItem;
	leftChildPtr = NULL;
	rightChildPtr = NULL;
	parentPtr = NULL;
}


// Description: Constructor that initializes the node variables
template <class ItemType>
BinaryNode<ItemType>::BinaryNode( const ItemType& anItem, BinaryNode<ItemType>* leftPtr, BinaryNode<ItemType>* rightPtr, BinaryNode<ItemType>* prntPtr)
{
	item= anItem;
	leftChildPtr = leftPtr;
	rightChildPtr = rightPtr;
	parentPtr = prntPtr;
}
#endif