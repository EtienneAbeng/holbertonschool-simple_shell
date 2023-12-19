#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>

#define BUF_SIZE 2023

void display_prompt(void);
void execute_command(char *command);
pid_t fork_process(void);
#endif
