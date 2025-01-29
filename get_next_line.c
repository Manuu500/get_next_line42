/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mruiz-ur <mruiz-ur@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 17:22:51 by mruiz-ur          #+#    #+#             */
/*   Updated: 2025/01/29 14:48:17 by mruiz-ur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_utils.c"


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
	size_t	i;
	
	bytes = 1;
	while (bytes > 0 && !ft_strchr(buffer, '\n'))
	{
		bytes = read(fd, temp, BUFFER_SIZE);
		if (bytes < 0)
			return (NULL);
		temp[bytes] = '\0';
		//contenido de buffer igualar a buffer_size
		buffer_temp = ft_calloc(ft_strlen(buffer) + 1, sizeof(char));
		if(!buffer_temp)
			return (NULL);
		i = -1;
		while(buffer[++i])
			buffer_temp[i] = buffer[i];
		buffer = ft_strjoin(buffer_temp, temp);
		if(!buffer)
			break;
		free(buffer_temp);
	}
	return (buffer);
}

char    *get_next_line(int fd)
{
	static char	*buffer;
	char	*text;
	size_t	i;
	
	if (buffer == NULL)
		buffer = ft_calloc(1, sizeof(char));
	text = read_line(fd, buffer);
	while (text[i])
	{
		buffer[i] = text[i];
		i++;
	}
	free (text);
	return (buffer);
	
}


int main(void)
{
    int fd;
    char buffer[1024];
    char *line;

    // Abre el archivo en modo lectura
    fd = open("test.txt", O_RDONLY);
    if (fd == -1)
    {
        perror("Error al abrir el archivo");
        return 1;
    }

    // Llama a la función read_line
    line = read_line(fd, buffer);
    if (line)
    {
        printf("Linea leida: %s\n", line);
    }
    else
    {
        printf("No se pudo leer la linea\n");
    }

    // Cierra el archivo
    close(fd);
    return 0;
}