#include "shell.h"
#include "input.h"

#include <stdio.h>
#include <string.h>

/**
 * Runs one comand line.
 * - 'exit' stops the shell
 * - An empty line does nothing
 * - Anything else is echoed back as: 'you typed: <line>'
 * 
 * @param line - the command line (no trailing newline)
 * @return - true to keep the shell running, false to stop
 */
bool ksh_exec(const char *line){
    bool res = true;
    if (strcmp(line, "exit") == 0){
        res = false;
    } else if(line[0] == '\0'){
        //empty, dont print
    }else{
        printf("you typed: %s\n", line);
        res = true;
    }
    return res;
}
/**
 * Runs the read -> execute loop until the user exits.
 * At end of input (Ctrl + D), prints a newline and stops.
 */
void ksh_loop(void){
    char line[LINE_MAX_LENGTH];
    bool running = true;

    while(running){
        bool res = ksh_rd_ln(line, sizeof line);
        if(!res){ //if ctrl+d, input closed, loop spins otherwise 
            printf("\n");
            break;
        }
        running = ksh_exec(line);
    }
}