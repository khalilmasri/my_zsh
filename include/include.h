// LIBRARIES

#include <stdlib.h>
#include <stdio.h>
#include <signal.h>
#include <dirent.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>

// DEFINES

#define MAX_STR_LEN 1024
#define MAX_DICT_LEN 100
#define BIN "/usr/bin/"

// BUILTINS
/* #define CD "cd" */
/* #define LS "ls" */
/* #define ECHO "echo" */
/* #define SETENV "setenv" */
/* #define UNSETENV "unsetenv" */
/* #define ENV "env" */
/* #define EXIT "exit" */
/* #define PWD "pwd" */
/* #define WHICH "which" */

// ENUM

typedef enum{
    SUCCESS, // 0
    QUIT, // 1
    ERROR, // 2
}status_t;

typedef enum{
    CD,
    ECHO,
    SETENV,
    UNSETENV,
    ENV,
    EXIT,
    PWD,
    WHICH,
    UNKNOWN_BUILTIN,
}builtins_t;

// STRUCTS

typedef struct arguments_s{
    int size;
    char **args;
    char **env;
    int env_length;
    builtins_t command;
}argument;

// --------------------------------------------------------------------------------

#ifndef STRING_H
#define STRING_H

char* my_strcat(char*, char*);
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
int my_getchar();
void my_putstr(char*);
void my_putchar(int, char*);

#endif
// --------------------------------------------------------------------------------

#ifndef UTILITY_H
#define UTILITY_H

void print_current_dir();

#endif
// --------------------------------------------------------------------------------

#ifndef INCLUDE_H
#define INCLUDE_H

void print_current_dir();
void display_prompt();

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

#ifndef MY_ZSH_H
#define MY_ZSH_H

status_t execute_args(argument*);
status_t echo(argument*);
status_t cd(argument*);
status_t which(argument*);
status_t env(argument*);
status_t my_setenv(argument*);
char **get_env(argument*,char**);
status_t my_unsetenv(argument*);

#endif
// --------------------------------------------------------------------------------
