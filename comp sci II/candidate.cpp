#include "candidate.h"
#include <string>
#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;

//Default constructor
candidate::candidate()
{
	fName = "Not Set";
	lName = "Not Set";
	votes = 0;
}

//Constructor with initialized variables
candidate::candidate(string sFName, string sLName, int sVotes)
{
	fName = sFName;
	lName = sLName;
	votes = sVotes;
}

//Functions to set and get first name
void candidate::setFName(string sFName)
{
	fName = sFName;
}
string candidate::getFName()
{
	return fName;
}

//Functions to set and get last name
void candidate::setLName(string sLName)
{
	lName = sLName;
}
string candidate::getLName()
{
	return lName;
}

//Functions to set and get the amount of votes
void candidate::setVotes(int sVotes)
{
	votes = sVotes;
}
int candidate::getVotes()
{
	return votes;
}

//Function to set the information of each candidate pulled from candidate.txt
void candidate::setCandidates(int counter, candidate *candidatePtr)
{
	ifstream candidateFile;
	candidateFile.open("C:\\Users\\tripl\\Desktop\\candidates.txt");
	for (float i = 0; i < counter; i++)
	{
		while (i  < counter && candidateFile >> fName >> lName >> votes)
		{
			candidatePtr->setFName(fName);
			candidatePtr->setLName(lName);
			candidatePtr->setVotes(votes);
			candidatePtr++;
		}
	}
	candidateFile.close();
}

//Function to calculate the total amount of votes among the candidates
double candidate::voteSumCalc(int counter, candidate *candidatePtr, double sum)
{
	for (float i = 0; i < counter; i++)
	{
		sum += candidatePtr->getVotes();
		candidatePtr++;
	}
	return sum;
}

//Function to display the information of each candidate and call upon the getPercentVotes function
void candidate::displayCandidates(int counter, candidate *candidatePtr, double sum)
{
	for (float i = 0; i < counter; i++)
	{
		cout << std::setprecision(2) << fixed;
		cout << "Name: " << candidatePtr->getFName() << "	" << candidatePtr->getLName() << "		" << "Votes: " << candidatePtr->getVotes();
		cout << "	" << candidatePtr->getPercentVotes(sum) << "	% of total votes." << endl;
		candidatePtr++;
	}
}

//Function to calculate the percentage of votes each candidate received
double candidate::getPercentVotes(double sum)
{
	double percentVotes = votes / sum;
	return percentVotes * 100;
}

//Function to decide upon and output which candidate had the most votes and won the election
void candidate::mostVotesCalc(int counter, candidate *candidatePtr, candidate *mostVotePtr)
{
	int mostVotes = 0;
	for (float i = 0; i < counter; i++)
	{
		int compareVotes;
		compareVotes = candidatePtr->getVotes();
		if (compareVotes > mostVotes)
		{
			mostVotes = compareVotes;
			mostVotePtr = candidatePtr;
		}
		candidatePtr++;
	}
	candidatePtr = mostVotePtr;
	cout << "\nThe winner of the vote is: " << candidatePtr->getFName() << " " << candidatePtr->getLName() << endl;
}

