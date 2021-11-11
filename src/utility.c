#include "../include/include.h"

void print_current_dir()
{
    char current_dir[MAX_STR_LEN];
    getcwd(current_dir, MAX_STR_LEN);
    my_putstr(current_dir);
    my_putstr("\n");
}

void display_prompt()
{
    write(0, "> ", 3);
}
