#include "get_next_line.h"
int has_newline(char *str)
{
    int i;

    if (!str)
        return (0);
    i = 0;
    while (str[i])
    {
        if (str[i] == '\n')
            return (1);
        i++;
    }
    return (0);
}
char *f_work(char *staticholder)
{
    int i;
    char *buffer;

    i = 0;
    if(!staticholder)
        return (NULL);
    while(staticholder[i] != '\n')
        i++;
    if(i != 0)
    {
        buffer = malloc(i+2);
        if(!buffer)
            return (NULL);
        ft_strncpy(buffer,staticholder,i+1);
        return(buffer);
    }
    return(ft_strdup(staticholder));
}
