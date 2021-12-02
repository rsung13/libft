/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsung <rsung@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 13:12:44 by rsung             #+#    #+#             */
/*   Updated: 2021/11/30 14:36:53 by rsung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

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
	size_t	word_count;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	word_count = ft_word_count(s, c);
	tab = malloc(sizeof(char *) * (word_count + 1));
	if (tab == NULL)
		return (NULL);
	while (s[i] != '\0')
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i] && s[i] != c)
		{
			tab[j] = ft_ptr_tab(&s[i], c);
			j++;
			while (s[i] && s[i] != c)
				i++;
		}
	}
	tab[j] = 0;
	return (tab);
}
