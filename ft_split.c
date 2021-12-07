/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsung <rsung@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 13:12:44 by rsung             #+#    #+#             */
/*   Updated: 2021/12/07 12:03:36 by rsung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static void	ft_clean(char **tab)
{
	size_t	i;

	i = 0;
	while (tab[i] != NULL)
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

static size_t	ft_word_count(char const *s, char c)
{
	size_t	count;
	size_t	i;

	count = 0;
	i = 0;
	while (s[i] != '\0')
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i] && s[i] != c)
		{
			count++;
			while (s[i] && s[i] != c)
				i++;
		}
	}
	return (count);
}

static char	*ft_ptr_tab(char const *s, char c)
{
	char	*tab;
	size_t	i;
	size_t	j;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	tab = malloc(sizeof(char) * (i + 1));
	if (tab == NULL)
		return (NULL);
	j = 0;
	while (j < i)
	{
		tab[j] = s[j];
		j++;
	}
	tab[j] = '\0';
	return (tab);
}

char	**ft_split(char const *s, char c)
{
	char	**tab;
	size_t	j;

	j = 0;
	tab = malloc(sizeof(char *) * (ft_word_count(s, c) + 1));
	if (!tab)
		return (NULL);
	while (*s != '\0')
	{
		while (*s && *s == c)
			s++;
		if (*s && *s != c)
		{
			tab[j++] = ft_ptr_tab(s, c);
			if (!(tab[j - 1]))
			{
				ft_clean(tab);
				return (NULL);
			}
			s += ft_strlen(tab[j - 1]);
		}
	}
	tab[j] = 0;
	return (tab);
}
