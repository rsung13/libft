/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsung <rsung@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 18:30:11 by rsung             #+#    #+#             */
/*   Updated: 2021/11/30 14:32:02 by rsung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*tab1;
	unsigned char	*tab2;
	size_t			i;

	i = 0;
	tab1 = (unsigned char *)s1;
	tab2 = (unsigned char *)s2;
	if (n == 0)
		return (0);
	while (i < n - 1)
	{
		if (tab1[i] != tab2[i] && i < n)
			return (tab1[i] - tab2[i]);
		i++;
	}
	return (tab1[i] - tab2[i]);
}
