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
	int	i;
	int	cont;

	cont = 0;
	i = 0;
	while (str[i++] != '\0')
		cont++;
	return (cont);
}

char	*read_line(int	fd, char	*buffer)
{
	int	bytes;
	char	temp[BUFFER_SIZE + 1];
	char	*buffer_temp;
	
	bytes = 1;
	if (buffer == NULL)
		buffer = ft_calloc(1, sizeof(char));
	while (bytes > 0 && !ft_strchr(buffer, '\n'))
	{
		bytes = read(fd, temp, BUFFER_SIZE);
		if (bytes < 0)
		{
			free(buffer);
			return (NULL);
		}
		temp[bytes] = '\0';
		buffer_temp = malloc(ft_strlen(buffer) + bytes + 1);
		if(!buffer_temp)
			return (NULL);
		if (buffer)
		{
			buffer_temp = ft_strjoin(buffer, temp);
			free(buffer);
		}
		else
		{
			buffer_temp = ft_strdup(temp);
		}
		buffer = buffer_temp;
	}
	return (buffer);
}

char    *get_next_line(int fd)
{
	static char	*buffer;
	char	*text;
	
	if (fd < 0 || BUFFER_SIZE < 0)
		return (NULL);
	text = read_line(fd, buffer);
	if (!text)
		return (NULL);
	
	// i = 0;
	// while (text[i])
	// {
	// 	buffer[i] = text[i];
	// 	i++;
	// }
	// free (text);
	return (text);
	
}

// char *get_next_line(int fd);

int main(void)
{
    int fd = open("test.txt", O_RDONLY);
    if (fd < 0)
    {
        perror("Error opening file");
        return 1;
    }

    char *line;
    while ((line = get_next_line(fd)) != NULL)
    {
        printf("%s\n", line);
        free(line);
    }

    close(fd);
    return 0;
}
