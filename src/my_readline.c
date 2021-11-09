#include "../include/include.h"

char *my_readline(){

    char *buffer;

    if((buffer = malloc(sizeof(char)*MAX_STR_LEN)) == NULL)
        return NULL;

    int read_input = STDIN_FILENO;

    read(read_input, buffer, MAX_STR_LEN);
    buffer[my_strlen(buffer)-1] = '\0';
    
    return buffer;
}
