#include "get_next_line.h"
#include <fcntl.h>  // For open
#include <unistd.h> // For close
#include <stdio.h>

size_t ft_strlen(char *str)
{
    size_t i;
    
    if (!str)
        return (0);
    i = 0;
    while (str[i])
        i++;
    return (i);
}

char *ft_strdup(char *src)
{
    char    *dest;
    int     lentsrc;
    int     i;

    if (!src)
        return (NULL);
    lentsrc = ft_strlen(src);
    dest = (char *)malloc(lentsrc + 1);
    if (!dest)
        return (NULL);
    i = 0;
    while (src[i])
    {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
    return (dest);
}

char *ft_strjoin(char *s1, char *s2)
{
    char    *result;
    size_t  i;
    size_t  j;
    size_t  len1;
    size_t  len2;

    len1 = ft_strlen(s1);
    len2 = ft_strlen(s2);
    result = (char *)malloc(len1 + len2 + 1);
    if (!result)
        return (NULL);
    i = 0;
    while (s1 && s1[i])
    {
        result[i] = s1[i];
        i++;
    }
    j = 0;
    while (s2 && s2[j])
    {
        result[i + j] = s2[j];
        j++;
    }
    result[i + j] = '\0';
    if (s1)
        free(s1);
    return (result);
}

char *ft_strncpy(char *dest, char *src, int destsize)
{
    int i;

    i = 0;
    while (src[i] && i < destsize)
    {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
    return (dest);
}

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

char *extract_line(char **storage)
{
    char    *line;
    char    *temp;
    int     i;

    if (!*storage || !**storage)
    {
        if (*storage)
        {
            free(*storage);
            *storage = NULL;
        }
        return (NULL);
    }
    i = 0;
    while ((*storage)[i] && (*storage)[i] != '\n')
        i++;
    if ((*storage)[i] == '\n')
        i++;
    line = (char *)malloc(i + 1);
    if (!line)
        return (NULL);
    ft_strncpy(line, *storage, i);
    if ((*storage)[i])
    {
        temp = ft_strdup(*storage + i);
        free(*storage);
        *storage = temp;
    }
    else
    {
        free(*storage);
        *storage = NULL;
    }
    return (line);
}

char *get_next_line(int fd)
{
    static char *storage;
    char        buffer[BUFFER_SIZE + 1];
    ssize_t     bytes_read;

    if (fd < 0 || BUFFER_SIZE <= 0)
        return (NULL);
    bytes_read = 1;
    while (!has_newline(storage) && bytes_read > 0)
    {
        bytes_read = read(fd, buffer, BUFFER_SIZE);
        if (bytes_read == -1)
        {
            free(storage);
            storage = NULL;
            return (NULL);
        }
        if (bytes_read == 0)
            break;
        buffer[bytes_read] = '\0';
        storage = ft_strjoin(storage, buffer);
        if (!storage)
            return (NULL);
    }
    return (extract_line(&storage));
}

#include <fcntl.h>  // For open
#include <unistd.h> // For close
#include <stdio.h>  // For printf

int main()
{
    int fd;
    char *line;

    // Open the file in read-only mode
    fd = open("text.txt", O_RDONLY);
    if (fd < 0)
    {
        perror("Error opening file");
        return (1);
    }

    // Read and print each line using get_next_line
    while ((line = get_next_line(fd)) != NULL)
    {
        printf("%s", line);
        free(line); // Free the line after use
    }

    // Close the file descriptor
    close(fd);
    return (0);
}