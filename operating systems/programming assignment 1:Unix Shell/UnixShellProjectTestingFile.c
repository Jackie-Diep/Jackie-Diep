
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

*******************  This was the file I was currently working on to try to implement the pipes in part four. Very rough and unfinished.

@file UnixShellProjectTestingFile.c
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

    /* Testing a char* buffer for the pipe to try to read into pipeArgs[] */
    char* pipeBuffer[1024];
    int should_run = 1; /* flag to determine when to exit program */
    /* Created a string to hold history feature buffer */
    char historyString[40];

    //Implementing a size variable to test a read function
    ssize_t bytes;

    int ampCheck = 0; /* to note the existence of an ampersand */

    /*Referencing the Implementation of Pipe in Linux from slideshare.net*/
    int fd_pipes[2];

    int saved_stdout = dup(STDOUT_FILENO); /* To test if it is required to restore STDOUT_FILENO after dup2 */
    int pid2 = -1; /* Integer to test if pid2 is created */

    while (should_run) {
        printf("\nosh>");
        /** Prompt for user input **/
        fflush(stdout);
        /**
        * After reading user input, the steps are:
        * (1) fork a child process using fork()
        * (2) the child process will invoke execvp()
        * (3) parent will invoke wait() unless command included &
        */

        /* Referenced educativ.io to learn how the strtok function works */
        char string[40];
        fgets(string, sizeof string, stdin);
        char* tokenParser = strtok(string, " \n");

        /* int i to index the args array and use it with tokenParser */
        int i = 0;

        /* int ampCheck to keep track of whether or not a lone asterisk was used in the command */
        ampCheck = 0;

        /* int historyCheck to keep track of whether or not a '!!' prompt was passed in the command */
        int historyCheck = 0;

        /* creating an int array with 2 elements for pipe usage */
        int fd_pipes[2];

        /* int pipeCheck to keep track of whether or not a pipe was used */
        /* (More often than not bricked the program) */
        int pipeCheck = 0;

        /* int fd to handle redirection operators and the dup2 function */
        int fd;
        pipeArgs[0] = NULL;



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
        /* Not performing this step caused intermittent errors for days */
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

        // Create a pipe and test for creation
        if (pipe(fd_pipes) < 0) {
            perror("Pipe Failed");
            return 1;
        }
        
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

            //Current pipe testing, largely incomplete and poorly implemented
            // If in child and not second child
            if ((pid == 0) && (pid2 < 0)) {

                // If no pipe, call execvp
                if (pipeArgs[0] == NULL)
                {
                    execvp(args[0], args);
                    return 0;
                }

                //If pipe exists, create second child
                else
                {

                    //fork pid2 and test for creation
                    int pid2 = fork();
                    if (pid2 < 0)
                    {
                        printf("Fork 2 failed");
                    }
                    else
                    {
                        printf("Fork 2 created successfully.");
                    }

                    /* current testing of dup2 configurations */
                    dup2(fd_pipes[1], STDOUT_FILENO);
                    close(fd_pipes[0]);
                    close(fd_pipes[1]);
                    execvp(args[0], args);
                    wait(NULL);
                }
            }

            //If in second child
            else if (pid == 0) {

                //Currently attempting to just change args instead of using pipeArgs[] array that I created
                //Very incomplete and where I left off to focus on the report instead
                args[0] = pipeArgs[0];
                printf("args[2]: %s", args[2]);
                dup2(fd_pipes[0], STDIN_FILENO);
                close(fd_pipes[1]);
                close(fd_pipes[0]);
                bytes = read(fd_pipes[0], pipeBuffer, 500);
                args[3] = (char*)bytes;
                execvp(args[2], args);
                printf("pid2 exec failed");
            }

            //Previous tests that I was unsure if I wanted to scrap yet or not
            /*else if (pid == 0 && pipeArgs[0] != NULL) {
                int pid2 = fork();
                if (pid2 == 0)
                {
                    
                    args[0] = pipeArgs[0];
                    printf("args[2]: %s", args[2]);
                    dup2(fd_pipes[0], STDIN_FILENO);
                    close(fd_pipes[1]);
                    close(fd_pipes[0]);
                    bytes = read(fd_pipes[0], pipeBuffer, 500);
                    args[3] = (char*)bytes;
                    printf("args3: %s", args[3]);
                    execvp(args[2], args);
                    printf("pid2 exec failed");
                    return 1;
                }
                else {
                    printf("\nargs[1]: %s\n", args[1]);
                    dup2(fd_pipes[1], STDOUT_FILENO);
                    close(fd_pipes[0]);
                    close(fd_pipes[1]);
                    execvp(args[0], args);
                    wait(NULL);
                    return 1;
                }
            }*/

            //In parent function
            else {
                /* If an asterisk was used */
                if (ampCheck == 1)
                {
                    printf("Parent did not wait\n");
                }


                /* Close the program with exit */
                else if (strcmp(args[0], "exit") == 0)
                {
                    should_run = 0;
                }

                /* Wait for the child to complete if neither asterisk or exit */
                else
                {

                // Testing if calling child node inside of parent function area would work
                // Stopped because it was causing while loop to break
                    /*if (pipeArgs != NULL) {
                        dup2(fd_pipes[1], STDOUT_FILENO);
                        close(fd_pipes[0]);
                        execvp(args[0], args);
                        close(fd_pipes[1]);
                    }*/
                        wait(NULL);
                        printf("\nChild Complete\n");
                }
                close(fd_pipes[0]);
                close(fd_pipes[1]);
                // copy the previous command to the history buffer
                strcpy(historyString, string);
            }
        }
    }
    return 0;
}