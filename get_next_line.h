/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mruiz-ur <mruiz-ur@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 17:23:21 by mruiz-ur          #+#    #+#             */
/*   Updated: 2025/03/03 13:11:55 by mruiz-ur         ###   ########.fr       */
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
/* @brief Esta función coge un int que es un fichero para extraer su contenido
	@param int Fichero a leer
	@return Devuelve una cadena leida hasta 
	el final de fichero o hasta salto de línea */
char	*get_next_line(int fd);
/* @brief Esta función encuentra la primera ocurrencia
	del carácter que se le pase
	@param char* Texto a leer
	@param char	 Caracter a encontrar en el texto
	@return Devuelve un puntero a la primera ocurrencia
	del caracter pasado como argumento. */
char	*ft_strchr(const char *s, int c);
/* @brief Esta función se encarga de juntar dos cadenas de caracteres
	@param char* 1º String
	@param char* Cadena a juntar con la primera string
	@return Devuelve una string concatenada con la primera cadena
	de caracteres y la segunda */
char	*ft_strjoin(char *s1, char *s2);
/* @brief Esta función se encarga contar cuantos caracteres tiene un string
	@param char* String pasado para contar
	@return Devuelve un int con la cantidad de caracteres que lee en
	el texto pasado por argumento */
size_t	ft_strlen(const char *str);
/* @brief Esta función devuelve una substring del string s
	@param s La string desde la que crear la substring
	@param int El índice del caracter de 's' en el que empieza a
	crear la substring
	@param len La longitud máxima hasta donde crea el substring
	@return Devuelve un int con la cantidad de caracteres que lee en
	el texto pasado por argumento */
char	*ft_substr(char const *s, unsigned int start, size_t len);
/* @brief Esta función reserva memoria y devuelve un puntero hacia esta
	@param num Cantidad de elementos que tiene que guardar
	@param size	Tamaño de cada uno de los elementos
	@return Devuelve un puntero hacia la memoria creada */
void	*ft_calloc(size_t num, size_t size);
void	ft_bzero(void *s, unsigned int leng);
/* @brief Esta función copia un bloque de memoria
	de una ubicación a otra
	@param dest Puntero a bloque de memoria donde se pegará
	el bloque de memoria copiado
	@param src Puntero a bloque de memoria donde se copiarán los datos
	@param n Número de bytes que se copiarán */
void	*ft_memcpy(void *dest, const void *src, unsigned int n);
/* @brief Esta función se encarga de duplicar una cadena
	@param s Cadena a duplicar
	@return Devuelve un puntero del duplicado de la cadena pasada como argumento
	 */
char	*ft_strdup(const char *s);

#endif