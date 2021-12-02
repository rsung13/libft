/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsung <rsung@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 20:46:37 by rsung             #+#    #+#             */
/*   Updated: 2021/12/01 14:47:28 by rsung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*ptr;
	t_list	*first;

	first = NULL;
	while (lst != NULL)
	{
		ptr = ft_lstnew((*f)(lst->content));
		if (ptr == NULL)
		{
			ft_lstclear(&first, (*del));
			return (NULL);
		}
		ft_lstadd_back(&first, ptr);
		lst = lst->next;
	}
	return (first);
}
