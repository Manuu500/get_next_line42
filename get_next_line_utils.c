/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mruiz-ur <mruiz-ur@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 17:22:55 by mruiz-ur          #+#    #+#             */
/*   Updated: 2025/01/22 11:53:05 by mruiz-ur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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

// char	*ft_substr(char const *s, unsigned int start, size_t len)
// {
// 	size_t	i;
// 	size_t	long_s;
// 	char	*str;

// 	i = 0;
// 	if (!s)
// 		return (0);
// 	long_s = ft_strlen((char *)s);
// 	if (start >= long_s)
// 		return (ft_strdup(""));
// 	if (len > long_s - start)
// 		len = long_s - start;
// 	str = malloc(sizeof(char) * (len + 1));
// 	if (!str)
// 		return (0);
// 	while (s[start + i] != '\0' && i < len)
// 	{
// 		str[i] = s[i + start];
// 		i++;
// 	}
// 	str[i] = '\0';
// 	return (str);
// }

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
