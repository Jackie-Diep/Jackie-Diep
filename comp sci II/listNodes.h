#pragma once

//listNodes class header file
class listNodes
{
private:
	
	//Private data member 'int info' to store the values of the nodes
	int info;

	//Private data member pointers used to create and append to the linked list
	listNodes* head, * link, * end, * newNode;

public:

	//Default constructor
	listNodes();

	//Append function to add nodes to the end of the linked list
	void append();

	//Print function to print the linked list after the append function is complete
	void print();

	//Destructor of the class to delete nodes and set the pointers to null at the end of use
	~listNodes();
};

