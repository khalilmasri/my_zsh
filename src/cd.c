#include "../include/include.h"

status_t cd(argument *table){

    char cwd[MAX_STR_LEN];
    char current_dir[MAX_STR_LEN];
    static char prev_dir[MAX_STR_LEN];

    if(!my_strcmp(table->args[1], "-")){
        chdir(prev_dir);
        getcwd(current_dir, MAX_STR_LEN);
        my_putstr(current_dir);
        my_putstr("\n");
        return SUCCESS;
    }

    getcwd(prev_dir, MAX_STR_LEN);
    DIR* dir = opendir(table->args[1]);

    if(!dir){
        perror("dir");
        return ERROR;
    }


    if(table->args[1][0] != '/'){
        getcwd(cwd, sizeof(cwd));
        my_strcat(cwd, "/");
        my_strcat(cwd, table->args[1]);
        chdir(cwd);
    }else{
        chdir(table->args[1]);
    }

    getcwd(current_dir, MAX_STR_LEN);
    my_putstr(current_dir);
    my_putstr("\n");

    return SUCCESS;
}
