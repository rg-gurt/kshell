#include "shell.h"
#include "input.h"
#include "parse.h"
#include "builtins.h"

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
    // exit should shut down shell only if it is the first word entered

    bool res = true;
    char copy[LINE_MAX_LENGTH];
    strcpy(copy, line);

    char *args[ARGS_MAX];
    int words = ksh_parse(copy, args, ARGS_MAX);

    if(words == 0){
        return true; //return true to keep running if nothing passed in  how does this even affect the boolean if words is an int?
    }

    if(copy[0] == '\0'){
        //empty, dont print
    }else if(strcmp(args[0], "exit") == 0){
        return false;
    }else{
        if (!ksh_run_builtin(args)) {
        printf("kshell: command not found: %s\n", args[0]);
    } 
        for(int i = 0; i < words; i++){
            printf("%s\n", args[i]);
        }
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