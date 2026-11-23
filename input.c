#include "input.h"
#include <stdio.h>
#include <string.h>


/**
 * Prints the prompt "kshell>" and reads one line from the keyboard
 * The trailing newline is removed.
 * 
 * @param line - buffer to store the line in
 * @param size - size of the buffer
 * @return - true if a line was read, false at the end of an input
 */

 bool ksh_rd_ln(char *line, size_t size){
    printf("kshell> ");
    fflush(stdout); //fflush(stdout) to immediately empty stdout to console

    bool input = false;
    
    if(fgets(line, LINE_MAX_LENGTH, stdin) != NULL){
        line[strcspn(line, "\n")] = '\0';
        input = true;
    }else{
        input = false;
    }
    return input;

 }

 /**
  * takes a single line input from user and returns true or false (1/0) if input was detected using fgets
  */
