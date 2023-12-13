#ifndef SHELL_H
#define SHELL_H

/**
 * main - shell header file
 *
 * return: Always 0
 */

#include <stdio.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdbool.h>

/**
 * main - shell project header
 *
 * return: Always 0
 */

void blink_prompt(void);
void marc_print(const char *string);
void read_command(char *command, size_t size);
void execute_command(const char *command);

#endif
