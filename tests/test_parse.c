#include "parse.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
gcc -Wall -I. -o test_p tests/test_parse.c parse.c && ./test_p
*/
void show(const char *input) {
    char copy[256];
    char *args[ARGS_MAX];
    strcpy(copy, input);                 // strtok changes the string, so test on a copy
    int n = ksh_parse(copy, args, ARGS_MAX);

    printf("\"%s\" -> %d words:", input, n);
    for (int i = 0; i < n; i++) {
        printf(" [%s]", args[i]);
    }
    printf("   last=%s\n", args[n] == NULL ? "NULL" : "NOT NULL");
}

int main(void) {
    show("ls -l /home");
    show("   hello    world  ");
    show("");
    show("     ");
    show("exit");
    return 0;
}