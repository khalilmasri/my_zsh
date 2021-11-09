#include "../include/include.h"

void print_error(char *error)
{
    if (my_strcmp(error, "usage") == 0)
    {
        printf("The program:\n");
        printf("must only contain the operators +, -, *, /, and %%\n");
        printf("must only have integer values\n");
        printf("can contain parentheses, but each group must be properly closed\n");
        printf("can contain spaces\n");
    }

    if (my_strcmp(error, "parentheses") == 0)
        printf("Parentheses must be properly closed and surround a valid equation.\n");
}

