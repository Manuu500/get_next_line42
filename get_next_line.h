/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mruiz-ur <mruiz-ur@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 17:23:21 by mruiz-ur          #+#    #+#             */
/*   Updated: 2025/02/19 16:21:23 by mruiz-ur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
// #  define BUFFER_SIZE 10000000
# endif

# include <stddef.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <fcntl.h>
/* @brief Essta función coge un int que es un fichero para extraer su contenido
	@param int Fichero a leer
	@return Devuelve una cadena leida hasta 
	el final de fichero o hasta salto de línea */
char	*get_next_line(int fd);
char	*ft_strchr(const char *s, int c);
char	*ft_strjoin(char *s1, char *s2);
size_t	ft_strlen(const char *str);
char	*ft_substr(char const *s, unsigned int start, size_t len);
void	*ft_calloc(size_t num, size_t size);
void	ft_bzero(void *s, unsigned int leng);
void	*ft_memcpy(void *dest, const void *src, unsigned int n);
char	*ft_strdup(const char *s);

#endif