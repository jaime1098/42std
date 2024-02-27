/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   order.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joltra-r <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 12:40:21 by joltra-r          #+#    #+#             */
/*   Updated: 2024/02/26 12:40:22 by joltra-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_order_a(t_node **stack_a)
{
	t_node	*aux;

	aux = *stack_a;
	while (aux->next && aux->ideal + 1 == aux->next->ideal)
		aux = aux->next;
	if (!aux->next)
		return (0);
	else
		return (1);
}

void	final_push(t_node **stack_a, t_node **stack_b, int auxideal)
{
	t_node		*aux_a;
	t_node		*aux_b;
	t_variable	variable;

	aux_b = (*stack_b);
	while ((*stack_b))
		push_a(stack_a, stack_b);
	aux_a = (*stack_a);
	count_movs(stack_a, &variable, auxideal);
	if (variable.total - variable.racount > variable.total / 2)
	{
		while (aux_a->ideal != 1)
		{
			rotate_a(stack_a);
			aux_a = (*stack_a);
		}
	}
	else
	{
		while (aux_a->ideal != 1)
		{
			rrotate_a(stack_a);
			aux_a = (*stack_a);
		}
	}
}

void	ft_order(t_node **stack_a, t_node **stack_b, t_variable *variable)
{
	t_node	*aux_a;
	t_node	*aux_b;
	int		search;
	int		auxideal;

	search = 1;
	aux_a = *stack_a;
	variable->ideal--;
	auxideal = variable->ideal;
	while (variable->ideal > search)
	{
		if (check_order_a(stack_a) == 0)
			break ;
		aux_a = *stack_a;
		if (variable->ideal == aux_a->ideal)
		{
			push_b(stack_a, stack_b);
			aux_b = *stack_b;
			aux_a = *stack_a;
			variable->ideal--;
			if (aux_b->next)
			{
				rotate_b(stack_b);
				aux_b = *stack_b;
			}
		}
		if (aux_a->ideal == search)
		{
			push_b(stack_a, stack_b);
			search++;
		}
		count_movs(stack_a, variable, search);
		if (variable->total - variable->racount > variable->total / 2)
			rotate_a(stack_a);
		else
			rrotate_a(stack_a);
		aux_a = *stack_a;
	}
	final_push(stack_a, stack_b, auxideal);
}
