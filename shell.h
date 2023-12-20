#ifndef _SHELL_H_
#define _SHELL_H_
#include <stddef.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/stat.h>
extern char **environ;
#define INITIAL_TOKENS 64
int main(void);
void buffer(void);
int exit_shell(void);
int print_env(void);
char *read_command(void);
char **split_command(char *input);
int execute_command(char **array);
char *get_env(char *command);
char *find_path(char *command);
#endif
