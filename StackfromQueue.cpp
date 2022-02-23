/*
    This program will modify the Queue from Class example code to implement a Stack in place of the Queue. 

    Pushing, popping, and peeking from the Stack is required.
    Member functions similar to the example code must be implemented.
    Demonstrate each function similarly to the example code.

    April 5, 2020

    Jackie Diep
    University of Southern Mississippi
    307 Data Structures Homework Assignment 4
*/

//Input and output includes
#include <iostream>
#include <fstream>

//Include ctime for simple random number seeding
#include <ctime>

//Using statement to save time
using namespace std;

//Struct node used to create the stack
struct node
{
    //Variable storing the data
    int number;

    //Location of the next node in the stack
    node* below;
};

//Class 'stack' that will protect the data by controlling performable operations
class stack
{

    //Private variables of class 'stack'
private: 

    //Node pointer to keep track of the top. Stacks do not need to keep track of the bottom assuming the value is NULL.
    node* top;

    //Public variables of class 'stack'
public:

    //Default constructor that sets top pointer to NULL
    stack()
    {
        top = NULL;
        cout << endl << "*****************************" << endl;
        cout << "Stack Object Created" << endl;
        cout << "*****************************" << endl;
    }

    //Destructor for 'stack' class objects
    ~stack()
    {
        cout << endl << "*****************************" << endl;
        cout << "Stack Object Deleted" << endl;
        cout << "*****************************" << endl;
    }

    //Class member function that pushes data to the stack.
    int pushToStack(int data)
    {

        //Temp node to put into the stack
        node* temp = new node;

        //Check that the node was created and notify the user if it was not
        if (temp == NULL)
        {
            cout << endl << "***---Fatal error, could not create node.---***" << endl << endl;
            return (1);
        }

        //Check if this is the first node of the stack
        if (top == NULL)
        {

            //Enter the passed in data to the temp node
            temp->number = data;

            //If this is the first member of the stack, below it must be set to NULL
            temp->below = NULL;

            //Set the top node equal to the temp node
            top = temp;
        }

        //If this is not the first node of the stack
        else
        {

            //Enter the passed in data to the temp node
            temp->number = data;

            //Set the below pointer of the temp node to the current location of the top node
            temp->below = top;

            //Set the top node equal to the temp node
            top = temp;
        }
        return (0);
    }

    //Class member function that lets us peek at the top item in the stack
    int peekTopStack()
    {

        //If there exists any data, return the data from the top node
        if (top != NULL)
        {
            return top->number;
        }

        //If there is no data, alert the user that there is no data to return
        else
        {
            cout << endl << "Nothing to peek !!!" << endl;
            return NULL;
        }
    }

    //Class member function that gets the item from the top of the stack. The data is returned and the node is removed from the stack.
    //That means top is changed to the node below it afterwards
    int popFromStack()
    {

        //If there exists any data
        if (top != NULL)
        {

            //Store the value of the data from the top node into a local variable
            int data = top->number;

            //Create a temp node equal to the top node
            struct node* temp = top;

            //Move the top node the the one below it
            top = top->below;

            //Delete the data stored at the temp node
            delete temp;

            //Return the value of the local variable
            return data;
        }

        //If there is no data, alert the user that there is no data to return
        else
        {
            cout << endl << "Nothing to pop !!!" << endl;
            return NULL;
        }
    }

    //Member function to view everything in the stack. When this function is complete, everything in the stack will be removed.
    void viewStack()
    {

        //Counter for formatting and data counting
        int counter = 1;

        //Loop until there is no remaining data in the stack
        while (top != NULL)
        {

            //Call the member function to get and remove the top data from the stack and output it to the console
            cout << popFromStack() << "\t";

            //Start a new line for every 10 items displayed to the console
            if (counter % 10 == 0)
            {
                cout << endl;
            }

            //Increment the counter
            counter++;
        }

        //Output the amount of items that were outputted and removed from the stack
        cout << endl << endl << "Total items in the stack was " << counter - 1 << endl;
    }
};

//Function header prototypes
int getSize(int);
int createDataFile(int);
int doWork(int);

//Main starts here
int main(int argc, char *argv[])
{

    //If arg parameters are passed in, check if they are valid
    if (argc == 2)
    {

        //Created a local variable to hold the passed in quantity so that it can be passed to functions as needed
        int size = atoi(argv[1]);

        //If an invalid number was passed in, notify the user and call the getSize function
        if (!size || size < 0 || size > 100)
        {
            cout << "This is not a valid quantity." << endl;
            size = getSize(size);
        }

        //Call the doWork function and pass in the size
        doWork(size);
    }

    //If nothing was passed in from the command line
    else
    {

        //Create a local variable to hold the size
        int size = 0;

        //Call the getSize function to get the size from the user
        size = getSize(size);

        //Call the doWork function and pass in the size
        doWork(size);
    }

    //Exit the program
    return (0);
}

//Get the required quantity of data from the user
int getSize(int size)
{
    //Prompt the user for the desired size until a valid size is returned
    while (size < 1 || size > 100)
    {
        cout << endl;
        cout << "How much data do you want to generate (1 to 100)?" << endl;
        cin >> size;

        //If the entered value is invalid, clear the buffer and prompt the user again after notifying them that the value is invalid.
        if (cin.fail() || size < 1 || size > 100)
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << endl << "Invalid Option.";
        }
        cout << endl;
    }

    //Return the valid size to main
    return (size);
}


//Function to create the data file that will hold the data specified by the user
int createDataFile(int size)
{

    //Create an out stream reader named WriteBinary
    ofstream WriteBinary;

    //Open the file 'numbers.bin' and insure that it was opened
    WriteBinary.open("numbers.bin", ios::out | ios::binary);
    if (!WriteBinary)
    {
        cout << "Could not open binary file for writing." << endl << endl;
        return (1);
    }

    //Inform the user that writing has begun and the file name
    cout << "Writing file: numbers.bin" << endl << endl;

    //Seed the random function with the time from the computer
    srand(unsigned int(time(NULL)));

    //Create a local variable to hold the random data and a counter to count the amount of data for output
    int data = 0;
    int counter = 1;

    //Until the amount of data is equal to the specified size, create data and write it to the file
    for (int i = 0; i < size; i++)
    {
        data = rand() % 100;
        WriteBinary.write(reinterpret_cast<const char*>(&data), sizeof(int));
        cout << data << "\t";

        //Output written data to console with 10 values per line
        if (counter % 10 == 0)
        {
            cout << endl;
            counter = 0;
        }
        counter++;
    }

    //Close the out stream writer
    WriteBinary.close();

    //Inform the user that data was written
    cout << endl << endl << "The data file was created successfully." << endl;

    //Return to main
    return(0);
}

//Function that will call other functions and perform maintenance
int doWork(int size)
{

    //Pass the size from main into the createDataFile function
    createDataFile(size);

    //Create a stack to hold the data
    stack myStack;

    //Create a stream reader that will read in data from the created Binary file
    ifstream ReadBinary;
    ReadBinary.open("numbers.bin", ios::in | ios::binary);

    //Check that the file opened
    if (!ReadBinary)
    {
        cout << "Could not open binary file for reading." << endl << endl;
        exit(1);
    }

    //Create a local variable to hold the read in data
    int data = 0;

    //Create a loop that will run until all data is read into the stack
    while (ReadBinary)
    {
        //Read in a single piece of data
        ReadBinary.read((char*)&data, sizeof(int));

        //If we have reached the end of the file and no data was read, exit the loop
        if (ReadBinary.eof()) 
            break;

        //Push the data to the stack
        myStack.pushToStack(data);
    }

    //Call the function to view everything in the stack
    myStack.viewStack();

    //Peek to see if the stack is empty
    if (myStack.peekTopStack() != NULL)
    {
        cout << myStack.peekTopStack() << endl;
    }

    //Call the popFromStack function to make sure there is no data left, but catch the return of the function with data or the data will be 
    // lost
    data = NULL;
    data = myStack.popFromStack();

    //If something was read in from the stack, output it
    if (data != NULL)
    {
        cout << data << endl;
    }

    //Return to main
    return (0);
}