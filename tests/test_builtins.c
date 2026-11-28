#include <stdio.h>
#include "builtins.h"

/* Prints the command, runs it, then shows whether it was a built-in. */
static void run(char *args[]) {
    printf("> ");
    for (int i = 0; args[i] != NULL; i++) {
        printf("%s ", args[i]);
    }
    printf("\n");

    bool was_builtin = ksh_run_builtin(args);
    printf("   (built-in? %d)\n\n", was_builtin);
}

int main(void) {
    char *help[]    = {"help", NULL};
    char *echo2[]   = {"echo", "hi", "there", NULL};
    char *echo0[]   = {"echo", NULL};
    char *pwd[]     = {"pwd", NULL};
    char *cd_up[]   = {"cd", "..", NULL};
    char *cd_bad[]  = {"cd", "nope", NULL};
    char *cd_home[] = {"cd", NULL};
    char *ls[]      = {"ls", "-l", NULL};

    run(help);      // lists the commands
    run(echo2);     // hi there
    run(echo0);     // blank line
    run(pwd);       // current folder
    run(cd_up);     // go up one folder
    run(pwd);       // should be one folder higher
    run(cd_bad);    // cd: No such file or directory
    run(cd_home);   // go home
    run(pwd);       // should be your home folder
    run(ls);        // not a built-in: prints nothing, built-in? 0
    return 0;
}