//Include listNodes header file
#include "listNodes.h"

//Include iostream for number input in the append function
#include <iostream>

//Default constructor setting all values to null
using namespace std;
listNodes::listNodes()
{
	info = NULL;
	link = nullptr;
	head = nullptr;
	end = nullptr;
	newNode = nullptr;
}

//Append function to add values to the end of the list
void listNodes::append()
{
	
	//Initialize 'int number' to request user input later
	int number = 0;

	//Begin while loop with 'number = -9999' as the exit condition
	while(number != -9999)
	{

		//Allocate a new memory address for *newNode pointer using 'new'
		newNode = new listNodes;

		//Request user input for 'number'
		cout << "\n**********************************************************************" << endl;
		cout << "Enter a single integer to add to the linked list. Enter -9999 to exit." << endl;
		cout << "\nInteger: ";
		cin >> number;

		//Replace the value of the data at the *newNode pointer with the user inputted value of 'number'
		newNode->info = number;

		//Set the link of the node at the *newNode pointer to nullptr
		newNode->link = nullptr;

		//If statement to check if the new node is the first in the list
		if (head == nullptr)
		{
			head = newNode;
			end = newNode;
		}

		//Else-if statement to check for the exit condition
		else if (number == -9999)
		{
			break;
		}

		//Else statement to continue appending
		else
		{
			end->link = newNode;
			end = newNode;
		}
	}
}

//Print function to display the list after appending
void listNodes::print()
{
	cout << "**********************************************************************" << endl;
	cout << "The entered list of integers is: ";

	//Create new pointer 'listNode* current' and set it equal to the first node on the list, so as to not lose data by moving *head
	listNodes* current = head;

	//While loop to print the linked list until *current reaches a node with a null link
	while (current != nullptr)
	{

		//cout statement to print the value of each node
		cout << "\n" << current->info;

		//Set *current to the value of the link of the next node to move forward in the list
		current = current->link;
	}
	cout << "\n**********************************************************************" << endl;
}

//Class destructor to delete the remaining nodes and set the pointers to null after printing the linked list
listNodes::~listNodes()
{

	//Create new pointer 'listNode* current' and set it equal to the first node on the list, so as to not lose data by moving *head
	listNodes* current = head;

	//While loop to print the linked list until *current reaches a node with a null link
	while (current != nullptr)
	{
		//Create new pointer 'listNodes* placeHolder' to delete nodes as *current moves along the linked list
		listNodes* placeHolder = current;

		//Set *current to the value of the link of the next node to move forward in the list
		current = current->link;

		//Delete *placeHolder as *current moves forward in the list
		delete placeHolder;
	}

	//Set *head to 'nullptr' after all nodes have been deleted
	head = nullptr;

	//Note: *current does not have to be sent to 'nullptr' because it must already be 'nullptr' to exit the while loop
}