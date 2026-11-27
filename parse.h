#ifndef PARSE_H_
#define PARSE_H_

#define ARGS_MAX 32

/**
 * Splits line into words separated by spaces or tabs.
 * Changes line in place (writes '\0' after each word).
 * args[i] points into line; args[argc] is set to NULL.
 *
 * @param line - the string to split (will be modified)
 * @param args - array to fill with pointers to each word
 * @param max  - size of args
 * @return - number of words found
 */
int ksh_parse(char *line, char *args[], int max);

#endif /* PARSE_H_ */