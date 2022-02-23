/*
    This program will prompt the user for the name of a text file and process the integers within the text file. 
    Integers between 0 and 49 will be entered into a queue, and integers between 50 and 99 will be entered into a stack.
    Error handling will be used to ignore words, negative numbers, and numbers greater than 99.
    A text file will be created for the queue named "Queue.txt", and the data from the queue will be entered into the file. 
    Then, the average of the data will be outputted to console.
    A text file will be created for the queue named "Stack.txt", and the data from the stack will be entered into the file.
    Then, the average of the data will be outputted to console.

    March 15, 2020

    Jackie Diep
    University of Southern Mississippi
    307 Data Structures Homework Assignment 3
*/

//Header files needed for input/output, formatting, string usage, stack usage, and queue usage
#include <iostream>
#include <fstream>
#include <string>
#include <stack>
#include <queue>
#include <iomanip>

//Using statement to save time
using namespace std;

//String function prototype that will request the name of the text file
string getFile();

//Void function prototype that will read data from the file and organize the data into either the stack or the queue
//  Will use error checking
void readInData(string fileName, stack<int>* dataStack, queue<int>* dataQueue);

//Void function prototype that will process the information from the queue into the "Queue.txt" file and display the average of the elements of the queue
void processQueue(queue<int>*dataQueue);

//Void function prototype that will process the information from the stack into the "Stack.txt" file and display the average of the elements of the stack
void processStack(stack<int>* dataStack);

//**************************************************************************************************************************************
//Main begins here
int main()
{
    //Declare the string "fileName" to hold the file name and call the getFile() function to prompt the user for the file name
    string fileName;
    fileName = getFile();

    //Declare integer stack and queue dataStack and dataQueue respectively
    stack<int> dataStack;
    queue<int> dataQueue;
    
    //Call the readInData() function passing in fileName, dataStack, and dataQueue
    //  The readInData() function will open the specified file and organize the elements of the file into
    //  the queue for numbers between 0 and 49 or the stack for numbers between 50 and 99
    //  Error checking will be used within the function to manage words, negative numbers, and numbers greater than 99
    readInData(fileName, &dataStack, &dataQueue);

    //Call the processQueue() function passing in dataQueue so that it may create "Queue.txt" and pass in the values from the queue into the file
    //  The function will then display the average value of the elements of the queue
    processQueue(&dataQueue);

    //Call the processStack() function passing in dataStack so that it may create "Stack.txt" and pass in the values from the stack into the file
    //  The function will then display the average value of the elements of the stack
    processStack(&dataStack);
}
//Main ends here
//**************************************************************************************************************************************

//String function definition that will request the name of the text file
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

//Void function definition that will read data from the file and organize the data into either the stack or the queue
//  Will use error checking
void readInData(string fileName, stack<int>* dataStack, queue<int>* dataQueue)
{
    
    //Declare data to hold the values of the file
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

            //If a value was passed into int "data
            else
            {

                //If the value is not between 0 and 99 (inclusive), move on
                if (data < 0 || data > 99);

                //If the value is between 50 and 99, push the data into the dataStack
                else if (data >= 50 && data <= 99)
                {
                    dataStack->push(data);
                }

                //If the value is between 0 and 49, push the data into the dataQueue
                else if (data >= 0 && data <= 49)
                {
                    dataQueue->push(data);
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

//Void function definition that will process the information from the queue into the "Queue.txt" file and display the average of the elements of the queue
void processQueue(queue<int>*dataQueue)
{

    //Declare the name of the file "Queue.txt"
    string queueFileName = "Queue.txt";

    //Create an out stream writer named writeQueue
    ofstream writeQueue;

    //Declare queue Track and Count variables to display the average of the queue elements later
    int queueTrack = 0;
    int queueCount = 0;

    //Open or create the "Queue.txt" file to be written into
    writeQueue.open(queueFileName);

    //Check whether or not the file was opened or created
    if (!writeQueue)
    {
        cout << endl << "Could not create/open " << queueFileName << "for writing." << endl;
    }

    //If the writeQueue check is passed move on
    else
    {

        //While loop to end processing when the queue is empty
        while (!dataQueue->empty())
        {

            //Add the front value to queueTrack and increment queueCount for average calculation later
            queueTrack += dataQueue->front();
            queueCount++;

            //Write the front of the queue into the file and move to the next line
            writeQueue << dataQueue->front() << "\n";

            //Pop the front value of the queue and repeat with the next value
            dataQueue->pop();
        }

        //Calculate the average of the queue
        double queueAverage = static_cast<double>(queueTrack) / static_cast<double>(queueCount);
        cout << fixed << showpoint;

        //Output the total of all elements of the queue, the amount of elements of the queue, and the average of the queue
        cout << "\nTotal added to Queue.txt file: " << setprecision(2) << queueTrack << endl;
        cout << "Total items added to Queue.txt file: " << queueCount << endl;
        cout << "Average value of items added to Queue.txt file: " << queueAverage << endl;
    }

    //Close the out stream writer
    writeQueue.close();
}

//Void function definition that will process the information from the stack into the "Stack.txt" file and display the average of the elements of the stack
void processStack(stack<int>* dataStack)
{
    //Declare the name of the file "Stack.txt"
    string stackFileName = "Stack.txt";

    //Create an out stream writer named writeStack
    ofstream writeStack;

    //Declare stack Track and Count variables to display the average of the stack elements later
    int stackTrack = 0;
    int stackCount = 0;

    //Open or create the "Stack.txt" file to be written into
    writeStack.open(stackFileName);

    //Check whether or not the file was opened or created
    if (!writeStack)
    {
        cout << endl << "Could not create/open " << stackFileName << "for writing." << endl;
    }

    //If the writeStack check is passed move on
    else
    {

        //While loop to end processing when the stack is empty
        while (!dataStack->empty())
        {

            //Add the top value to stackTrack and increment stackCount for average calculation later
            stackTrack += dataStack->top();
            stackCount++;

            //Write the top of the stack into the file and move to the next line
            writeStack << dataStack->top() << "\n";

            //Pop the top value of the stack and repeat with the next value
            dataStack->pop();
        }

        //Calculate the average of the stack
        double stackAverage = static_cast<double>(stackTrack) / static_cast<double>(stackCount);
        cout << fixed << showpoint;

        //Output the total of all elements of the stack, the amount of elements of the stack, and the average of the stack
        cout << "\nTotal added to Stack.txt file: " << setprecision(2) << stackTrack << endl;
        cout << "Total items added to Stack.txt file: " << stackCount << endl;
        cout << "Average value of items added to Stack.txt file: " << stackAverage << endl;
    }

    //Close the out stream writer
    writeStack.close();
}