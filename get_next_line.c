/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mruiz-ur <mruiz-ur@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 17:22:51 by mruiz-ur          #+#    #+#             */
/*   Updated: 2025/01/23 13:57:24 by mruiz-ur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char    *get_next_line(int fd)
{
	int	bytes;
	static char	*buffer;
	
	bytes = 0;
	buffer = malloc(BUFFER_SIZE * (sizeof(char *)));
	if(!buffer)
		return (0);
	bytes = read(fd, buffer, 3);
	if (bytes <= 0)
	{
		free(buffer);
		return (0);
	}
	buffer[bytes] = '\0';
	// printf("Llamada número: %d\n", count);  // Imprimir el contador	
	return (buffer);
}

int main() {
    int fd = open("test.txt", O_RDONLY);  // Abre el archivo test.txt en modo solo lectura
    if (fd == -1) {
        perror("Error al abrir el archivo");
        return 1;
    }

    char *line;
    while ((line = get_next_line(fd)) != NULL) {
        printf("Línea leída: %s\n", line);  // Imprimir la línea leída
        free(line);  // Liberar el buffer después de usarlo
    }

    close(fd);  // Cerrar el archivo
    return 0;
}