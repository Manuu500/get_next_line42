/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mruiz-ur <mruiz-ur@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 17:22:55 by mruiz-ur          #+#    #+#             */
/*   Updated: 2025/02/19 15:19:07 by mruiz-ur         ###   ########.fr       */
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

void	*ft_memcpy(void *dest, const void *src, unsigned int n)
{
	size_t			i;
	unsigned char	*a;
	unsigned char	*b;

	b = (unsigned char *)dest;
	a = (unsigned char *)src;
	i = 0;
	if (n == 0)
		return (dest);
	if (!dest && !src && n > 0)
		return (0);
	while (i < n)
	{
		b[i] = a[i];
		i++;
	}
	return (dest);
}

// static char	*build_letter(char *str, char *s1, char *s2)
// {
// 	size_t	i;
// 	size_t	j;

// 	i = 0;
// 	j = 0;
	
// 	return ((char *)str);
// }

char	*ft_strchr(const char *s, int c)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == (char)c)
			return ((char *)&s[i]);
		i++;
	}
	if ((char)c == '\0')
		return ((char *)s + i);
	return (0);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*str1;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	str1 = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2)) + 1);
	if (!str1)
		return (0);
	while (s1[i] != '\0')
	{
		str1[i] = s1[i];
		i++;
	}
	while (s2[j] != '\0')
	{
		str1[i + j] = s2[j];
		j++;
	}
		str1[i + j] = '\0';
	// str_cmp = build_letter(str1, s1, s2);
	return (str1);
}

void	*ft_calloc(size_t num, size_t size)
{
	char	*a;
	size_t	i;

	i = 0;
	if (size == 0 || num == 0)
	{
		num = 1;
		size = 1;
	}
	if ((num * size) / num != size)
		return (NULL);
	a = malloc(num * size);
	if (!a)
		return (0);
	else
	{
		while (i < (num * size))
		{
			a[i] = '\0';
			i++;
		}	
	}
		// ft_bzero(mem, (num * size));
	return (a);
}

