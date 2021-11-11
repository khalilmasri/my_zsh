#include "../include/include.h"

builtins_t is_builtins(char *str)
{
    if (my_strcmp(str, "echo") == 0)
        return ECHO;
    if (my_strcmp(str, "cd") == 0)
        return CD;
    if (my_strcmp(str, "setenv") == 0)
        return SETENV;
    if (my_strcmp(str, "unsetenv") == 0)
        return UNSETENV;
    if (my_strcmp(str, "env") == 0)
        return ENV;
    if (my_strcmp(str, "exit") == 0)
        return EXIT;
    if (my_strcmp(str, "pwd") == 0)
        return PWD;
    if (my_strcmp(str, "which") == 0)
        return WHICH;

    return 0;
}

status_t which(argument *table)
{

    int index = 1, i = 0;
    char ret_msg[MAX_STR_LEN];
    DIR *dir;

    while (i < table->paths_size)
    {
        dir = opendir(table->paths[i]);

        if (!dir)
        {
            perror("dir");
            return ERROR;
        }

        while (table->args[index])
        {
            if (is_builtins(table->args[index]) != 0)
            {
                my_strcpy(ret_msg, table->args[index]);
                my_strcat(ret_msg, ": shell built-in command\n");
                my_putstr(ret_msg);
                goto found;
            }
            else
            {
                struct dirent *current_file;
                current_file = readdir(dir);
                for (; current_file;)
                {
                    if (!my_strcmp(table->args[index], current_file->d_name))
                    {
                        my_strcpy(ret_msg, table->paths[i]);
                        my_strcat(ret_msg, "/");
                        my_strcat(ret_msg, current_file->d_name);
                        my_strcat(ret_msg, "\n");
                        my_putstr(ret_msg);
                        goto found;
                    }
                    current_file = readdir(dir);
                }
            }
            index++;
        }
        index = 1;
        i++;
    }
    my_strcpy(ret_msg, table->args[index]);
    my_strcat(ret_msg, " not found.\n");
    my_putstr(ret_msg);

found:
    closedir(dir);

    return SUCCESS;
}
