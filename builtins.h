#ifndef BUILTINS_H_
#define BUILTINS_H_

#include <stdbool.h>

/**
 * Runs args[0] if it is a built-in command: help, echo, pwd, cd.
 *
 * @param args - the words of the command line, ending in NULL
 * @return - true if args[0] was a built-in (and it ran), false if not
 */
bool ksh_run_builtin(char *args[]);

#endif /* BUILTINS_H_ */