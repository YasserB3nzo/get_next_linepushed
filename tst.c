#include "get_next_line.h"
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





























// #include <stdio.h>

// void inctest(char **a)
// {
//     int i  = 0;
//     while(**a != 'b')
//     {
//         (*a)++;
//         i++; 
//     }
    
// }
// void printtest(char *c)
// {
//     printf("%s",c);
// }
//  char	*ft_strncpy(char *dest, const char *src, int destsize)
// {
// 	int	i;

// 	i = 0;
// 	if (destsize)
// 	{
// 		while (src[i] && i < destsize - 1)
// 		{
// 			dest[i] = src[i];
// 			i++;
// 		}
// 		dest[i] = '\0';
// 	}
// 	return (dest);
// }
// void printbuffer(char *dest,char *src,int i)
// {
//     printf("\n------------------------------------\n");
//     ft_strncpy(dest,src,8);
//     printf("%s",dest);
// }
// int main()
// {
//     static char *test = "yasserbenzidiya";
//     char buffer[8];
//     inctest(&test);
//     printtest(test);
//     printbuffer(buffer,test,8);

// }