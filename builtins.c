#include "builtins.h"

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>

bool ksh_run_builtin(char *args[])
{
    // Check for help
    if (strcmp(args[0], "help") == 0)
    {
        /**
        * Print list of built-ins
        */
       printf("Built-in commands: \n");
       printf("help - Display available commands\n");
       printf("echo - Display text\n");
       printf("pwd  - Display current directory\n");
       printf("cd   - Change directory\n");

       return true;
    }

    // Check for echo
    if (strcmp(args[0], "echo") == 0)
    {
        /**
         * Display text
         */
        int i = 1;

        while (args[i] != NULL)
        {
            printf("%s", args[i]);

            if (args[i + 1] != NULL)
            {
                printf(" ");
            }

            i++;

        }

        printf("\n");
        return true;

    }

    // Check for pwd
    if (strcmp(args[0], "pwd") == 0)
    {
        /**
         * Print current working directory (location)
         */
        char cwd[1024];

        if (getcwd(cwd, sizeof(cwd)) != NULL)
        {
            printf("%s\n", cwd);
        }
        else
        {
            perror("pwd");
        }

        return true;
    }

    // Check for cd
    if (strcmp(args[0], "cd") == 0)
    {
        /**
         * Change current directory
         */
        char *directory;

        if (args[1] == NULL)
        {
            directory = getenv("HOME");
        }
        else
        {
            directory = args[1];
        }

        if (directory == NULL)
        {
            fprintf(stderr, "cd: HOME not set\n");
        }
        else if (chdir(directory) != 0)
        {
            perror("cd");
        }

        return true;

    }

    // Not a built-in command
    return false;

}