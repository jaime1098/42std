/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lstnew.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joltra-r <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 17:31:20 by joltra-r          #+#    #+#             */
/*   Updated: 2023/10/22 18:48:51 by joltra-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*new_node;

	new_node = (t_list *)malloc(sizeof(t_list));
	if (!new_node)
		return (NULL);
	new_node->content = content;
	new_node->next = NULL;
	return (new_node);
}
/*
int main()
{
int value = 42;

t_list *new_node = ft_lstnew(&value);
if (new_node)
{
printf("Nuevo nodo creado con contenido: %d\n", *((int *)new_node->content));
free(new_node);
}
else
printf("Error al crear el nuevo nodo.\n");
    return (0);
}*/
