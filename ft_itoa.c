/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsung <rsung@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 14:47:12 by rsung             #+#    #+#             */
/*   Updated: 2021/11/30 14:30:09 by rsung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_len_count(int n)
{
	int				count;
	unsigned int	nbr;

	count = 0;
	if (n == 0)
		return (count + 1);
	if (n < 0)
	{
		count++;
		nbr = n * -1;
	}
	else
		nbr = n;
	while (nbr != 0)
	{
		nbr /= 10;
		count++;
	}
	return (count);
}

static void	ft_put_n(char *s, unsigned int n, int size)
{
	while (0 < size)
	{
		s[size -1] = n % 10 + '0';
		n /= 10;
		size--;
	}	
}

char	*ft_itoa(int n)
{
	char			*tab;
	int				count;
	unsigned int	nbr;

	count = ft_len_count(n);
	tab = malloc(sizeof(char) * count + 1);
	if (tab == NULL)
		return (NULL);
	if (n == 0)
		tab[0] = '0';
	if (n < 0)
	{
		tab[0] = '-';
		nbr = n * -1;
		ft_put_n(tab + 1, nbr, count - 1);
	}
	else
	{
		nbr = n;
		ft_put_n(tab, nbr, count);
	}
	tab[count] = '\0';
	return (tab);
}
