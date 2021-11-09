// LIBRARIES

#include <stdlib.h>
#include <stdio.h>
#include <signal.h>
#include <dirent.h>
#include <sys/types.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/wait.h>

#define MAX_STR_LEN 100

// STRUCTS

typedef struct arguments_s{
    int size;
    char **args;
}argument;

// --------------------------------------------------------------------------------

#ifndef STRING_H
#define STRING_H

int my_memset(char*, char, int);
size_t my_strlen(char*);
char *my_strcpy(char*, char*);
void my_reverse(char*, int);
char *my_itoa(int, char*);
long my_atoi(char*,int);
int my_strcmp(char*, char*);
int is_digit(char);
int is_char(char);
int arg_count(char*);

#endif
// --------------------------------------------------------------------------------

#ifndef INCLUDE_H
#define INCLUDE_H

void print_error(char*);

#endif
// --------------------------------------------------------------------------------

#ifndef MY_READLINE_H
#define MY_READLINE_H

char *my_readline();

#endif
// --------------------------------------------------------------------------------

#ifndef PARSE_H
#define PARSE_H

argument *parse_input(argument*, char*);
void free_argument(argument*);

#endif
// --------------------------------------------------------------------------------
