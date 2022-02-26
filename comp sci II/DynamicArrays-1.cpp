/*
Jackie Diep
CSC 102 November 2019
Adding exception handling to the program from assignment 5 to manage when a candidate with negative votes is found

Changes in lines 65 - 83 and 103 - 129 of candidate.cpp
*/

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <iomanip>
#include "candidate.h"

using namespace std;

int main()
{
	//declare an ifstream object candidateFile to be read into the program
	ifstream candidateFile;

	//initialize the counter that will be used to determine the size of the dynamic array and later loop lengths
	int counter = 0;

	//initialize string "line" to be used in the getline() function
	string line;

	//initialize sum within the main file to simplify functions
	double sum = 0;

	//open candidate.txt
	candidateFile.open("C:\\Users\\tripl\\Desktop\\candidates.txt");

	//count the number of lines within candidate.txt to set as array size, and reset back to the beginning of the file
	while (getline(candidateFile, line))
	{
		counter++;
	}
	candidateFile.clear();
	candidateFile.seekg(0, ios::beg);

	//create a pointer for the new candidate array, create a pointer to save the location of the array, and create a pointer
	//to save the location of the candidate with the most votes
	candidate* candidatePtr = new candidate[counter];
	candidate* ptrSaver = candidatePtr;
	candidate* mostVotePtr = candidatePtr;
	candidatePtr = ptrSaver;
	//call upon the function to read in information from the file into the array and reset the location of the pointer
	candidatePtr->setCandidates(counter, candidatePtr);
	candidatePtr = ptrSaver;

	//call upon the function to calculate the sum of the votes of the array and reset the location of the pointer
	sum = candidatePtr->voteSumCalc(counter, candidatePtr, sum);
	candidatePtr = ptrSaver;

	//call upon the function to print the information of each candidate which also calls upon the function to calculate the 
	//percentage of the total vote each candidate maintains and reset the location of the pointer
	candidatePtr->displayCandidates(counter, candidatePtr, sum);
	candidatePtr = ptrSaver;

	//call upon the function that determines the candidate with the greatest amount of votes and outputs the winner
	candidatePtr->mostVotesCalc(counter, candidatePtr, mostVotePtr);
	candidatePtr = ptrSaver;

	//close the file and set the pointers to null
	candidateFile.close();
	candidatePtr = 0;
	ptrSaver = 0;
	mostVotePtr = 0;
}