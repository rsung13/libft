/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsung <rsung@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 11:05:56 by rsung             #+#    #+#             */
/*   Updated: 2021/11/30 14:43:06 by rsung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_checkset(char c, char const *set)
{
	size_t	i;

	i = 0;
	while (set[i] != '\0')
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

static size_t	ft_str_size(char const *s1, char const *set)
{
	size_t	len;
	size_t	c_count;
	size_t	i;

	i = 0;
	len = ft_strlen(s1);
	c_count = 0;
	while (s1[c_count] != '\0' && ft_checkset(s1[c_count], set) == 1)
		c_count++;
	while (s1[c_count] && i < len && ft_checkset(s1[len - 1 - i], set) == 1)
	{
		c_count++;
		i++;
	}
	return (len - c_count);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*tab;
	size_t	size;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	size = ft_str_size(s1, set);
	tab = malloc(sizeof(char) * size + 1);
	if (tab == NULL)
		return (NULL);
	while (s1[j] && ft_checkset(s1[j], set) == 1)
		j++;
	while (s1[j] && i < size)
	{
		tab[i] = s1[j];
		i++;
		j++;
	}
	tab[i] = '\0';
	return (tab);
}
