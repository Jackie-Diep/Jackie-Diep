/*
    This program will use a basic singly-linked list "node" struct to create a linked list in four different organizations. The size of the linked list will
    be found through either command line arguments or user input, and a file will be generated with an amount of numbers equal to the specified size. 
    These numbers will be between 0 and 99, and the size of the linked list will be between 20 and 100 nodes (inclusive).

    The four organitions in this program will be

    1.  Order of generation
    2.  Backwards order of generation
    3.  Highest to lowest value
    4.  Lowest to highest value

    March 15, 2020

    Jackie Diep
    University of Southern Mississippi
    307 Data Structures Homework Assignment 2
*/

//Header Files for output, file operation, string usage, and the C time library
#include <iostream>
#include <fstream>
#include <string>
#include <ctime>

using namespace std;

//Define the struct "node" to be the building blocks of the singly-linked list.
//First node = head
//Middle nodes = next
//Last node = NULL
struct node
{
    int number;
    node* next;
};

//Function prototype to either prompt the user to enter an integer between 20 and 100 (inclusive) for the size of the linked list or use the number
//  passed in through the command line
int getSize(int argc, char* argv[]);

//Function prototype to create a binary file "numbers.bin" and randomly generate an amount of numbers equal to the chosen size integer that are between 0 and 99
void createFile(int size);

//Function prototype to open the "numbers.bin" file and create a singly-linked list in the order that the numbers were generated and read into the file.
void createList(int size);

//Function prototype to open the "numbers.bin" file and create a singly-linked list in the opposite order that the numbers were generated and read into the file.
void createListBackwards(int size);

//Function prototype to open the "numbers.bin" file and create a singly-linked list from highest to lowest based on the numbers read into the file.
void createListHighLow(int size);

//Function prototype to open the "numbers.bin" file and create a singly-linked list from highest to lowest based on the numbers read into the file.
void createListLowHigh(int size);

//Function prototype to display the linked list at 5 per line separated by a tab
void printList(node* head);

//Function prototype to delete the linked list
void deleteList(node* head);
 
//**************************************************************************************************************************************
//Main begins here
int main(int argc, char *argv[])
{
    //Declare the integer variable "size" to hold the size of the linked lists and call the getSize function to either use command line arguments or 
    //  a user enterred value to determine the value of "size"
    int size = getSize(argc, argv);

    //If the size function passes successfully
    if (size != 1)
    {

    //Call the createFile function to randomly generate values a number of values equal to the chosen size between 0 and 99
        createFile(size);
        cout << endl << endl;

    //Call the createList function to create a singly-linked list in the order 
    //  that which the numbers were generated and read into the "numbers.bin" file that will call both
    //  the printList and deleteList functions after creation of the singly-linked list
        cout << "Original list" << endl;
        createList(size);

    //Call the createList function to create a singly-linked list in the order opposite that 
    //  which the numbers were generated and read into the "numbers.bin" file that will call both
    //  the printList and deleteList functions after creation of the singly-linked list
        cout << "Backwards Original list" << endl;
        createListBackwards(size);

    //Call the createList function to create a singly-linked list in the order highest to lowest in value
    //  from the "numbers.bin" file that will call both
    //  the printList and deleteList functions after creation of the singly-linked list
        cout << "Highest to Lowest list" << endl;
        createListHighLow(size);

    //Call the createList function to create a singly-linked list in the order lowest to highest in value
    //  from the "numbers.bin" file that will call both
    //  the printList and deleteList functions after creation of the singly-linked list
        cout << "Lowest to Highest list" << endl;
        createListLowHigh(size);
    }
}
//Main ends here
//**************************************************************************************************************************************

//Function description to either prompt the user to enter an integer between 20 and 100 (inclusive) 
//  for the size of the linked list or use the number passed in through the command line
int getSize(int argc, char* argv[])
{
    //Declare integer variable "size"
    int size;
    
    //If no command line argument was passed in for size, prompt the user for size
    if (argc != 2)
    {
        cout << "Please enter a number between 20 and 100 to determine the size of the linked list." << endl;
        cout << "Size: ";
        cin >> size;
    }

    //If a command line argument was passed in for size, set it equal to size
    else
    {
        size = atoi(argv[1]);
    }

    //If size is not within the bounds of 20 and 100 (inclusive), state the error and return error code (1)
    if (size < 20 || size > 100)
    {
        cout << "The size of the list must be between 20 and 100." << endl;
        return (1);
    }

    //If size is valid, return size to main
    else
    {
        return size;
    }
}

//Function description to create a binary file "numbers.bin" and randomly 
//  generate an amount of numbers equal to the chosen size integer that are between 0 and 99
void createFile(int size)
{
    
    //Seed the ranodm function with the time from the computer
    srand((unsigned)time(NULL));

    //Set string variable "fileName" to "numbers.bin", which will be the name of the generated file.
    string fileName = "numbers.bin";

    //Create an out stream writer named writeFile
    ofstream writeFile;

    //Open or create a file with the selected fileName. Use the stream writer to write in binary data
    writeFile.open(fileName, ios::out | ios::binary);

    //Check whether or not the file was opened or created
    if (!writeFile)
    {
        cout << endl << "Could not create/open numbers.bin for writing." << endl;
    }

    //If the writeFile check is passed move on
    else
    {

        //For loop to randomly generate and write data to the file between 0 and 99 in value
        for (int i = 0; i < size; i++)
        {
            int newNumber;
            newNumber = (rand() * rand()) % 100;
            writeFile.write(reinterpret_cast<const char*>(&newNumber), sizeof(int));
        }

        //Close the out stream writer writeFile
        writeFile.close();
    }
}

//Function description to open the "numbers.bin" file and create a 
//  singly-linked list in the order that the numbers were generated and read into the file.
void createList(int size)
{
    
    //Create pointer for head to keep track of the beginning of the list
    node* head;

    //Create a new node and set it equal to head
    head = new(node);

    //Check to see if the node assigned to head got created
    if (head == NULL)
    {
        cout << endl << "Could not create head node." << endl;
    }

    //If the head creation check is passed move on
    else
    {

        //Create a stream reader named readFile
        ifstream readFile;

        //Open the "numbers.bin" file created previously
        readFile.open("numbers.bin", ios::in | ios::binary);

        //Check if "numbers.bin" was opened
        if (!readFile)
        {
            cout << "\nCould not open numbers.bin for reading.\n" << endl;
        }

        //If the check for "numbers.bin" was successful move on
        else 
        {
            //Declare variable newNumber and set the head point to NULL because it is the last point in the list currently
            int newNumber;
            head->next = NULL;

            //For loop to fill in the linked list
            for (int i = 0; i < size; i++)
            {
                //Create a current pointer equal to head pointer to avoid a memory leak and a newNode pointer to begin adding nodes to the linked list
                node* current = head;
                node* newNode;

                //Read data from the file into the newNumber variable
                readFile.read((char*)&newNumber, sizeof(int));

                //Traverse the linked list until the NULL pointer to add to the end
                while (current->next != NULL)
                {
                    current = current->next;
                }

                //Create a newNode and check if memory was allocated
                if ((newNode = new(node)) == NULL)
                {
                    cout << "Failed to allocate enough memory." << endl;
                }

                //If the check for the newNode was successful move on
                else
                {
                    //set newNode's number value to the next read in number from the file
                    newNode->number = newNumber;

                    //Set newNode's next pointer to the pointer of current's next pointer
                    newNode->next = current->next;

                    //Set current's next pointer to point to the newNode
                    current->next = newNode;
                }
            }

            //Close the stream reader readFile
            readFile.close();

            //Call the function to print the linked list
            printList(head);

            //Call the function to delete the linked list
            deleteList(head);
        }
    }

}

//Function description to open the "numbers.bin" file and create a singly-linked list in the opposite
//  order that the numbers were generated and read into the file.
void createListBackwards(int size)
{
    //Create pointer for head to keep track of the beginning of the list
    node* head;

    //Create a new node and set it equal to head
    head = new(node);

    //Check to see if the node assigned to head got created
    if (head == NULL)
    {
        cout << endl << "Could not create head node." << endl;
    }

    //If the head creation check is passed move on
    else
    {

        //Create a stream reader named readFile
        ifstream readFile;

        //Open the "numbers.bin" file created previously
        readFile.open("numbers.bin", ios::in | ios::binary);

        //Check if "numbers.bin" was opened
        if (!readFile)
        {
            cout << "\nCould not open numbers.bin for reading.\n" << endl;
        }

        //If the check for "numbers.bin" was successful move on
        else
        {

            //Declare variable newNumber and set the head point to NULL because it is the last point in the list currently
            int newNumber;
            head->next = NULL;

            //For loop to fill in the linked list
            for (int i = 0; i < size; i++)
            {

                //Create a current pointer equal to head pointer to avoid a memory leak and a newNode pointer to begin adding nodes to the linked list
                node* current = head;
                node* newNode;

                //Read data from the file into the newNumber variable
                readFile.read((char*)&newNumber, sizeof(int));

                //Create a newNode and check if memory was allocated
                if ((newNode = new(node)) == NULL)
                {
                    cout << "Failed to allocate enough memory." << endl;
                }

                //If the check for the newNode was successful move on
                else
                {
                    //set newNode's number value to the next read in number from the file
                    newNode->number = newNumber;

                    //Set newNode's next pointer to the pointer of current's next pointer
                    newNode->next = head->next;

                    //Set head's next pointer to point to the newNode
                    head->next = newNode;
                }
            }
            //Close the stream reader readFile
            readFile.close();

            //Call the function to print the linked list
            printList(head);

            //Call the function to delete the linked list
            deleteList(head);
        }
    }
}


//Function description to open the "numbers.bin" file and create a singly-linked list from 
//  highest to lowest based on the numbers read into the file.
void createListHighLow(int size)
{

    //Create pointer for head to keep track of the beginning of the list
    node* head;

    //Create a new node and set it equal to head
    head = new(node);

    //Check to see if the node assigned to head got created
    if (head == NULL)
    {
        cout << endl << "Could not create head node." << endl;
    }

    //If the head creation check is passed move on
    else
    {

        //Create a stream reader named readFile
        ifstream readFile;

        //Open the "numbers.bin" file created previously
        readFile.open("numbers.bin", ios::in | ios::binary);

        //Check if "numbers.bin" was opened
        if (!readFile)
        {
            cout << "\nCould not open numbers.bin for reading.\n" << endl;
        }

        //If the check for "numbers.bin" was successful move on
        else
        {
            //Declare variable newNumber and set the head point to NULL because it is the last point in the list currently
            int newNumber;
            head->next = NULL;

            //For loop to fill in the linked list
            for (int i = 0; i < size; i++)
            {
                //Create a current pointer equal to head pointer to avoid a memory leak and a newNode pointer to begin adding nodes to the linked list
                node* current = head;
                node* newNode;

                //Read data from the file into the newNumber variable
                readFile.read((char*)&newNumber, sizeof(int));

                //Traverse the linked list until the newNumber is greater than the current spot in the linked list
                while (current->next != NULL && (current->next->number > newNumber))
                {
                    current = current->next;
                }

                //Create a newNode and check if memory was allocated
                if ((newNode = new(node)) == NULL)
                {
                    cout << "Failed to allocate enough memory." << endl;
                }

                //If the check for the newNode was successful move on
                else
                {
                    //set newNode's number value to the next read in number from the file
                    newNode->number = newNumber;

                    //Set newNode's next pointer to the pointer of current's next pointer
                    newNode->next = current->next;

                    //Set current's next pointer to point to the newNode
                    current->next = newNode;
                }
            }

            //Close the stream reader readFile
            readFile.close();

            //Call the function to print the linked list
            printList(head);

            //Call the function to delete the linked list
            deleteList(head);
        }
    }
}

//Function description to open the "numbers.bin" file and create a singly-linked list from 
//  lowest to highest based on the numbers read into the file.
void createListLowHigh(int size)
{
    //Create pointer for head to keep track of the beginning of the list
    node* head;

    //Create a new node and set it equal to head
    head = new(node);

    //Check to see if the node assigned to head got created
    if (head == NULL)
    {
        cout << endl << "Could not create head node." << endl;
    }

    //If the head creation check is passed move on
    else
    {

        //Create a stream reader named readFile
        ifstream readFile;

        //Open the "numbers.bin" file created previously
        readFile.open("numbers.bin", ios::in | ios::binary);

        //Check if "numbers.bin" was opened
        if (!readFile)
        {
            cout << "\nCould not open numbers.bin for reading.\n" << endl;
        }

        //If the check for "numbers.bin" was successful move on
        else
        {
            //Declare variable newNumber and set the head point to NULL because it is the last point in the list currently
            int newNumber;
            head->next = NULL;

            //For loop to fill in the linked list
            for (int i = 0; i < size; i++)
            {
                //Create a current pointer equal to head pointer to avoid a memory leak and a newNode pointer to begin adding nodes to the linked list
                node* current = head;
                node* newNode;

                //Read data from the file into the newNumber variable
                readFile.read((char*)&newNumber, sizeof(int));

                //Traverse the linked list until the newNumber is less than the current spot in the linked list
                while (current->next != NULL && (current->next->number < newNumber))
                {
                    current = current->next;
                }

                //Create a newNode and check if memory was allocated
                if ((newNode = new(node)) == NULL)
                {
                    cout << "Failed to allocate enough memory." << endl;
                }

                //If the check for the newNode was successful move on
                else
                {
                    //set newNode's number value to the next read in number from the file
                    newNode->number = newNumber;

                    //Set newNode's next pointer to the pointer of current's next pointer
                    newNode->next = current->next;

                    //Set current's next pointer to point to the newNode
                    current->next = newNode;
                }
            }

            //Close the stream reader readFile
            readFile.close();

            //Call the function to print the linked list
            printList(head);

            //Call the function to delete the linked list
            deleteList(head);
        }
    }
}

//Function definition to display the linked list at 5 per line separated by a tab
void printList(node* head)
{

    //Create a temp node to avoid losing the head node and a memory leak
    node* temp;

    //Set temp node equal to head's next pointer
    temp = head->next;

    //Declare integer variable "counter" and set it equal to 1 for formatting purposes
    int counter = 1;

    //Until temp is NULL, which signifies the end of this list, output elements of the linked list separated by tabs
    while (temp != NULL)
    {
        cout << temp->number << "\t";

        //If statement to format the linked list display
        if (counter % 5 == 0)
        {
            cout << endl;
            counter = 0;
        }

        //Move temp forward and increment the counter
        temp = temp->next;
        counter++;
    }
    cout << endl << endl;
}


//Function definition to delete the linked list
void deleteList(node* head)
{

    //Create a temp node to avoid losing the head node and a memory leak
    node* temp;

    //Until temp is NULL, which signifies the end of this list, set temp equal to head's next pointer,
    //  delete the memory that head is pointing to,
    //  set head equal to temp
    while (head != NULL)
    {
        temp = head->next;
        delete(head);
        head = temp;
    }
}
