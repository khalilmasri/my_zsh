/*
 * =====================================================================================
 *
 *       Filename:  main.c
 *
 *    Description:  My_zsh is A unix_shell 
 *
 *        Version:  1.0
 *        Created:  11/09/2021 02:23:28 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Chris Dallat , Khalil Masree 
 *   Organization:  ELU 
 *
 * =====================================================================================
 */

#include "../include/include.h"

int main(int argc, char *argv[], char **envi)
{

    if (argc > 1)
    {
        *argv = NULL;
        my_putstr("my_zsh: can't take input.\n");
        return 0;
    }

    char *std_in = "\0";
    status_t status = 0;
    argument *table = malloc(sizeof(argument));
    table->env = get_env(table, envi);

    print_current_dir();

    while (status != QUIT)
    {
        display_prompt();
        std_in = my_readline();
        table->size = arg_count(std_in);
        table = parse_input(table, std_in);
        status = execute_args(table);

        free(std_in);
    }

    free_argument(table);
    free(table);

    return 0;
}
