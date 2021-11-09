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
    
    char *arg    = malloc((sizeof(char)*size)+1);
    
    while(str[index] != ' ' && str[index] != '\0'){
        arg[cur] = str[index];
        cur++;
        index++;
    }
    
    arg[cur] = '\0';

    return arg;
}

void print_argument(argument *table){

    for(int i = 0 ; i < table->size; i++)
        printf("%s ", table->args[i]);
}

void free_argument(argument *table){
    
    for(int i = 0 ; i < table->size; i++){
        free(table->args[i]);
    }

    free(table);
}

argument *parse_input(argument* table, char* input){

    int index   = 0,
        size    = 0;

    table->args = malloc(sizeof(char*)*table->size);

    for(int i = 0; i < table->size; i++){
        size = get_input_size(input, index); 
        index += size + 1;
        table->args[i] = store_arg(input, index-size-1, size);
    }

    print_argument(table);
    return table;
}
