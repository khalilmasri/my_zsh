#include "../include/include.h"

int check_insert_file(argument* table){

    int index = 1;

    while(index < table->size){
        if(my_strcmp(table->args[index], ">>") == 0)
            return index;

        index++;
    }

    return 0;
}

status_t write_to_file(argument* table, int where){

    if(table->args[where+1] != NULL){
        my_putstr("Echo to only one file allowed.\n");
        return ERROR;
    }

    int fd = open(table->args[where], O_CREAT | O_RDWR | O_APPEND, S_IRWXU),
        index = 1;

    if(fd < 0){
        my_putstr("Error File open.\n");
        return ERROR;
    }

    while(index < where - 1){
        my_putchar(fd,table->args[index]);
        if(index+1 != where -1)
            write(fd, " ", my_strlen(" "));
        index++;
    }

    write(fd, "\n", my_strlen("\n"));

    return SUCCESS;
}

status_t echo(argument *table){

    int where = check_insert_file(table),
        index = 1;

    if(where == 0){
        while(table->args[index]){
            my_putchar(0,table->args[index]);
            if(table->args[index+1] != NULL)
                my_putstr(" ");
            index++;
        }
    }else{
        if (write_to_file(table, where + 1) == ERROR)
            return ERROR;
    }

    my_putstr("\n");
    return SUCCESS;
}
