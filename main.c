#include "shell.h"
#include "input.h"

#include <stdlib.h>
#include <stdio.h>

/**
gcc -Wall -o kshell *.c && ./kshell
 */

int main(void){
    ksh_loop();

    return EXIT_SUCCESS;
}