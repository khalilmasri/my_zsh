#include "../include/include.h"

status_t env(argument *table){

    for(int i = 1 ;*table->env; table->env++, i++){
        printf("%s\n", *table->env);
    }

    return SUCCESS;
}

int env_length(char **env){

    int i = 0;

    for(;*env; env++)
        i++;

    return i;
}

char **get_env(argument* table,char **env){
    
    table->env_length = env_length(env);

    table->env = malloc(sizeof(char*)*table->env_length+1);

    for(int i = 0;*env;env++,i++){
        table->env[i] = malloc(sizeof(char)*my_strlen(*env));
        my_strcpy(table->env[i], *env);
    }

    table->env[table->env_length] = NULL;
    
    return table->env;
}

char *get_variable(char *str){

    int index = 0;
    char *variable = malloc(sizeof(char)*MAX_STR_LEN);

    while(str[index] != '=' && str[index]){
        variable[index] = str[index];
        index++;
    }

    variable[index] = '\0';

    return variable;
}

int check_variable_exist(char *new, char *exist){

    char *exist_var = get_variable(exist);

    if(!(my_strcmp(new, exist_var)))
        return 1;

    return 0;
}

char **new_env(argument *table){

    char **ret = malloc(sizeof(char*)*table->env_length+1);

    for(int i = 0; i < table->env_length;i++){
        printf("%s\n",table->env[i]);
        ret[i] = malloc(sizeof(char)*100);
        my_strcpy(ret[i], table->env[i]);
        printf("Here\n");
    }

    ret[table->env_length] = malloc(sizeof(char)*my_strlen(table->args[1]));
    my_strcpy(table->env[table->env_length], table->args[1]);
    table->env_length+=1;
    ret[table->env_length] = NULL;
    
    return ret;
}

argument *add_variable(argument *table){

    table->env = new_env(table);

    env(table);
    return table;
}

status_t my_setenv(argument *table){

    if(table->size != 2){
        my_putstr("setenv usage: setenv NEWVALUE=value.\n");
        return ERROR;
    }
    
    char *variable = get_variable(table->args[1]);

    while(*table->env){
        if(check_variable_exist(variable, *table->env) == 1){
            my_putstr("Variable exists.\n");
            return ERROR;
        }
        table->env++;
    }

    table = add_variable(table);

    free(variable);
    return SUCCESS;
}

