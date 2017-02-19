/*
File Name: dictionaryEntery.cpp

Class Description: Contains and english word and its klingontraslation pair.
These will be part of the each node as the data part.

Created: July 15, 2016

-----------
Mehrshad Matin
Email:  mmatin@sfu.ca
ST ID:  301117102

*/


#include "dictionaryEntry.h"

//------------------------------------------------------------
// Constructor Section.
//------------------------------------------------------------
//Description: constructor. Sets to empty string.
dictionaryEntry::dictionaryEntry()
{	
	english = "";
	klingon = "";
}
//Description:  sets englishg and klingon
dictionaryEntry::dictionaryEntry(string eng, string klng)
{	
	english = eng;
	klingon = klng;
}

//------------------------------------------------------------
// Getters and Setters section
//------------------------------------------------------------

//Description:  Gets English
string dictionaryEntry::getEnglish()
{
	return english;
}
//Description: Gets Klingon
string dictionaryEntry::getKlingon()
{
	return klingon;
}
//Description: Sets English
void dictionaryEntry::setEnglish(string eng)
{
	english = eng;
}
//Description: Sets Klingon
void dictionaryEntry::setKlingon(string klng)
{
	klingon = klng;
}

//------------------------------------------------------------
// Overloaded Operator Section.
//------------------------------------------------------------

//Description: Returns true if the current object has an English word that is (alphabetically) equal to the
//object on the RHS.
bool dictionaryEntry::operator == (const dictionaryEntry& rhs)
{
	return (english == rhs.english);
}

//Description: Returns true if the current object has an English word that is (alphabetically) less than the
//object on the RHS.
bool dictionaryEntry::operator <  (const dictionaryEntry& rhs)
{
	return (english < rhs.english);
}

//Description: Returns true if the current object has an English word that is (alphabetically) greater than
//the object on the RHS.
bool dictionaryEntry::operator >  (const dictionaryEntry& rhs)
{
	return (english > rhs.english);
}

//Description: Returns true if the current object has an English word that is (alphabetically) less than
//equal the object on the RHS.
bool dictionaryEntry::operator <=  (const dictionaryEntry& rhs)
{
	return (english <= rhs.english);
}

//Description: Returns true if the current object has an English word that is (alphabetically) greater than
//equal the object on the RHS.
bool dictionaryEntry::operator >=  (const dictionaryEntry& rhs)
{
	return (english >= rhs.english);
}

//Description: Overloaded operator for printing. Prints the RHS object in the form of "English"Klingon".
ostream & operator<<(ostream & os, const dictionaryEntry& rhs)
{
	cout<<rhs.english<<":"<<rhs.klingon<<endl;
	return os;
}
