#include "parse.h"
#include <string.h>

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

int ksh_parse(char *line, char *args[], int max) {
    int i = 0;
    int num_words = 0;

    char *token = strtok(line, " \t");

    while(token != NULL && i < max - 1){ //max - 1 to leave last argument for NULL 
        args[i++] = token;
        num_words++;

        token = strtok(NULL, " \t"); //NULL in parameter tells strtok to continue from the last bookmark
        // IMPORTANT passing line once again in the loop starts from the beginning!
    }
    args[i] = NULL; //end the args list with NULL as a flag for other functions

    return num_words;
}