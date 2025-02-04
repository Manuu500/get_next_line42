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
		buffer_temp = malloc(ft_strlen(buffer) + 1 * sizeof(char));
		if(!buffer_temp)
			return (NULL);
		// i = -1;
		// while(buffer[++i])
		// 	buffer_temp[i] = buffer[i];
		// buffer_temp[i] = '\0';
		buffer = ft_strjoin(buffer_temp, temp);
		if(!buffer)
		{
			free(buffer);
			break;	
		}
		free(buffer_temp);
	}
	return (buffer);
}

char    *get_next_line(int fd)
{
	static char	*buffer;
	char	*text;
	
	text = read_line(fd, buffer);
	
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

// int main(int argc, char **argv)
// {
//     int fd;
//     char *line;

//     if (argc != 2)
//     {
//         fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
//         return 1;
//     }

//     // Abre el archivo en modo lectura
//     fd = open(argv[1], O_RDONLY);
//     if (fd == -1)
//     {
//         perror("Error al abrir el archivo");
//         return 1;
//     }

//     // Llama a la función get_next_line
//     line = get_next_line(fd);
//     if (line)
//     {
//         printf("Linea leida: %s\n", line);
//         free(line); // Libera la memoria asignada para la línea
//     }
//     else
//     {
//         printf("No se pudo leer la linea\n");
//     }

//     // Cierra el archivo
//     close(fd);
//     return 0;
// }
