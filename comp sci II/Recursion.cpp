/*
Jackie Diep
CSC 102 November 2019
A program that recursively calls a function to check whether or not a string is a palindrome.
Must contain a value-returning recursive function that returns true or false.
No global variables
*/

#include <iostream>
#include <string>
using namespace std;

//Bool function palindrome prototype
bool palindrome(string testPalindrome, int fLetter, int lLetter);

//Main function that asks for a string, calls the bool function palindrome, and outputs the result
int main()
{
	//Initialize the string to be tested
	string testPalindrome;

	//Prompt the user for and receive the string to be tested
	cout << "Enter the string to be tested." << endl;
	cin >> testPalindrome;

	//Call the bool function palindrome to test the string
	palindrome(testPalindrome, 0, testPalindrome.length() - 1);

	//Output whether or not the function returns true or false
	if (palindrome(testPalindrome, 0, testPalindrome.length() - 1))
	{
		cout << "This string is a palindrome.";
	}
	else
	{
		cout << "This string is not a palindrome.";
	}
}

//Bool function palindrome definition
bool palindrome(string testPalindrome, int fLetter, int lLetter)
{
	
	//If the two int variables successfully meet in the middle of the word, then the word is a palindrome, return true
	if (fLetter == lLetter)
	{
		return true;
	}

	//If the letters at any point of comparison within the recursion are incorrect, return false
	else if (testPalindrome.substr(fLetter, 1) != testPalindrome.substr(lLetter, 1))
	{
		return false;
	}

	//Recursively call the function again, moving both points of comparison by one space in the string 
	//until either true or false are returned and return to main
	else
	{
		return palindrome(testPalindrome, fLetter + 1, lLetter - 1);
	}

}
