#include "shell.h"

/**
 * main - simple main func
 * return = 0 always (success).
 * @ac: couter for arguments
 * @avgr: argumrnts
 */
int main(int ac, char **argv)
{
char *line = NULL;
char **command = NULL;
int status = 0;
(void) ac;
while (1)
{
line = read_line();
if (line == NULL)
{
if (isatty(STDIN_FILENO))
write(STDOUT_FILENO, "\n ", 1);
return (status);
}
command = TOKEN(line);
if (!command)
continue;
status = _execute(command, argv);
}
return (0);
}

