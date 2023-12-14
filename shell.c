#include "shell.h"

void blink_prompt(void);

/**
 * blink_prompt - displays the shell prompt
 */
void blink_prompt(void)
{
	marc_print("marcelo_shell$$ ");
}

/**
 * main - shell main project
 * Return: always 0
 */

int main(void)
{
	char command[128];

	while (true)
	{
		blink_prompt();
		read_command(command, sizeof(command));
		execute_command(command);
	}
	return (0);
}
