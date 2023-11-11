
#include "shell.h"

char *_getpath(char *com)
{
    char *flcm , *Penv , *dr;
    struct stat st;
    
    for(int j = 0 ; com[j] ; j++)
    {
        if (com[j] == '/')
        {
            if (stat(com , &st ) == 0)
            {
            return(_strdup(com));
            }
            return(NULL);
        }
    }
    
    
    Penv = _getenv("path");
    
    if(!Penv)
    return(NULL);
    
    dr = strtok(Penv, ":");
    
    while(dr)
    {
        flcm = malloc(_strlen(dr) + _strlen(com) + 2);
        if(flcm)
        {
            _strcpy(flcm, dr);
            _strcat(flcm, "/");
            _strcat(flcm, com);
            if(stat(flcm, &st) == 0)
            {
                free(Penv);
                return(flcm);
            }
            free(flcm), flcm = NULL;
            
            dr = strtok(NULL, ":");
        }
    }
    free(Penv);
    return(NULL);
}




