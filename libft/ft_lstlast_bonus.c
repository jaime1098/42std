/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joltra-r <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 18:30:05 by joltra-r          #+#    #+#             */
/*   Updated: 2023/10/22 18:49:44 by joltra-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	if (lst == NULL)
		return (NULL);
	while (lst->next != NULL)
		lst = lst->next;
	return (lst);
}
/*
int main()
{
  int value = 42;
	// Crear una lista con 3 nodos
	t_list *node1 = (t_list *)malloc(sizeof(t_list));
	t_list *node2 = (t_list *)malloc(sizeof(t_list));
	t_list *node3 = (t_list *)malloc(sizeof(t_list));

	node1->next = node2;
	node2->next = node3;
	node3->next = NULL;

	// Obtener el último nodo de la lista
	t_list *last_node = ft_lstlast(node1);

	if (last_node)
	{
		printf("Contenido del último nodo: %p\n", last_node->content);
	}
	else
	{
		printf("La lista está vacía.\n");
	}

	// Liberar la memoria de los nodos
	free(node1);
	free(node2);
	free(node3);

	return 0;
}*/
