/*
File Name: exceptions.h

Class Description: Defines the exception that is thrown when
    -the data collection ADT Tree is empty
    -the data collection Hash is empty
	-the entery was not found in the data collection ADT

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


#ifndef _EXCEPTIONS_H
#define _EXCEPTIONS_H
#include <stdexcept>
using namespace std;

// If the hash table is empty
class hashTableEmptyException: public logic_error {
public:
	hashTableEmptyException(): logic_error("Exception: Operation FAILED. Hash table is empty.") 
	{
	};
};

// If the tree is empty
class treeEmptyException: public logic_error {
public:
	treeEmptyException(): logic_error("Exception: Operation FAILED. Tree is empty.") 
	{
	};
};

// If an entry cannot be found in the tree
class NotFoundException: public logic_error {
	public:
		NotFoundException(): logic_error("Exception: Operation FAILED. Entery cannot be found.") 
		{
		};
};

#endif