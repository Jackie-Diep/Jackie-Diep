// TreesAssignment6.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>

using namespace std;

string getFile();
struct Node* Insert(struct Node*& Root, int data, int depth, int occurence);
void readInData(string fileName, struct Node*& Root);
void InOrder(struct Node* Root);
void processTree(struct Node* Root);
void writeInOrder(struct Node* Root, ofstream& writer);

//Nodes that will be used in the tree
//Holds data, depth, and Left/Right pointers
//Also holds an occurence counter for repeat iterations of data values
struct Node
{
    int data;
    int depth;
    struct Node* Left;
    struct Node* Right;
    int occurence;
};

int main(int argc, char* argv[])
{
    //Declare the string "fileName" to hold the file name
    string fileName;

    //Initialize a NULL Root pointer to start the tree
    struct Node* Root = NULL;

    //An if statement to determine whether or not the file name was passed in
    if (argc != 2)
    {
        fileName = getFile();
        cout << "Name:\t\t" << fileName << endl;
    }
    else
    {
        //Assigning the file name to fileName and outputting it to console
        fileName = argv[1];
        cout << "Name:\t\t" << fileName << endl;
    }

    //Call the function to read data in from the testFile.txt
    readInData(fileName, Root);

    //Call the function to print the tree in order from lowest to highest to the console
    InOrder(Root);

    //Call the function to print hte tree in order from lowest to highest to the file
    processTree(Root);
}

//Function to get the file name from the user if it was not passed in from the console
string getFile()
{

    //Declare string fileName to be returned to main
    string fileName;

    //Prompt and accept input for the fileName
    cout << "Enter the name of the text file. (including the file extension)" << endl;
    cout << "File Name: ";
    cin >> fileName;

    //Return the fileName to main
    return fileName;
}

//Function to insert data into the tree
struct Node* Insert(struct Node*& Root, int data, int depth, int occurence)
{

    //If this is the first node, create a new Root node, initialize its pointers to NULL
    //  Initialize its data to the first passed in data
    //  Initialize its depth and occurence to the passed in values

    //If the node has reached its place in the tree, create a new Root node, initialize its pointers to NULL
    //  Initialize its data to the current passed in data
    //  Initialize its depth and occurence to the current incremented values
    if (Root == NULL)
    {
        Root = new(Node);
        Root->data = data;
        Root->Left = NULL;
        Root->Right = NULL;
        Root->depth = depth;
        Root->occurence = occurence;
    }

    //If this is not the first node, increase the depth and call the function again
    //  If the data value is less than a previous data value, move it left.
    //  If the data value is greater than a previous data value, move it right.
    //  If the data value is the same as a previous data value, increase the occurence counter.
    else
    {
        if (data < Root->data)
        {  
            depth++;
            Root->Left = Insert(Root->Left, data, depth, occurence);

        }
        else if (data > Root->data)
        {
            depth++;
            Root->Right = Insert(Root->Right, data, depth, occurence);
        }
        else if (data = Root->data)
        {
            Root->occurence++;
        }
    }
    return Root;
}

//Function to display the tree in order from least to lowest, also displaying depth and occurence when necessary.
void InOrder(struct Node *Root)
{
    if(Root)
    {
        //Call the function repeatedly to the left until the lowest number is reached
        InOrder(Root->Left);

        //Print the current root value and depth, accounting for occurence when necessary
        if(Root->occurence == 1)
        {
            cout << "Data:   " << Root->data << "\tDepth:   " << Root->depth << endl;
        }
        else
        {
            cout << "Data:   " << Root->data << "\tDepth:   " << Root->depth << "\tOccurence: " << Root->occurence << endl;
        }

        //Call the function repeatedly to the right until the highest number is reached
        InOrder(Root->Right);
    }
}

//Function to print the tree to the file in order from least to lowest, also displaying depth and occurence when necessary.
void writeInOrder(struct Node *Root, ofstream& writer)
{
    if (Root)
    {

        //Call the function repeatedly to the left until the lowest number is reached
        writeInOrder(Root->Left, writer);

        //Print to the file the current root value and depth, accounting for occurence when necessary
        if (Root->occurence == 1)
        {
            writer << "Data:   " << Root->data << "\tDepth:    " << Root->depth << endl;
        }
        else
        {
            writer << "Data:   " << Root->data << "\tDepth:    " << Root->depth << "\tOccurence: " << Root->occurence << endl;
        }

        //Call the function repeatedly to the right until the highest number is reached
        writeInOrder(Root->Right, writer);
    }
}


//Function to read data in from the file
void readInData(string fileName, struct Node*& Root)
{

    //Declare int data to hold the values of the file
    int data;

    //Create a stream reader named readFile
    ifstream readFile;

    //Open the specified file
    readFile.open(fileName, ios::in);

    //Check whether or not the file was opened
    if (!readFile)
    {
        cout << "Unable to open the specified file " << fileName << " for reading." << endl;
    }

    //If the readFile check is passed move on
    else
    {

        //State what values will be considered errors and ignored
        cout << "\nNon-digit entries will be ignored." << endl;
        cout << "Digits less than 0 will be ignored." << endl;
        cout << "Digits greater than 99 will be ignored." << endl;
        cout << "-----------------------------------------------------------------------" << endl;
        //While loop to stop reading the file at end of file (eof())
        while (!readFile.eof())
        {

            //Check for word errors by whether or not a value was passed into int "data"
            if (!(readFile >> data))
            {

                //If no value was passed, check for end of file and break if true
                if (readFile.eof())
                    break;

                //If not end of file, clear the reader and move on
                readFile.clear();
                readFile.ignore();
            }

            //If a value was passed into int "data"
            else
            {

                //If the value is not between 0 and 99 (inclusive), move on
                if (data < 0 || data > 99);

                //If the value is between 0 and 99, push the data into the tree
                else if (data >= 0 && data <= 99)
                {
                    int depth = 0;
                    int occurence = 1;
                    Insert(Root, data, depth, occurence);
                }

                //Catch-all if statement, just in case
                else
                {
                    cout << "Unspecified error from read in data" << endl;
                }
            }
        }
    }

    //Close the stream reader after fully reading the file and reaching end of file
    readFile.close();
}

//Void function definition that will process the information from the tree into the "tree.txt" file
void processTree(struct Node *Root)
{

    //Declare the name of the file "tree.txt"
    string treeFileName = "tree.txt";

    //Create an out stream writer named writeTree
    ofstream writeTree;

    //Open or create the "tree.txt" file to be written into
    writeTree.open(treeFileName);

    //Check whether or not the file was opened or created
    if (!writeTree)
    {
        cout << endl << "Could not create/open " << treeFileName << "for writing." << endl;
    }

    //If the writeTree check is passed, call the writeInOrder function to write to the data file
    else
    {
        writeInOrder(Root, writeTree);
    }

    //Close the out stream writer
    writeTree.close();
}