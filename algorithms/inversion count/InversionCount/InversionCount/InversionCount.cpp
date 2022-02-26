/* 

Jackie Diep
April 7, 2021
CSC 413

InversionCount.cpp : This file contains the 'main' function. 
This file computes the number of inversions provided by CSC 413 Course Programming Project 
    using a divide-and-conquer algorithm, and it outputs the sorted array to a text file.
The provided file, "IntegerArray.txt", inclusively contains every integer between 1 and 100,000 in some order with no repetitions.
*/

// Include I/O functionality and file operations
#include <iostream>
#include <fstream>

using namespace std;

// Prototype for a long long function sorts the array and counts inversions
long long mergeSort(int arr[], int temp[], int leftArray, int rightArray);

// Prototype for a function that merges two divided arrays and counts inversions
long long merge(int arr[], int temp[], int leftArray, int rightArray, int midArray);

//Prototype for a function that reads in the data of the txt file
void readFile(int *arr, string fileName);

//Prototype that outputs the sorted array to a txt file
void writeFile(int* arr, string fileName, long long inversionCount);

// Main function
int main()
{

    // Initializes two blank equally sized arrays
    int toCount[100000];
    int tempArray[100000];

    // Create an array pointer to the first initialized array
    int* tC;
    tC = toCount;

    // Initialize file names for I/O
    string fileName = "IntegerArray.txt";
    string outFileName = "SortedIntegerArray.txt";
    readFile(tC, fileName);

    long long inversionCount = mergeSort(toCount, tempArray, 0, 99999);
    cout << inversionCount << endl;

    
    /* 
    for (int i = 0; i < 100000; i++)
    {
        cout << toCount[i] << "\tcount: " << i + 1 << endl;
    }
    cout << "InversionCount:\t" << inversionCount << endl;
    */
    

    writeFile(tC, outFileName, inversionCount);
    tC = 0;
}

// Function that reads the txt file and inputs its values into the array toCount using the tC array pointer
void readFile(int* arr, string fileName)
{

    // Initialize temp int variable and open the if stream
    int tempInt;
    ifstream file(fileName);

    // If the if stream was successfully opened, input values into the array until eof or index > 99999
    if (file.is_open())
    {
        int index = 0;
        while (!file.eof() && index < 100000)
        {
            file >> tempInt;
            arr[index] = tempInt;
            index++;
        }

        // Close the if stream
        file.close();
    }
}

// Function that writes to the txt file and outputs the array values in sorted order
void writeFile(int* arr, string fileName, long long inversionCount)
{
    // Open the of stream
    ofstream file(fileName);

    // If the of stream was successfully opened write the elements of the array to the file
    if (file.is_open())
    {
        int index = 0;
        file << "Inversion count: " << inversionCount << endl;
        for (int i = 0; i < 100000; i++)
        {
            file << arr[index] << endl;
            index++;
        }

        //Close the of stream
        file.close();
    }
}

// Function that sorts the array and counts inversions
long long mergeSort(int arr[], int temp[], int leftArray, int rightArray)
{

    // Initialize variables midArray to divide the arrays and inversionCount
    int midArray;
    long long inversionCount = 0;

    // If structure to track when to stop recursion
    if (rightArray > leftArray) {
        midArray = (rightArray + leftArray) / 2;

        // Recursively call mergeSort and merge functions until only one element remains and increment inversionCount 
        //  with the return value
        inversionCount += mergeSort(arr, temp, leftArray, midArray);
        inversionCount += mergeSort(arr, temp, midArray + 1, rightArray);
        inversionCount += merge(arr, temp, leftArray, rightArray, midArray + 1);
    }

    // return inversionCount to previously called functions and main
    return inversionCount;
}

// Function that merges two divided arrays and counts inversions
long long merge(int arr[], int temp[], int leftArray, int rightArray, int midArray)
{

    // Initialize inversionCount and integers to maintain indexes on the arrays
    long long inversionCount = 0;
    int left = leftArray;
    int mid = midArray;
    int leftT = leftArray;

    // Until the left index hits the middle of the array or the middle index hits the right of the array
    while ((left <= midArray - 1) && (mid <= rightArray))
    {

        // If the value of the left index is less than or equal to the middle index of the array, 
        if (arr[left] <= arr[mid])
        {
            temp[leftT++] = arr[left++];
        }
        else
        {
            temp[leftT++] = arr[mid++];
            inversionCount = inversionCount + (midArray - left);
        }
    }

    // Iterate through to sorting the rest of the array
    while (left <= midArray - 1)
    {
        temp[leftT++] = arr[left++];
    }
    while(mid <= rightArray)
    {
        temp[leftT++] = arr[mid++];
    }
    for (left = leftArray; left <= rightArray; left++)
    {
        arr[left] = temp[left];
    }
    return inversionCount;
}