/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rrotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joltra-r <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 13:10:56 by joltra-r          #+#    #+#             */
/*   Updated: 2024/02/13 13:10:57 by joltra-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rrotate_a(t_node **stack_a)
{
	t_node	*first;
	t_node	*last;

	first = *stack_a;
	if (*stack_a && (*stack_a)->next)
	{
		while (first->next)
		{
			last = first;
			first = first->next;
		}
		first->next = *stack_a;
		last->next = NULL;
		*stack_a = first;
	}
	write (1, "rra\n", 4);
}

void	rrotate_b(t_node **stack_b)
{
	t_node	*first;
	t_node	*last;

	first = *stack_b;
	if (*stack_b && (*stack_b)->next)
	{
		while (first->next)
		{
			last = first;
			first = first->next;
		}
		first->next = *stack_b;
		last->next = NULL;
		*stack_b = first;
	}
	write (1, "rrb\n", 4);
}

void	rrotate_rr(t_node **stack_a, t_node **stack_b)
{
	t_node	*first1;
	t_node	*first2;
	t_node	*last1;
	t_node	*last2;

	first1 = *stack_a;
	first2 = *stack_b;
	if (*stack_a && (*stack_a)->next && *stack_b && (*stack_b)->next)
	{
		while (first1->next)
		{
			last1 = first1;
			first1 = first1->next;
		}
		first1->next = *stack_a;
		last1->next = NULL;
		*stack_a = first1;
		while (first2->next)
		{
			last2 = first2;
			first2 = first2->next;
		}
		first2->next = *stack_b;
		last2->next = NULL;
		*stack_b = first2;
	}
	write (1, "rrr\n", 4);
}
