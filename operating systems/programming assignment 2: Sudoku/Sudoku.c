// Sudoku.c : This program 
//

#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <stdlib.h>
#include <string.h>

// Struct to transfer data to the threads
struct parameters{
    int row;
    int column;
    int matrix[9][9];
};

// Function prototypes for the thread work functions
void* rowThread(void* data);
void* columnThread(void* data);
void* squareThread(void* data);

int main()
{

    // Initialize array for thread passback values
    int validationArray[11] = { 0 };

    // Initialize pointer to hold thread passbacks
    int* ptr;

    // Initialize matrix to be validated
    int sudoku[9][9] = {
        {6, 2, 4, 5, 3, 9, 1, 8, 7},
        {5, 1, 9, 7, 2, 8, 6, 3, 4},
        {8, 3, 7, 6, 1, 4, 2, 9, 5},
        {1, 4, 3, 8, 6, 5, 7, 2, 9},
        {9, 5, 8, 2, 4, 7, 3, 6, 1},
        {7, 6, 2, 3, 9, 1, 4, 5, 8},
        {3, 7, 1, 9, 5, 6, 8, 4, 2},
        {4, 9, 6, 1, 8, 2, 5, 7, 3},
        {2, 8, 5, 4, 7, 3, 9, 1, 6} };

    // Output matrix
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            printf(" %d", sudoku[i][j]);
        }
        printf("\n");
    }

    // Initialize thread ids
    pthread_t tid0;
    pthread_t tid1;
    pthread_t tid2;
    pthread_t tid3;
    pthread_t tid4;
    pthread_t tid5;
    pthread_t tid6;
    pthread_t tid7;
    pthread_t tid8;
    pthread_t tid9;
    pthread_t tid10;
    pthread_t* pthreads[] = { &tid0, &tid1, &tid2, &tid3, &tid4, &tid5, &tid6, &tid7, &tid8, &tid9, &tid10 };

    // Initialize pointer parameter struct for row and column threads
    struct parameters* data = (struct parameters*)malloc(sizeof(struct parameters));

    // Initialize pointer parameter struct array for 3 x 3 test threads
    struct parameters* squareData[9];

    // Allocate memory for parameter struct array
    for (int i = 0; i < 9; i++)
    {
        squareData[i] = malloc(sizeof(struct parameters));
    }

    // Copy matrix to parameter struct for row and columns
    memcpy(data->matrix, sudoku, sizeof(data->matrix));

    // Loop to initialize the threads
    for (int i = 0; i < 11; i++)
    {

        // First nine threads are 3 x 3 Test Threads
        if (i < 9)
        {

            // First three threads will be the top three squares
            if (i < 3)
            {
                squareData[i]->row = 0;
            }

            // Second three threads will be the middle three squares
            else if (i < 6)
            {
                squareData[i]->row = 3;
            }

            // Third three threads will be the bottom three squares
            else if (i < 9)
            {
                squareData[i]->row = 6;
            }

            // Copy the matrix to each struct in the array as it loops
            memcpy(squareData[i]->matrix, sudoku, sizeof(squareData[i]->matrix));

            // Calculate the appropriate column to begin per thread
            squareData[i]->column = i % 3 * 3;

            //Create the 3 x 3 Square test threads passing in the array struct element
            pthread_create(pthreads[i], NULL, squareThread, (void*)squareData[i]);
        }

        // The tenth thread will be the Row test thread
        else if (i == 9)
        {

            // Initialize the struct elements to start from the beginning
            data->row = 0;
            data->column = 0;

            // Create the Row test thread and pass in the struct
            pthread_create(pthreads[i], NULL, rowThread, (void*) data);
        }

        // The eleventh thread will be the Column test thread
        else if (i == 10)
        {

            // Initialize the struct elements to start from the beginning
            data->row = 0;
            data->column = 0;

            // Create the Column test thread and pass in the struct
            pthread_create(pthreads[i], NULL, columnThread, (void*) data);
        }
    }

    // Wait for the threads to finish and output the returned values into the passback array
    for (int i = 0; i < 11; i++)
    {
        pthread_join(*pthreads[i], (void*)&ptr);
        validationArray[i] = *ptr;
    }


    int solutionCheck = 1;
    // Output the validation array
    // A "0" signifies an invalid test; A "1" signifies a successful test
    for (int i = 0; i < 11; i++)
    {

        // Check if the solution is invalid
        if (validationArray[i] == 0)
        {
            solutionCheck = 0;
        }
        printf("\nValidation Array[%d]: \t%d", i, validationArray[i]);
    }

    // Output whether the solution was valid or invalid
    if (solutionCheck == 0)
    {
        printf("\n***************************************");
        printf("\nSolution: Incorrect\n\n");
    }
    else if (solutionCheck == 1)
    {
        printf("\n***************************************");
        printf("\nSolution: Correct!\n\n");
    }

    // Free the malloc()'d elements
    for (int i = 0; i < 9; i++)
    {
        free(squareData[i]);
    }
    free(data);
}

// Row thread work function that takes in parameters of a struct
void* rowThread(void* data)
{
    
    // Initialize a pointer to be returned
    int* validator = (int*)malloc(sizeof(int));
    *validator = 1;

    // Create a parameter pointer struct equal to the struct passed in
    struct parameters* rowData = (struct parameters*) data;

    // Create variables to be iterated upon to avoid overlap in threads
    int row = rowData->row;
    int column = rowData->column;

    // Iterate through the rows, if a repeat value is found within a row, set the validator to 0 and return it
    // If the value is not a repeat, add it to the array of found values and keep going until the end of the row
    // Repeat the process through all of the rows until either a repeat is found, or the end of the matrix is reached
    for (row; row < 9; row++)
    {

        // Initialize an array to hold found matrix values and reset column every loop
        int rowArray[9] = { 0 };
        column = 0;
        for (column; column < 9; column++)
        {
            if (rowArray[rowData->matrix[row][column] - 1] != 0)
            {
                //printf("\nFailed\n");
                *validator = 0;
                return validator;
            }
            else
            {
                rowArray[rowData->matrix[row][column] - 1] = rowData->matrix[row][column];
                //printf("\nrowArray %d: %d", column + 1, rowArray[rowData->matrix[row][column] - 1]);
            }
        }
        //printf("\nNext row");
    }

    // Return the validator amount
    return validator;
};

// Column thread work function that takes in parameters of a struct
void* columnThread(void* data)
{

    // Initialize a pointer to be returned
    int* validator = (int*)malloc(sizeof(int));
    *validator = 1;

    // Create a validator pointer to a struct equal to the struct passed in
    struct parameters* colData = (struct parameters*) data;

    // Create variables to be iterated upon to avoid overlap in threads
    int row = colData->row;
    int column = colData->column;

    // Iterate through the columns, if a repeat value is found within a column, set the validator to 0 and return it
    // If the value is not a repeat, add it to the array of found values and keep going until the end of the column
    // Repeat the process through all of the columns until either a repeat is found, or the end of the matrix is reached
    for (column; column < 9; column++)
    {

        // Initialize an array to hold found matrix values and reset row every loop
        int colArray[9] = { 0 };
        row = 0;
        for (row; row < 9; row++)
        {
            if (colArray[colData->matrix[row][column] - 1] != 0)
            {
                //printf("\nFailed\n");
                *validator = 0;
                return validator;
            }
            else
            {
                colArray[colData->matrix[row][column] - 1] = colData->matrix[row][column];
                //printf("\ncolArray %d: %d", column + 1, colArray[colData->matrix[row][column] - 1]);
            }
        }
        //printf("\nNext column");
    }

    // Return the validator amount
    return validator;
};

// Square thread work function that takes in an element of the struct pointer array
void* squareThread(void* data)
{

    // Initialize a pointer to be returned
    int* validator = (int*)malloc(sizeof(int));
    *validator = 1;

    // Create a validator pointer to a struct equal to the struct passed in
    struct parameters* squareData = (struct parameters*) data;

    // Create variables to be iterated upon to avoid overlap in threads
    int row = squareData->row;
    int column = squareData->column;

    // Create variables to mark the bounds of the 3 x 3 square
    int rowBound = row + 3;
    int columnBound = column + 3;

    // Initialize an array to hold found matrix values
    int sqArray[9] = { 0 };

    // Iterate through the squares, if a repeat value is found within a square, set the validator to 0 and return it
    // If the value is not a repeat, add it to the array of found values and keep going until the end of the square
    // Repeat the process through the entire square until either a repeat is found, or the end of the square is reached
    for (row; row < rowBound; row++)
    {
        //printf("\n");

        // Reset column back to the beginning value every loop
        column = columnBound - 3;
        for (column; column < columnBound; column++)
        {
            if (sqArray[squareData->matrix[row][column] - 1] != 0)
            {
                *validator = 0;
                return validator;
            }
            else
            {
                sqArray[squareData->matrix[row][column] - 1] = squareData->matrix[row][column];
                //printf(" %d", sqArray[squareData->matrix[row][column] - 1]);
            }
        }
    }
    //printf("\nValidation: %d", *validator);
    //printf("\nnew square \n");

    // Return the validator amount
    return validator;
}