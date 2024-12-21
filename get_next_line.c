/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybenzidi <ybenzidi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 22:20:41 by ybenzidi          #+#    #+#             */
/*   Updated: 2024/12/17 22:27:45 by ybenzidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "get_next_line.h"

void    ft_strtrim(char **storage)
{
    char    *new_storage;
    int     i;

    if (!storage || !*storage)
        return;
    i = has_newline(*storage);
    if (i == 0)
    {
        free(*storage);
        *storage = NULL;
        return;
    }
    new_storage = ft_strdup(*storage + i);
    free(*storage);
    *storage = new_storage;
}
 char	*ft_strncpy(char *dest, char *src, int destsize)
{
	int	i;

	i = 0;
	if (destsize)
	{
		while (src[i] && i < destsize - 1)
		{
			dest[i] = src[i];
			i++;
		}
		dest[i] = '\0';
	}
	return (dest);
}

char    *get_next_line(int fd)
{
    static char    *storage;
    char          buffer[BUFFER_SIZE + 1];
    char          *line;
    ssize_t       bytes_read;

    if (fd < 0 || BUFFER_SIZE <= 0)
        return (NULL);
    while (!has_newline(storage))
    {
        bytes_read = read(fd, buffer, BUFFER_SIZE);
        if (bytes_read == 0)
           break;
		if (bytes_read == -1)
           break;
        buffer[bytes_read] = '\0';
        storage = ft_strjoin(storage, buffer);
        if (!storage)
            return (NULL);
    }
    if (!storage)
        return (NULL);
    line = f_work(storage);
    ft_strtrim(&storage);
    return (line);
}


















// so during a process one file discreptor table is open that stores al the f position 
// file positiom in open file table(global table)
