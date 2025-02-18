/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mruiz-ur <mruiz-ur@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 17:22:55 by mruiz-ur          #+#    #+#             */
/*   Updated: 2025/02/18 14:13:47 by mruiz-ur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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

static char	*build_letter(char *str, char const *s1, char const *s2)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (s1[i] != '\0')
	{
		str[i] = s1[i];
		i++;
	}
	while (s2[j] != '\0')
	{
		str[i + j] = s2[j];
		j++;
	}
	str[i + j] = '\0';
	return ((char *)str);
}

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

