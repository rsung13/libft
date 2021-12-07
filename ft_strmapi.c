/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsung <rsung@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 13:47:37 by rsung             #+#    #+#             */
/*   Updated: 2021/12/07 12:03:46 by rsung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	i;
	size_t	len;
	char	*tab;

	if (!s || !f)
		return (NULL);
	len = ft_strlen(s);
	tab = malloc(sizeof(char) * len + 1);
	if (tab == NULL)
		return (NULL);
	i = 0;
	while (s[i] != '\0')
	{
		tab[i] = (*f)((unsigned int)i, s[i]);
		i++;
	}
	tab[i] = '\0';
	return (tab);
}
