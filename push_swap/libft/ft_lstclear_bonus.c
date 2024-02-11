/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joltra-r <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 13:16:36 by joltra-r          #+#    #+#             */
/*   Updated: 2023/10/26 13:16:38 by joltra-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*current_node;
	t_list	*next_node;

	if (lst == NULL || del == NULL)
		return ;
	current_node = *lst;
	while (current_node != NULL)
	{
		next_node = current_node->next;
		del(current_node->content);
		free(current_node);
		current_node = next_node;
	}
	*lst = NULL;
}

/*
int main()
{
	// Crear una lista enlazada con 3 nodos
	t_list *node1 = (t_list *)malloc(sizeof(t_list));
	t_list *node2 = (t_list *)malloc(sizeof(t_list));
	t_list *node3 = (t_list *)malloc(sizeof(t_list));

	int *value1 = (int *)malloc(sizeof(int));
	int *value2 = (int *)malloc(sizeof(int));
	int *value3 = (int *)malloc(sizeof(int));

	*value1 = 1;
	*value2 = 2;
	*value3 = 3;

	node1->content = value1;
	node2->content = value2;
	node3->content = value3;

	node1->next = node2;
	node2->next = node3;
	node3->next = NULL;

	// Utilizar ft_lstclear para eliminar y liberar la memoria de la lista
	ft_lstclear(&node1, free_int);

	// Verificar si la lista se eliminó correctamente
	if (node1 == NULL)
	{
		printf("Lista eliminada correctamente. El puntero al primer nodo es NULL.\n");
	}
	else
	{
		printf("Error al eliminar la lista.\n");
	}

	return 0;
}*/
