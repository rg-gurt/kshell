#ifndef INPUT_H_
#define INPUT_H_

#include <stdbool.h>
#include <stddef.h>

#define LINE_MAX_LENGTH 256

/**
 * Prints the prompt "kshell>" and reads one line from the keyboard
 * The trailing newline is removed.
 * 
 * @param line - buffer to store the line in
 * @param size - size of the buffer
 * @return - true if a line was read, false at the end of an input
 */

 bool ksh_rd_ln(char *line, size_t size);

#endif /* INPUT_H_ */