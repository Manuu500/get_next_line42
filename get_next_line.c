/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mruiz-ur <mruiz-ur@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 17:22:51 by mruiz-ur          #+#    #+#             */
/*   Updated: 2025/01/23 14:37:52 by mruiz-ur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*build_letter(char *str, char const *s1, char const *s2)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (s2[j] != '\0' || s1[i] != '\0')
	{
		if (s1[i] != '\0')
		{
			str[i] = s1[i];
			i++;
		}
		else
		{
			str[i + j] = s2[j];
			j++;
		}
	}
	str[i + j] = '\0';
	return ((char *)str);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	str1_long;
	size_t	str2_long;
	char	*str1;
	char	*str_cmp;

	str1_long = ft_strlen(s1);
	str2_long = ft_strlen(s2);
	str1 = malloc(sizeof(char) * (str1_long + str2_long) + 1);
	if (!str1)
		return (0);
	str_cmp = (char *)build_letter(str1, s1, s2);
	return (str_cmp);
}

char    *get_next_line(int fd)
{
	int	bytes;
	static char	*buffer;
	char	*temp;
	
	temp = NULL;
	bytes = 0;
	buffer = malloc(BUFFER_SIZE + 1 * (sizeof(char)));
	if(!buffer)
		return (0);
	bytes = read(fd, buffer, BUFFER_SIZE);
	temp = ft_strjoin(buffer, temp);
	if (bytes == 0)
	{
		if (ft_strchr(buffer, "\n"))
		{
			get_next_line(fd);
		}
		return (buffer);
	}
	else
		return (NULL);
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