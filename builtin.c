#include "shell.h"

/**
 * _myexit - exits the shell
 * @info: Structure containing potential arguments. Used to maintain
 *          constant function prototype.
 *  Return: exits with a given exit status
 *         (0) if info.argv[0] != "exit"
 */
int get_exit_code(char *arg)
{
	int exitcode;
	if (!arg || strtol(arg, NULL, 10, &exitcode) == 0)
	{
		return -1; // Invalid argument
	}
	return exitcode;
}
int _myexit(info_t *info)
{
	if (info->argv[1])
	{
		int exitcode = get_exit_code(info->argv[1]);
		if (exitcode == -1)
		{
			print_error(info, "Illegal number: %s\n", info->argv[1]);
			return 1;
		}
		return -2; // Signal exit with specified code
	}
	return -1; // Exit shell with default code
}

/**
 * _mycd - changes the current directory of the process
 * @info: Structure containing potential arguments. Used to maintain
 *          constant function prototype.
 *  Return: Always 0
 */
int _mycd(info_t *info)
{
	char *target;
	if (!info->argv[1])
	{
		target = getenv("HOME");
		if (!target) target = "/";
	}
	else if (_strcmp(info->argv[1], "-") == 0)
	{
		target = getenv("OLDPWD");
		if (!target) return print_error(info, "No previous directory\n");
	}
	else
	{
		target = info->argv[1];
	}
	if (chdir(target) == -1)
	{
		print_error(info, "Error changing directory to '%s'\n", target);
		return 1;
	}
	_setenv("OLDPWD", getcwd(NULL, 0));
	_setenv("PWD", getcwd(NULL, 0));
	return (0);
}

/**
 * _myhelp - changes the current directory of the process
 * @info: Structure containing potential arguments. Used to maintain
 *          constant function prototype.
 *  Return: Always 0
 */
int _myhelp(info_t *info)
{
	char **arg_array;

	arg_array = info->argv;
	_puts("help call works. Function not yet implemented \n");
	if (0)
		_puts(*arg_array); /* temp att_unused workaround */
	return (0);
}
