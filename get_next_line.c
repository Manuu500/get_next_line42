/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mruiz-ur <mruiz-ur@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 17:22:51 by mruiz-ur          #+#    #+#             */
/*   Updated: 2025/02/04 13:42:03 by mruiz-ur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
    size_t	cont;

    cont = 0;
    while (str[cont] != '\0')
        cont++;
    return (cont);
}

char	*ft_strdup(const char *s)
{
	char	*str;

	str = malloc(sizeof(char) * ft_strlen(s) + 1);
	if (!str)
		return (0);
	ft_memcpy(str, s, ft_strlen(s) + 1);
	return (str);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	long_s;
	char	*str;

	i = 0;
	if (!s)
		return (0);
	long_s = ft_strlen((char *)s);
	if (start >= long_s)
		return (ft_strdup(""));
	if (len > long_s - start)
		len = long_s - start;
	str = malloc(sizeof(char) * (len + 1));
	if (!str)
		return (0);
	while (s[start + i] != '\0' && i < len)
	{
		str[i] = s[i + start];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*read_line(int fd, char *buffer)
{
    size_t	bytes;
    char	temp[BUFFER_SIZE + 1];
    char	*buffer_temp;
    
    if (!buffer)
    {
        buffer = malloc(1);
        if (!buffer)
            return NULL;
        buffer[0] = '\0';
    }
    while (!ft_strchr(buffer, '\n') || bytes < 0)
    {
        bytes = read(fd, temp, BUFFER_SIZE);
        if (bytes <= 0)
            break;
        temp[bytes] = '\0';
        buffer_temp = ft_strjoin(buffer, temp);
        if (!buffer_temp)
        {
            free(buffer);
            return (NULL);
        }
        free(buffer);
        buffer = buffer_temp;
    }
    return (buffer);
}

char	*get_next_line(int fd)
{
    static char	*buffer;
    char		*line;
    char		*temp;
    char        *new_line;
    
    if (fd < 0 || BUFFER_SIZE <= 0)
        return (NULL);
    buffer = read_line(fd, buffer);
    if (!buffer || *buffer == '\0')
        return (NULL);
    line = ft_substr(buffer, 0, ft_strchr(buffer, '\n') - buffer + 1);
    if (!line)
    {
        free(buffer);
        buffer = NULL;
        return (NULL);
    }
	//Actualiza en temp, un duplicado de la línea buffer despues del salto de línea
	new_line = ft_strchr(buffer, '\n');
	if (new_line)
	{
        line = ft_substr(buffer, 0, new_line - buffer + 1);
	    temp = ft_strdup(new_line + 1);
	}
	else
	{
	    line = ft_strdup(buffer);
	    temp = NULL;
	}
    free(buffer);
    buffer = temp;
    return (line);
}

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

int main(void)
{
    int index = 0;
    int fd = open("test.txt", O_RDONLY);
    if (fd < 0)
    {
        perror("Error opening file");
        return 1;
    }

    char *line;
    while ((line = get_next_line(fd)) != NULL)
    {
        index++;
        printf("%i: %s", index, line);
        free(line);
    }

    close(fd);
    return 0;
}