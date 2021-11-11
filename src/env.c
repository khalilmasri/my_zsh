#include "../include/include.h"

status_t env(argument *table){

    for(int i = 0 ;i < table->env_length;i++){
        printf("%s\n", table->env[i]);
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

int correct_char(char c){
    if((c >= 'A' && c <= 'Z' && c !='\0') || is_digit(c) == 1 || c == '_' )
        return 1;

    return 0;
}

char *get_variable(char *str){

    int index = 0;
    char *variable = malloc(sizeof(char)*MAX_STR_LEN);

    while(str[index] != '='){
        if(correct_char(str[index]) == 1){
            variable[index] = str[index];
        }else{
            my_putstr("Variable must be capital letters and have variable.\n");
            return NULL;
        }
        index++;
    }

    variable[index] = '\0';

    return variable;
}

int check_variable(char *str){

    int index = 0;

    while(str[index]){
        if(correct_char(str[index]) == 1)
            index++;
        else{
            my_putstr("Incorrect variable name.\n");
            return 0;
        }
    }

    return 1;
}

char *get_value(char *str){

    int index = 0,
        cur = 0;

    char *value = malloc(sizeof(char)*MAX_STR_LEN);

    while(str[index] != '=' && str[index])
        index++;

    index++;
    if(str[index] == '\0'){
        my_putstr("Values must not be empty.\n");
        return NULL;
    }

    while(str[index]){
        value[cur] = str[index];
        cur++;
        index++;
    }

    value[cur] = '\0';

    return value;

}

int check_variable_exist(char *new, char *exist){

    char *exist_var = get_variable(exist);

    if(!(my_strcmp(new, exist_var)))
        return 1;

    return 0;
}

char **modify_variable(argument* table, int index){

    table->env[index] = malloc(sizeof(char)*my_strlen(table->args[1]));

    my_strcpy(table->env[index], table->args[1]);

    return table->env;
}

char **add_variable(argument *table){

    table->env_length+=1;
    char **ret = malloc(sizeof(char*)*table->env_length+1);

    for(int i = 0; i < table->env_length;i++){
        if(i != table->env_length-1){
            ret[i] = malloc(sizeof(char)*my_strlen(table->env[i]));
            my_strcpy(ret[i], table->env[i]);
        }else{
            ret[i] = malloc(sizeof(char)*my_strlen(table->args[1]));
            my_strcpy(ret[i], table->args[1]);
        }
    }

    ret[table->env_length] = NULL;

    return ret;
}

char **delete_variable(argument *table, int index){

    table->env_length-=1;
    char **ret = malloc(sizeof(char*)*table->env_length+1);

    for(int i = 0,  j = 0; i < table->env_length;i++,j++){
        if(i == index){
            j++;
        }
            ret[i] = malloc(sizeof(char)*my_strlen(table->env[j]));
            my_strcpy(ret[i], table->env[j]);
    }

    ret[table->env_length] = NULL;

    return ret;
}

status_t my_setenv(argument *table){

    if(table->size != 2){
        my_putstr("setenv usage: setenv NEWVALUE=value.\n");
        return ERROR;
    }

    char *variable = get_variable(table->args[1]),
         *value = get_value(table->args[1]);

    if(variable == NULL || value == NULL)
        return ERROR;

    int i = 0;

    while(table->env[i]){
        if(check_variable_exist(variable, table->env[i]) == 1){
            table->env = modify_variable(table,i);
            my_putstr("Variable successfuly changed.\n");
            return SUCCESS;
        }
        i++;
    }

    table->env = add_variable(table);

    free(variable);
    free(value);
    return SUCCESS;
}

status_t my_unsetenv(argument *table){

    if(table->size != 2){
        my_putstr("unsetenv usage: unsetenv NEWVALUE.\n");
        return ERROR;
    }

    if(check_variable(table->args[1]) == 0)
        return ERROR;

    int i = 0;

    while(table->env[i]){
        if(check_variable_exist(table->args[1], table->env[i]) == 1){
            table->env = delete_variable(table,i);
            my_putstr("Variable successfuly deleted.\n");
            return SUCCESS;
        }
        i++;
    }

    my_putstr("Variable was not found.\n");
    return ERROR;
}

