#include "shell.h"

void freearrayofsring(char **arr)
{
    int i;
    if (!arr)
        return;

    for (i = 0; arr[i]; i++)
    {
        free (arr[i]);
        arr[i] = NULL;
    }
    
    free (arr), arr = NULL;
}
void error(char *name ,char *com, int i)
{
    char *ix , msg[]="  not found\n";

    ix = _itoa(i);

    write(STDERR_FILENO , name , _strlen(name));
    write(STDERR_FILENO , ": ", 2 );
    write(STDERR_FILENO , ix , _strlen(ix));
    write(STDERR_FILENO , ": ", 2 );
    write(STDERR_FILENO , com , _strlen(com));
    write(STDERR_FILENO , msg , _strlen(msg));

}

char *_itoa(int n)
{
    char buffer[20];
    int i = 0 ;
    
    if (n == 0 ){
        buffer[i++]='0';
    }else{
        while(n>0){
            buffer[i++]=(n%10)+'0';
            n/=10;
        }
    }
    buffer[i]='\0';
    rev_str(buffer,i);
    return(_strdup(buffer));
  
}
void rev_str(char *str , int len)
{
    char tmp;
    int start = 0;
    int end = len -1 ;

    while (start < end ){
        tmp = str[start];
        str[start]=str[end];
        str[end]=tmp;
        start++;
        end--;

    }
}
