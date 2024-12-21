#include "get_next_line.h"

size_t ft_strlen(char *str)
{
	size_t i;
	i = 0;
	if(!str)
		return (0);
	while(str[i])
		i++;
	return (i);
}
char	*ft_strdup(char *src)
{
	char	*dest;
	int		lentsrc;
	int		i;

	lentsrc = ft_strlen(src) + 1;
	dest = (char *)malloc(lentsrc);
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

    result = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
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
