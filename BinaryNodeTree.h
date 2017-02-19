/*
File Name: EKTApp.cpp

Description: ADT binary tree: Link-based implementation.

Class invariants: Item in the tree are always in order

Created: July 15, 2016

Mehrshad Matin
Email:  mmatin@sfu.ca
ST ID:  301117102

*/

#ifndef _BINARY_NODE_TREE
#define _BINARY_NODE_TREE
#include "BinaryNode.h"
#include "exceptions.h"


template <class ItemType>
class BinaryNodeTree
{
	private :
		BinaryNode<ItemType>* rootPtr;
	
	protected:
		//------------------------------------------------------------
		// Protected Utility Methods Section:
		// Recursive helper methods for the public methods.
		//------------------------------------------------------------
		// Recursively deletes all nodes from the tree.
		void destroyTree(BinaryNode<ItemType>* subTreePtr);
		
		// Recursively finds where the given node should be placed and
		// inserts it in a leaf at that point.
		BinaryNode < ItemType >* insertR (BinaryNode < ItemType >* subTreePtr, BinaryNode < ItemType >* newNodePtr);
		
		
		// Recursively searches for target value in the tree by using a
		// preorder traversal.
		BinaryNode<ItemType>* findNode(BinaryNode<ItemType>* treePtr,const ItemType& target) const;
		
		// Copies the tree rooted at treePtr and returns a pointer to
		// the copy.
		BinaryNode <ItemType>* copyTree(const BinaryNode<ItemType>* treePtr) const;
		
		//recursively traverses the tree in order fashio
		void inorder (void visit (ItemType &), BinaryNode < ItemType > *nodePtr) const;
	
	public :
		//------------------------------------------------------------
		// Constructor and Destructor Section.
		//------------------------------------------------------------
		BinaryNodeTree();
		BinaryNodeTree (const BinaryNodeTree<ItemType> &treePtr);
		~BinaryNodeTree();
		
		//------------------------------------------------------------
		// Public BinaryTreeInterface Methods Section.
		//------------------------------------------------------------
		bool isEmpty() const ;

		// wrapper around the recursive method that adds a node at the correct place
		bool insert( const ItemType& newData); 

		
		ItemType getEntry( const ItemType& anEntry) const throw (NotFoundException);
		
		// Recursive traversal helper method:
		void inorderTraverse (void visit (ItemType &)) const throw (treeEmptyException);

	
}; // end BinaryNodeTree




// Description: Default constructor
template <class ItemType>
BinaryNodeTree<ItemType>::BinaryNodeTree()
{
	rootPtr = NULL;
}
// Description: returns true if the tree is empty
template <class ItemType>
bool BinaryNodeTree<ItemType>::isEmpty() const
{
	return (rootPtr == NULL);
}

// Description: wrapper around the recursive method that adds a node at the correct place
// Post-condition: Nodes in the tree are still in order
template <class ItemType>
bool BinaryNodeTree<ItemType>::insert( const ItemType& newData)
{
	BinaryNode<ItemType>* newNodePtr = new BinaryNode<ItemType>(newData);
	rootPtr = insertR(rootPtr, newNodePtr );
	return true ;
} // end add

// Description: Recursive method that adds a node at the correct place
template <class ItemType>
BinaryNode < ItemType >* BinaryNodeTree<ItemType>::insertR (BinaryNode < ItemType >* subTreePtr, BinaryNode < ItemType >* newNodePtr)
{

	BinaryNode<ItemType>* tempPtr;
	if (subTreePtr == NULL)
	{
		
		tempPtr = NULL;
		delete tempPtr;
		return newNodePtr;
	}
	else if (subTreePtr->getItem() > newNodePtr->getItem())
	{
		tempPtr = insertR(subTreePtr->getLeftChildPtr(), newNodePtr);
		subTreePtr->setLeftChildPtr(tempPtr);

	}
	else if (subTreePtr->getItem() < newNodePtr->getItem())
	{
		tempPtr = insertR(subTreePtr->getRightChildPtr(), newNodePtr);
		subTreePtr->setRightChildPtr(tempPtr);
	}
	
	tempPtr = NULL;
	delete tempPtr;

	return subTreePtr;
}


// Description: recursively traverses the tree in order fashio
//Precondition: tree should not be empty
template < class ItemType > 
void BinaryNodeTree < ItemType >::inorder (void visit (ItemType &),
						       BinaryNode < ItemType > *nodePtr) const
{
  if (nodePtr != NULL)
    {
      inorder (visit, nodePtr->getLeftChildPtr ());
      ItemType theItem = nodePtr->getItem ();

      visit (theItem);
      inorder (visit, nodePtr->getRightChildPtr ());
    }	// end if
}   // end inorder


// Description: wrapper arpund the recursive travers method insertR the tree in order fashio
template <class ItemType> 
void BinaryNodeTree < ItemType >::inorderTraverse (void visit (ItemType &)) const throw (treeEmptyException)
{

	// Throw exception if tree is empty
	if (rootPtr == NULL) {
		throw treeEmptyException();
		return;
	}
	else {
		inorder(visit, rootPtr);		// enter recursive part of algorithm
	}
	return;

}


//Description: recursivly traverses the method in pre-order fahsion to find the target item.
//Returns a pointer to the found node
template <class ItemType> 
BinaryNode<ItemType>* BinaryNodeTree <ItemType>::findNode(BinaryNode<ItemType>* treePtr,const ItemType& target) const
{
	if(treePtr == NULL)
	{
		return NULL; // not found
	}
	else if (treePtr ->getItem() == target)
	{
		return treePtr; //found
	}
	else if (treePtr->getItem() > target)
	{
		return findNode(treePtr->getLeftChildPtr(), target);
	}
	else //(treePtr->getItem() < target)
	{
		return findNode(treePtr->getRightChildPtr(), target);
	}
	
}

// Description: wrapper arpund the recursive method findNode()
// Throws an expetion if tree is empty or item not found
// Precondition: tree should not be empty

template <class ItemType> 
ItemType BinaryNodeTree <ItemType>::getEntry( const ItemType& anEntry) const throw (NotFoundException)
{
	if(rootPtr!= NULL)
	{
		BinaryNode<ItemType>* resultPtr = findNode(rootPtr, anEntry);	
		if (resultPtr != NULL)
			return resultPtr->getItem();
		else
			throw NotFoundException();
	}
	else 
	{
		throw NotFoundException();
	}
	
}


// Description: Copy Constructor. Wrapper around the recursive method copyTree()
template <class ItemType> 
BinaryNodeTree <ItemType>::BinaryNodeTree (const BinaryNodeTree < ItemType > &treePtr)
{
  rootPtr = copyTree (treePtr.rootPtr);
}   // end copy constructor



//  Description: copies the tree node by node in recursive fashion
template < class ItemType > 
BinaryNode <ItemType>* BinaryNodeTree<ItemType>::copyTree (const BinaryNode<ItemType>* treePtr) const
{
	BinaryNode < ItemType > *newTreePtr = NULL;
	// Copy tree nodes during a preorder traversal
	if (treePtr != NULL)
	{
		// Copy node
		newTreePtr = new BinaryNode < ItemType > (treePtr->getItem (), NULL, NULL, NULL);
		newTreePtr->setLeftChildPtr  (copyTree (treePtr->getLeftChildPtr ()));
		newTreePtr->setRightChildPtr (copyTree (treePtr->getRightChildPtr ()));
		newTreePtr->setParentPtr     (copyTree (treePtr->getParentPtr ()));
	}	// end if
	// Else tree is empty (newTreePtr is NULL)
	return newTreePtr;
}   // end copyTree



// Description: recursivly traverses through the tree in pre-order fashion
// and destorys each node
template < class ItemType >
void BinaryNodeTree<ItemType>::destroyTree (BinaryNode <ItemType>* subTreePtr)
{
  if (subTreePtr != NULL)
    {
      destroyTree (subTreePtr->getLeftChildPtr ());
      destroyTree (subTreePtr->getRightChildPtr ());
      delete subTreePtr;
    }	// end if
}   // end destroyTree

//Description: Destructor. Wrapper around the recursive method destroyTree()
template <class ItemType>
BinaryNodeTree<ItemType>::~BinaryNodeTree()
{
	destroyTree (rootPtr);
}

#endif
