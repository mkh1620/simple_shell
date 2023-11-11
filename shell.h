#ifndef SHELL_H
#define SHELL_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <errno.h>
#include <fcntl.h>
#define DELIM " \t\n"
char *read_line (void);
char *_strdup (const char *str);
int _strcmp(char *s1, char *s2);
int _strlen(char *s);
char *_strcat(char *dest, char *src);
char *_strcpy(char *dest, char *src);
int _execute(char **command, char **argv);
char **TOKEN(char *line);
void freearrayofsring(char **arr);
extern char **environ;
int _execute(char **command, char **argv);
char *_getenv(char *name);
char *_getpath(char *com);
void error(char *name ,char *com, int i);
void rev_str(char *str , int len);
char *_itoa(int n);



#endif
