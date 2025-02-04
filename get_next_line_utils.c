/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mruiz-ur <mruiz-ur@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 17:22:55 by mruiz-ur          #+#    #+#             */
/*   Updated: 2025/02/04 12:32:41 by mruiz-ur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_bzero(void *s, unsigned int leng)
{
	unsigned int	i;
	char			*a;

	a = s;
	i = 0;
	while (i < leng)
	{
		a[i] = '\0';
		i++;
	}
}

void	*ft_calloc(size_t num, size_t size)
{
	void	*mem;

	if (size == 0 || num == 0)
	{
		num = 1;
		size = 1;
	}
	mem = malloc(num * size);
	if (!mem)
		return (0);
	else
		ft_bzero(mem, (num * size));
	return (mem);
}

static char	*build_letter(char *str, char const *s1, char const *s2)
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

