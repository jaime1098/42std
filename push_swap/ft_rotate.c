/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joltra-r <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 13:10:50 by joltra-r          #+#    #+#             */
/*   Updated: 2024/02/13 13:10:51 by joltra-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_a(t_node **stack_a)
{
	t_node	*first;
	t_node	*last;

	first = *stack_a;
	if (*stack_a && (*stack_a)->next)
	{
		*stack_a = (*stack_a)->next;
		last = *stack_a;
		while (last->next)
			last = last->next;
		last->next = first;
		first->next = NULL;
		write(1, "ra\n", 3);
	}
}

void	rotate_b(t_node **stack_b)
{
	t_node	*first;
	t_node	*last;

	first = *stack_b;
	if (*stack_b && (*stack_b)->next)
	{
		*stack_b = (*stack_b)->next;
		last = *stack_b;
		while (last->next)
			last = last->next;
		last->next = first;
		first->next = NULL;
		write(1, "rb\n", 3);
	}
}

void	rotate_rr(t_node **stack_a, t_node **stack_b)
{
	t_node	*first1;
	t_node	*last1;
	t_node	*first2;
	t_node	*last2;

	first1 = *stack_a;
	first2 = *stack_b;
	if (*stack_a && (*stack_a)->next && *stack_b && (*stack_b)->next)
	{
		*stack_a = (*stack_a)->next;
		last1 = *stack_a;
		while (last1->next)
			last1 = last1->next;
		last1->next = first1;
		first1->next = NULL;
		*stack_b = (*stack_b)->next;
		last2 = *stack_b;
		while (last2->next)
			last2 = last2->next;
		last2->next = first2;
		first2->next = NULL;
	}
	write (1, "rr\n", 3);
}
