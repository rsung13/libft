/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsung <rsung@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 12:03:02 by rsung             #+#    #+#             */
/*   Updated: 2021/11/30 14:33:38 by rsung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char		*desti;
	const char	*source;
	int			i;

	desti = (char *)dest;
	source = (const char *)src;
	i = -1;
	if (src == NULL && dest == NULL)
		return (NULL);
	if ((src < dest) && (dest < src + n))
	{
		while (n > 0)
		{
			desti[n - 1] = source[n - 1];
			n--;
		}
	}
	else
	{
		while (++i < (int)n)
			desti[i] = source[i];
	}
	return (dest);
}
