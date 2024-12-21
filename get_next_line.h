/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybenzidi <ybenzidi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 19:46:52 by ybenzidi          #+#    #+#             */
/*   Updated: 2024/12/17 19:49:35 by ybenzidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
#define GET_NEXT_LINE_H


#include <unistd.h>
#include <stddef.h>
#include <fcntl.h>
#include <stdlib.h>

#define BUFFER_SIZE 42

size_t	ft_strlen(char *str);
char	*ft_strdup(char *src);
void	ft_strtrim(char **storage);
char	*ft_strncpy(char *dest, char *src, int destsize);
char    *get_next_line(int fd);
int		has_newline(char *str);
char	*f_work(char *staticholder);
char	*ft_strjoin(char *s1, char *s2);


#endif