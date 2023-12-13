#include "shell.h"
/**
 * main - shell main project file
 *
 * return: Always 0.
 */

int main(void) {
	char command[128];

	while (true) {
		blink_prompt();
		void blink_prompt(void) {
			marc_print("marcelo_shell$$ ");
		}
		read_command(command, sizeof(command));
		execute_command(command);
	}
	return 0;
}
