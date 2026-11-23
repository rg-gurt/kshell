#ifndef SHELL_H_
#define SHELL_H_

#include <stdbool.h>

/**
 * Runs one comand line.
 * - 'exit' stops the shell
 * - An empty line does nothing
 * - Anything else is echoed back as: 'you typed: <line>'
 * 
 * @param line - the command line (no trailing newline)
 * @return - true to keep the shell running, false to stop
 */
bool ksh_exec(const char *line);

/**
 * Runs the read -> execute loop until the user exits.
 * At end of input (Ctrl + D), prints a newline and stops.
 */
void ksh_loop(void);

#endif /* SHELL_H_ */