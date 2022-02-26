/*
File: SimpleLinkedList.cpp
Name: Jackie Diep
Date: 12/3/2019
Course: CSC 102
Description: Write a linked list class using nodes that contain a single integer. 
			Prompt the user to enter integers, stopping when a sentinel value is entered. 
			Add the integers to the end of your linked linked list in the order that they are entered.
*/

//Include the listNodes header file
#include "listNodes.h"

//Begin main function
int main()
{
	//Create object 'list' of the class 'listNodes'
	listNodes list;

	//Start the append() function on object 'list' to begin adding numbers to the nodes of the linked list
	list.append();

	//Start the print() function on object 'list' after the append function is complete to display the members of the linked list
	list.print();

	//Call the destructor after printing is complete to delete the nodes and set the pointers to null of the linked list
	list.~listNodes();
}