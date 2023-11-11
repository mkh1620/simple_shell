#include "shell.h"

int _execute(char **command, char **argv)
{
    pid_t child;
    int status;
   char *flcom;
   flcom = _getpath(command[0]);
if(!flcom)
{
        freearrayofsring(command);
        return(127);
}
   
   
    child = fork();
    if (child == 0)
    {
        if (execve(flcom, command, environ) == -1)
        {
            perror (argv[0]);
            free(flcom), flcom = NULL;
            freearrayofsring(command); 
            exit(0);
        }
    }
    else
    {
        waitpid (child, &status, 0);
        free(flcom), flcom = NULL;
        freearrayofsring(command);
    }

return (WEXITSTATUS (status));
}
