#include "shell.h"

void marc_print(const char *string) {
	write(STDOUT_FILENO, message, strlen(message));
}
