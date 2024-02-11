/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joltra-r <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 13:03:40 by joltra-r          #+#    #+#             */
/*   Updated: 2023/10/26 13:03:43 by joltra-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if (lst == NULL || del == NULL)
		return ;
	del(lst->content);
	free(lst);
}
/*
int main()
{
	t_list *node = (t_list *)malloc(sizeof(t_list));
	int *value = (int *)malloc(sizeof(int));
	*value = 42;
	node->content = value;
	node->next = NULL;
	ft_lstdelone(node, free_int);
	if (node == NULL)
		printf("Nodo y contenido liberados correctamente.\n");
	else
		printf("Error al liberar la memoria del nodo y su contenido.\n");
	return 0;
}*/
