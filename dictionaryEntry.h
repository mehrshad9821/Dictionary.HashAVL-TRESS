/*
File Name: dictionaryEntery.h

Class Description: Contains and english word and its klingontraslation pair.
These will be part of the each node as the data part.

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


#ifndef _dictionary_Entry
#define _dictionary_Entry

#include <string>
#include <iostream>
using namespace std;

class dictionaryEntry
{
	private:
		string english; 
		string klingon; //holds klingon translation of English word
	public:
		//------------------------------------------------------------
		// Constructor Section.
		//------------------------------------------------------------
		dictionaryEntry();
		dictionaryEntry(string eng, string klng);
		//------------------------------------------------------------
		// Getters and Setters section
		//------------------------------------------------------------
		string getEnglish();
		string getKlingon();
		void setEnglish(string eng);
		void setKlingon(string klng);
		
		//------------------------------------------------------------
		// Overloaded Operator Section.
		//------------------------------------------------------------
		bool operator == (const dictionaryEntry& rhs);
		bool operator <  (const dictionaryEntry& rhs);
		bool operator >  (const dictionaryEntry& rhs);
		bool operator <=  (const dictionaryEntry& rhs);
		bool operator >=  (const dictionaryEntry& rhs);
		
		friend ostream & operator<<(ostream & os, const dictionaryEntry& rhs);
		
};
#endif