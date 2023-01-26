/* File: autocomplete.cpp
 * Course: CS216-002
 * Project: Project 2
 * Purpose: the implementation of member functions for the class named Autocomplete.
 * Author: Bryce Grant
 */
#include <iostream>
#include "autocomplete.h"
#include "magicString.h"

// default constructor
Autocomplete::Autocomplete()
{
    // You can leave it blank
    // since the private data member terms has been initialized through default constructor of SortingList class 
}


// inserts the newterm to the sequence
// note that a SortingList<Term> object, named terms
//          represents the sequence
void Autocomplete::insert(Term newterm)
{
	terms.insert(newterm);
}


// sort all the terms by query in the lexicographical order  
void Autocomplete::sort()
{
	terms.sort();
}

// binary search helper function
// as private function
// since it serves binary_search member function only
int Autocomplete::binary_searchHelper(SortingList<Term> terms, string key, int left_index, int right_index)
{
    if(right_index < left_index)
    {
        int KEY_NOT_FOUND = -1;
        return KEY_NOT_FOUND;
    }
    else
    {
        Term keyterm(key, 0);
        int r = key.length();
        int middle = (left_index + right_index) / 2;
        if(Term::compareByPrefix(keyterm,terms[middle],r) > 0)
        {
            return binary_searchHelper(terms, key, left_index, middle - 1);

        }
        else if(Term::compareByPrefix(keyterm,terms[middle],r)  < 0)
        {
            return binary_searchHelper(terms, key, middle + 1, right_index);
        }
        else
        {
            return middle;
        }
    }
}

// return the index number of the term whose query 
// prefix-matches the given prefix, using binary search algorithm
// Note that binary search can only be applied to sorted sequence
// Note that you may want a binary search helper function
int Autocomplete::binary_search(string prefix)
{
	sort();
	return binary_searchHelper(terms, prefix, 0, terms.size()-1);
}

string Autocomplete::string_correction(string key){

	string myNewString = key;
	string result;
	bool space_present = true;
	for (int i = 0; i < myNewString.length(); i++)
	{
		if(myNewString[i] == '\t'){
			myNewString[i] = ' ';}
		if (myNewString[i] != ' '){ //remove spaces before first character
			result += myNewString[i];
			space_present = false;
		}
		else if (!space_present){
			result += myNewString[i];
			space_present = true;
		}
		else{
			space_present = true;}}
	string myString = "";
	string blank = "x";
	for (char c : result){
		if(blank.back() != ' ' && c == ' '){
			myString.push_back(' ');
		blank.push_back(c);}
		if (c != ' ')
			myString.push_back(c);}

	string temp = myString;
	return temp;
}
// first: the index of the first query whose prefix matches
//          the search key, or -1 if no such key
// last: the index of the last query whose prefix matches 
//         the search key, or -1 if no such key
// key: the given prefix to match
// hints: you can call binary_search() first to find one matched index number,
//        say hit, then look up and down from hit, to find first and last respectively
void Autocomplete::search(string key, int& firstIndex, int& lastIndex)
{
	//correct for the spaces
	string temp = string_correction(key);
	
	int curr_index = binary_search(temp);
	if(curr_index == -1){
		firstIndex = -1;
		lastIndex = -1;
		return;}

	// Looking in both directions to find prefix terms that match
	// First forward then backward
	firstIndex = curr_index;
	lastIndex = curr_index;
	for(int i = curr_index; i >= 0; i--){
		if(terms[i].compareByPrefix(terms[i], terms[curr_index],temp.length())!=0){
			firstIndex = i+1;
			break;
		}
		
	}
	for(int j = curr_index; j < terms.size(); j++){
		if(terms[j].compareByPrefix(terms[j], terms[curr_index], temp.length())!=0){
			lastIndex = j-1;
			break;
		}
		
	
	}
}
// returns all terms that start with the given prefix, in descending order of weight
SortingList<Term> Autocomplete::allMatches(string prefix)
{
	SortingList<Term> matches;
	int firstIndex;
	int lastIndex;
	search(prefix, firstIndex, lastIndex);
	if (firstIndex == -1 || lastIndex == -1){
		return matches;}
	for(int i = firstIndex; i <= lastIndex; i++){
		matches.insert(this->terms[i]);
	}
	matches.merge_sort(Term::compareByWeight);

	return matches;
}

void Autocomplete::print()
{
	terms.print();
}
