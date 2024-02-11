/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joltra-r <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 13:17:49 by joltra-r          #+#    #+#             */
/*   Updated: 2023/10/26 13:17:50 by joltra-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_l;
	t_list	*new_n;
	void	*aux;

	if (!f || !del)
		return (NULL);
	new_l = NULL;
	while (lst)
	{
		aux = f(lst ->content);
		new_n = ft_lstnew(aux);
		if (!new_n)
		{
			del(aux);
			ft_lstclear(&new_l, del);
			return (NULL);
		}
		ft_lstadd_back(&new_l, new_n);
		lst = lst ->next;
	}
	return (new_l);
}
