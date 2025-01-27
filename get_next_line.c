/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mruiz-ur <mruiz-ur@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 17:22:51 by mruiz-ur          #+#    #+#             */
/*   Updated: 2025/01/27 14:23:59 by mruiz-ur         ###   ########.fr       */
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
	char	*temp;
	
	bytes = 1;
	temp = ft_calloc(BUFFER_SIZE + 1, sizeof(char *));
	while (bytes != 0 && !ft_strchr(buffer, "\n"))
	{
		bytes = read(fd, temp, BUFFER_SIZE);
		temp[bytes] = '\0';
		buffer = ft_strjoin(buffer, temp);
	}
	free(temp);
	return (buffer);
}

char    *get_next_line(int fd)
{
	static char	*buffer;
	char	*text;
	
	if (buffer == NULL)
		buffer = calloc(1, sizeof(char *));
	text = read_line(fd, buffer);
}

// int main() {
//     int fd = open("test.txt", O_RDONLY);  // Abre el archivo test.txt en modo solo lectura
//     if (fd == -1) {
//         perror("Error al abrir el archivo");void	ft_bzero(void *s, unsigned int leng)
// {
// 	unsigned int	i;
// 	char			*a;

// 	a = s;
// 	i = 0;
// 	while (i < leng)
// 	{
// 		a[i] = '\0';
// 		i++;
// 	}
// }
//         return 1;
//     }

//     char *line;
//     while ((line = get_next_line(fd)) != NULL) {
//         printf("Línea leída: %s\n", line);  // Imprimir la línea leída
//         free(line);  // Liberar el buffer después de usarlo
//     }

//     close(fd);  // Cerrar el archivo
//     return 0;
// }


// buffer = malloc(BUFFER_SIZE + 1 * (sizeof(char)));
	// if(!buffer)
	// 	return (0);
	// bytes = read(fd, buffer, BUFFER_SIZE);
	// temp = ft_strjoin(buffer, temp);
	// if (bytes == 0)void	ft_bzero(void *s, unsigned int leng)
// {
// 	unsigned int	i;
// 	char			*a;

// 	a = s;
// 	i = 0;
// 	while (i < leng)
// 	{
// 		a[i] = '\0';
// 		i++;
// 	}
// }
	// {
	// 	if (ft_strchr(buffer, "\n"))
	// 		get_next_line(fd);
	// 	return (buffer);
	// }
	// else
	// 	return (NULL);
	// buffer[bytes] = '\0';
	// free(buffer);
	// // printf("Llamada número: %d\n", count);  // Imprimir el contador	
	// return (buffer);