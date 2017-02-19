/*
File Name: EKTApp2.cpp

Description: English to Klingon translators.
Starts tranlsating by populating the dictionary. If input "display" is given,
the program will output all the items stored in the dictionary.
If no input is given when running the application, the user then should type in
words to tranlate them.

Contains two types of ADTs: a BST to inset the items in order
and a hashtable to retrive items in O(1).

Precondition: dataFile.txt should be input file to populate the dictionary
in the format of "English:Klingon" pairs. One pait for each line.

Created: July 31, 2016
Mehrshad Matin
Email:  mmatin@sfu.ca
ST ID:  301117102

*/




#include <iostream>
#include <fstream>
#include <sstream>

#include "dictionaryEntry.h"
#include "BinaryNode.h"
#include "BinaryNodeTree.h"
#include "HashedDictionary.h"




using namespace std;



void visit (dictionaryEntry& anEntery);

int main(int argc, char* argv[])
{

	string line;
	string english;
	string klingon;
	
	//Contains a BST to displayu items in order and a hash table dictionary to retrive items in O(1)
	BinaryNodeTree<dictionaryEntry> dictionaryTree;
	HashedDictionary<string, dictionaryEntry> HashDictionary;


	//open the input file and read it line by line
	ifstream myfile ("dataFile.txt");

	if (myfile.is_open())
	{
		while ( getline (myfile,line) )
		{
			istringstream ss(line);	    //Split the line
			getline(ss, english, ':');  // Use ":" as the delimiter for English.
			getline(ss, klingon); 		// No delimiter for the Klingon

			//create a dictonaryENtry Object to store the pair in hash table and BST.
			dictionaryEntry newEntry(english, klingon);
			dictionaryTree.insert(newEntry);
			HashDictionary.insert(english, newEntry);
		}
		myfile.close(); //close the file
	}
	else
  	{
		cout << "Unable to open file. Exiting the program"<<endl;
		return 0;
  	}

  	//cout<< "There are : "<<HashDictionary.getItemCount()<<" items in the dictionary."<<endl;

	if (argc ==2) //if arguments were given when running the application
	{
		if (string(argv[1])=="display") //if argumnet is "display"
			try
			{
				dictionaryTree.inorderTraverse(visit); //print all the nodes in oder
			}
			catch (hashTableEmptyException e)   //catch any exception if something goes wrong.
			{
				cout<<e.what()<<endl;
			}

		else //if unknown argumnet was passed when running the program
			cout<<"Unrecognized input command. Exiting program."<<endl;
			return 1;

	}
	else
	{
		//read the user input egnlish words and translate them...
		while(getline(cin, line)) {   // while there is data
			stringstream ss(line);
			if (line=="") //if empty: then exit
				return 1;
			//otherwise create an entery with English only and no klingon
			dictionaryEntry newEntry(line, "");
			try
			{
				//Attempt to find the Entry in the hashtabele
				cout<<HashDictionary.search(line,newEntry);
			}
			catch (NotFoundException e)
			{
				//catch any exceptions if not found.
				cout<<e.what()<<endl;
			}

		}

	}


	return 1;
}

// Description: This finction is passed to the data collection ADT,
// and is called once the node is visited when using the inorder-traverse function.
void visit (dictionaryEntry& anEntery)
{
	cout<< anEntery;
	return;
}
