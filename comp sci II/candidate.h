#ifndef CANDIDATE_H
#define CANDIDATE_H
#include <string>

using namespace std;

class candidate
{
public:
	
	//Default constructor and constructor with initialized variables
	candidate();
	candidate(string sFName, string sLName, int sVotes);

	//Functions to set and get first name
	void setFName(string sFName);
	string getFName();

	//Functions to set and get last name
	void setLName(string sLName);
	string getLName();

	//Functions to set and get the amount of votes
	void setVotes(int sVotes);
	int getVotes();

	//Function to set the information of each candidate from candidate.txt
	void setCandidates(int counter, candidate *candidatePtr);

	//Function to calculate the sum amount of votes among the candidates
	double voteSumCalc(int counter, candidate* candidatePtr, double sum);

	//Function to output the information of each candidate and call upon the 
	//getPercentVotes function which calculates the percentage of votes each candidate
	void displayCandidates(int counter, candidate* candidatePtr, double sum);
	double getPercentVotes(double sum);

	//Function to decide upon and output which candidate won the election
	void mostVotesCalc(int counter, candidate* candidatePtr, candidate* mostVotePtr);
	
private:
	//Initialize the three variables pulled from candidate.txt
	string fName;
	string lName;
	int votes;
};
#endif