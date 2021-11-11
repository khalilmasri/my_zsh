#include "../include/include.h"

char *get_bin(argument *table)
{
    int i = 0;
    DIR *dir;
    char *bin = malloc(sizeof(char) * MAX_STR_LEN);

    while (i < table->paths_size)
    {
        dir = opendir(table->paths[i]);

        if (!dir)
        {
            perror("dir");
            return NULL;
        }

        struct dirent *current_file;
        current_file = readdir(dir);

        for (; current_file; current_file = readdir(dir))
        {
            if (!my_strcmp(table->args[0], current_file->d_name))
            {
                my_strcpy(bin, table->paths[i]);
                my_strcat(bin, "/");
                my_strcat(bin, current_file->d_name);
                goto found;
            }
        }
        i++;
        closedir(dir);
    }
    return NULL;
found:
    closedir(dir);

    return bin;
}

status_t execute(argument *table)
{
    pid_t pid, wpid;
    int status;
    char *bin = get_bin(table);

    if (bin == NULL)
    {
        my_putstr("our_zsh: command not found: ");
        my_putstr(table->args[0]);
        my_putstr("\n");
        return ERROR;
    }

    pid = fork();

    if (pid == 0)
    {
        if (execv(bin, table->args) == 1)
        {
            perror("lsh");
        }
        exit(EXIT_FAILURE);
    }
    else
    {
        do
        {
            wpid = waitpid(pid, &status, WUNTRACED);
        } while (!WIFEXITED(status) && !WIFSIGNALED(status) && wpid > 0);
    }

    return SUCCESS;
}
