#include "shell.h"

int buildin(char *command)
{
    char *buildins[]={
        "exit", "env" , "setenv", "cd"
    };
    
    for(int i =0 ; i < 4; i++){
        if(_strcmp(command,buildins[i])==0){
            return(1);
        }
    }
    
    
    return(0);
}

void handel_buildin(char **command , char **argv , int status , int i)
{
    (void) argv;
    (void) i ;
    if(_strcmp(command[0], "exit")==0)
    exit_shell(command, status);
    else if (_strcmp(command[0],"env")==0)
    print_env(command , status);
}

void exit_shell(char **command , int status){
    freearrayofsring(command); 
exit(status);
}

void print_env(char **command, int status)
{
    int i ;
    (void) status;
    for(i = 0 ; environ[i] ; i++)
    {
        write(STDERR_FILENO, environ[i], _strlen(environ[i]);
        write(STDERR_FILENO,"\n",1);
    }
        freearrayofsring(command); 

}

