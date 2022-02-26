
/*
This file displays a project that uses a C program as a shell interface.
The project requires four parts:
    Modify a given function to fork a child process and execute the command it is given
    Implement a history feature that repeats the last command with basic error checking
    Modify the shell to support redirectional operators (May assume that only one will be used per command)
    Modify the shell to allow the output of one command to serve as input to another using a pipe
        (May assume that command will only contain
        one pipe character and no redirectional
        operators)

*****************************File I backed up after having the command line's vertical bar '|' be noticed during parsing.
                                From this point onwards all testing was done on the UnixShellProjectTestingFile.c

@file UnixShellProject.c
@author Jackie Diep
@date 10 / 18 / 2020
*/


/*
gcc UnixShellProject.c -o test
*/


#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>
#include <fcntl.h>

#define MAX_LINE 80 /* The maximum length command */

int main(void)
{
    char* args[MAX_LINE / 2 + 1]; /* command line arguments */
    char* pipeArgs[MAX_LINE / 2 + 1]; /* command line arguments */
    int should_run = 1; /* flag to determine when to exit program */
    /* Created a string to hold history feature buffer */
    char historyString[40];

    int ampCheck = 0; /* to note the existence of an ampersand */

    /*Referencing the "Implementation of Pipe in Linux" from slideshare.net*/
    int fd_pipes[2];

    /* Indexer to the pipeArgs[] array */
    int pipeIndex = 0;

    while (should_run) {
        printf("osh>");
        /** Prompt for user input **/
        fflush(stdout); /* To clear the output buffer from each process */
        /**
        * After reading user input, the steps are:
        * (1) fork a child process using fork()
        * (2) the child process will invoke execvp()
        * (3) parent will invoke wait() unless command included &
        */

        /* Referenced educativ.io to learn how the strtok function works */
        char string[40];    /* character array to hold the command line; size of 40 for max size */
        fgets(string, sizeof string, stdin);
        char* tokenParser = strtok(string, " \n");

        /* int i to index the args array and use it with tokenParser */
        int i = 0;


        /* int ampCheck to keep track of whether or not a lone asterisk was used in the command */
        ampCheck = 0;

        /* int historyCheck to keep track of whether or not a '!!' prompt was passed in the command */
        int historyCheck = 0;

        /* int pipeCheck to keep track of whether or not a pipe was used */
        /* (More often than not bricked the program) */
        int pipeCheck = 0;

        /* int fd to handle redirection operators and the dup2 function */
        int fd;

        /* while loop to end when strtok is done going through the command line */
        while (tokenParser != NULL)
        {
            /* If history feature used if-else and nested if-else to error check and re-use the last command */
            if (strcmp(tokenParser, "!!") == 0)
            {

                // Check if history buffer is empty and reprompt for input
                if (strcmp(historyString, "") == 0)
                {
                    printf("No commands in history\n");
                    historyCheck = 1;
                }

                //If history buffer is not empty use buffered string as args
                else
                {
                    strcpy(string, historyString);
                    tokenParser = strtok(string, " \n");
                }
            }

            /* If history feature is not used, process the command line with strtok */
            else
            {

                /* Nested if-else-if structure to handle redirectional operators and to process the command line */
                if (strcmp(tokenParser, "<") == 0)
                {
                    args[i] = tokenParser;

                    /* iterate tokenParser passed the operator */
                    if (tokenParser != NULL)
                    {
                        tokenParser = strtok(NULL, " \n");
                        args[i] = tokenParser;
                    }
                    
                    /* open a read only version of the file whose name was passed into args */
                    fd = open(args[i], O_RDONLY);

                    /* Replace STDIN with file descriptor and iterate the indexer */
                    dup2(STDIN_FILENO, fd);
                    i++;
                }

                //If output using file
                else if (strcmp(tokenParser, ">") == 0)
                {
                    args[i] = tokenParser;

                    /* iterate tokenParser passed the operator */
                    if (tokenParser != NULL)
                    {
                        tokenParser = strtok(NULL, " \n");
                        args[i] = tokenParser;
                    }

                    /* open a write only version of the file whose name was passed into args */
                    fd = open(args[i], O_WRONLY);

                    /* Replace file descriptor with STDOUT and iterate the indexer */
                    dup2(fd, STDOUT_FILENO);
                    i++;
                }

                //If an asterisk is used
                else if (strcmp(tokenParser, "&") == 0)
                {
                    ampCheck = 1;
                    i++;
                }

                //If a vertical bar is used
                else if (strcmp(tokenParser, "|") == 0)
                {
                    printf("Vertical bar used.");
                    tokenParser = strtok(NULL, " \n");
                    pipeArgs[0] = tokenParser;
                }

                //Update the args with the current command line token and iterate the indexer
                else
                {
                    args[i] = tokenParser;
                    i++;
                }
            }

            /* move tokenParser forward*/
            tokenParser = strtok(NULL, " \n");
        }

        /* Because i would have been indexed one last time before the loop ended, set args[i] to NULL to terminate the char array there */
        args[i] = NULL;

        /* For Error Checking*/
        /*for (int j = 0; j < i; j++)
        {
            printf("\nargs[j] = %s\n", args[j]);
            printf("j = %d\n", j);
        }
        if (pipeArgs[0] != NULL)
        {
            printf("\npipeArgs[0] = %s\n", pipeArgs[0]);
        }
        sleep(2);*/

        /* if the history function was called with an empty buffer, skip the loop and prompt for another user input */
        if (historyCheck != 1)
        {

            /* Referenced slide 3.28 for error checking if-else structure */
            /* Assign a process ID data type variable */
            pid_t pid;

            /* Use the procID variable to fork a child process */
            pid = fork();

            /* Error checking of process forking */
            if (pid < 0) {
                fprintf(stderr, "Fork Failed");
                return 1;
            }
            else if (pid == 0) {
                /* execvp prototype : execvp(char *command, char *params[] ) */
                execvp(args[0], args);
                return 0;
            }
            else {

                /* If an asterisk was used */
                if (ampCheck == 1)
                {
                    printf("Parent did not wait\n");
                }

                /* else if block that checks for the pipeCheck */
                else if (pipeCheck == 1)
                {
                    printf("In the parent pipe else if");
                }

                /* Close the program with exit */
                else if (strcmp(args[0], "exit") == 0)
                {
                    should_run = 0;
                }

                /* Wait for the child to complete if neither asterisk or exit */
                else
                {

                    wait(NULL);
                    printf("\nChild Complete\n");
                }

                // copy the previous command to the history buffer
                strcpy(historyString, string);
            }
        }
    }
    return 0;
}