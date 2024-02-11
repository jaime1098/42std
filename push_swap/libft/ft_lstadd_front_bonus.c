/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joltra-r <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 18:46:43 by joltra-r          #+#    #+#             */
/*   Updated: 2023/10/22 18:48:26 by joltra-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (!lst || !new)
		return ;
	new->next = *lst;
	*lst = new;
}

/*void	print_t_list(t_list *head)
{
	t_list	*current;

	current = head;
	while (current)
	{
		printf("%s ", (char *)current ->content);
		current = current ->next;
	}
	printf("\n");
}

int	main(void)
{
	// Create new nodes
    t_list *node1 = ft_lstnew("I");
    t_list *node2 = ft_lstnew("want");
    t_list *node3 = ft_lstnew("churros");

	node2 ->next = node3;
	ft_lstadd_front(&node2, node1);
	print_t_list(node2);
	return (0);
}*/