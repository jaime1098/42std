/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joltra-r <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 13:10:38 by joltra-r          #+#    #+#             */
/*   Updated: 2024/02/13 13:10:39 by joltra-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_a(t_node **stack_a, t_node **stack_b)
{
	t_node	*temp;
	t_node	*new_node;

	new_node = malloc(sizeof(t_node));
	if (!new_node)
		write(2, "error al crear nodo\n", 20);
	new_node->value = (*stack_b)->value;
	new_node->ideal = (*stack_b)->ideal;
	new_node->next = (*stack_a);
	*stack_a = new_node;
	temp = *stack_b;
	*stack_b = (*stack_b)->next;
	free(temp);
	write(1, "pa\n", 3);
}

void	push_b(t_node **stack_a, t_node **stack_b)
{
	t_node	*temp;
	t_node	*new_node;

	new_node = malloc(sizeof(t_node));
	if (!new_node)
		write(2, "error al crear nodo\n", 20);
	new_node->value = (*stack_a)->value;
	new_node->ideal = (*stack_a)->ideal;
	new_node->next = (*stack_b);
	*stack_b = new_node;
	temp = *stack_a;
	*stack_a = (*stack_a)->next;
	free(temp);
	write(1, "pb\n", 3);
}
