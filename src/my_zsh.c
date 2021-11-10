#include "../include/include.h"


status_t execute_args(argument *table){

    if(table->args[0] == NULL)
        return ERROR;

    status_t(*func_ptr)(argument*);

    char *buffer = malloc(sizeof(char)*MAX_STR_LEN);

    switch (table->command){
        case CD:
            func_ptr = cd;
            break;
        case ECHO:
            func_ptr = echo;
            break;
        /* case SETENV: */

        /*     break; */
        /* case UNSETENV: */
            
        /*     break; */
        /* case ENV: */

        /*     break; */
        case EXIT:
            return QUIT;
            break;
        case PWD:
            if(getcwd(buffer, MAX_STR_LEN) == NULL){
                perror("getcwd");
                return ERROR;
            }
                my_putstr(buffer);
                my_putstr("\n");
                free(buffer);
                return SUCCESS;
            break;
        case WHICH:
            func_ptr = which;
            break;
        default:
            return ERROR;
    }

    return func_ptr(table);
}


