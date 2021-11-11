#include "../include/include.h"

int get_input_size(char *str, int index){

    int size = 0;

    while(str[index] != ' ' && str[index] != '\0'){
        size++;
        index++;
    }
    
    return size;
}

char *store_arg(char *str, int index, int size){

    int cur     = 0;
    
    char *arg = malloc((sizeof(char)*size)+1);
    
    while(str[index] != ' ' && str[index] != '\0'){
        arg[cur] = str[index];
        cur++;
        index++;
    }
    
    arg[cur] = '\0';

    return arg;
}

void print_argument(argument *table){

    printf("Command type : %d\n", table->command);
    for(int i = 0 ; i < table->size; i++)
        printf("%s ", table->args[i]);

    printf("\n");
}

builtins_t get_command(argument *table){

    if(my_strcmp(table->args[0], "echo") == 0)
        return ECHO;
    if(my_strcmp(table->args[0], "cd") == 0)
        return CD;
    if(my_strcmp(table->args[0], "setenv") == 0)
        return SETENV;
    if(my_strcmp(table->args[0], "unsetenv") == 0)
        return UNSETENV;
    if(my_strcmp(table->args[0], "env") == 0)
        return ENV;
    if(my_strcmp(table->args[0], "exit") == 0)
        return EXIT;
    if(my_strcmp(table->args[0], "pwd") == 0)
        return PWD;
    if(my_strcmp(table->args[0], "which") == 0)
        return WHICH;

    return UNKNOWN_BUILTIN;
}


void free_argument(argument *table){
    
    for(int i = 0 ; i < table->size; i++){
        free(table->args[i]);
    }

    /* free(table); */
}

argument *parse_input(argument* table, char* input){

    int index   = 0,
        size    = 0;

    table->args = malloc(sizeof(char*)*table->size + 1);

    for(int i = 0; i < table->size; i++){
        size = get_input_size(input, index); 
        index += size + 1;
        table->args[i] = store_arg(input, index-size-1, size);
    }
    table->args[table->size] = NULL;

    
    table->command = get_command(table);
    //print_argument(table); 
    return table;
}
