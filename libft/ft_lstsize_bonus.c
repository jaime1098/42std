/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joltra-r <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 18:23:29 by joltra-r          #+#    #+#             */
/*   Updated: 2023/10/22 18:49:18 by joltra-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int	count;

	count = 0;
	while (lst)
	{
		count++;
		lst = lst->next;
	}
	return (count);
}

/*
int main()
{
	// Crear una lista con 3 nodos
	t_list *node1 = (t_list *)malloc(sizeof(t_list));
	t_list *node2 = (t_list *)malloc(sizeof(t_list));
	t_list *node3 = (t_list *)malloc(sizeof(t_list));

	node1->next = node2;
	node2->next = node3;
	node3->next = NULL;

	// Calcular la longitud de la lista
	int length = ft_lstsize(node1);

	printf("Longitud de la lista: %d\n", length);

	// Liberar la memoria de los nodos
	free(node1);
	free(node2);
	free(node3);

	return (0);
}*/
