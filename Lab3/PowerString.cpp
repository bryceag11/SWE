/* 
 * File:   PowerString.cpp
 * Purpose: provide the definition of the PowerString class
 *
 * Author: Bryce Grant
 *
 */
#include <iostream>
#include <stack>
#include "PowerString.h"

// initialize str with ini_str passing as a parameter
PowerString::PowerString(string ini_str)
{
	str = ini_str;
}

// return the current value of the private data member: str
string PowerString::getString() const
{
	return str;
}

// set the value of str to be the passed in parameter input_str
void PowerString::setString(string input_str)
{
	str = input_str;
}

// return a reverse string
// using a loop to implement
// Note that the private data member named str, has not been changed
string PowerString::rev_loop() const
{
	string rev_string = "";
	int str_len = str.length();

	for (int i=str_len-1; i>=0; i--){
		rev_string += str[i];
	}
	return rev_string;
}

// return a reverse string
// using recursion to implement
// Note that the private data member named str, has not been changed
string PowerString::rev_recursion() const
{	
	if (str.length() <= 1)
		return str;

	size_t length = str.length();

	string str_rec = str.substr(1, length -1);

	PowerString str_rec_object(str_rec);
	return str_rec_object.rev_recursion() + str.at(0);
}

// return a reverse string
// using a stack to implement
// Note that the private data member named str, has not been changed
string PowerString::rev_stack() const
{
	//initialize string and stack 
	stack<char> stk;
	string ret_string;

	for(char chc:str){
		stk.push(chc);
	}
	//Pop from stack and add to string when the stack has content
	while(!stk.empty()){
		ret_string += stk.top();
		stk.pop();
	}
	return ret_string;
}

// return true if str is a palindrome
// otherwise return false
// A palindrome is defined as a sequence of characters which reads the same backward as forward
// calling member function to  implement
// Note that the private data member named str, has not been changed
bool PowerString::isPalindrome() const
{
	if (str == rev_loop())
		return true;
	else
		return false;
}
        
// return true if str is a palindrome
// otherwise return false
// A palindrome is defined as a sequence of characters which reads the same backward as forward
// using recursion to implement
// Note that the private data member named str, has not been changed
bool PowerString::isPalindrome_recursion() const
{
	string rev;
	rev = rev_recursion();
	if (str== rev)
		return 1;
	else
		return 0;

}
        
// displays str followed by a new line marker
// to the standard output
void PowerString::print() const
{
	cout << str << endl;
}
