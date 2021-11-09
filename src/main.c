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

int main(void){

    char *std_in;
    argument *table = malloc(sizeof(argument));

    while(my_strcmp(std_in, "exit") != 0){
        write(0, "> ", my_strlen("> "));
        std_in = my_readline();
        table->size = arg_count(std_in); 
        table = parse_input(table,std_in);
    }
    
    free_argument(table); 
    return 0;
}


