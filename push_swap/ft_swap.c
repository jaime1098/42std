/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joltra-r <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 13:10:31 by joltra-r          #+#    #+#             */
/*   Updated: 2024/02/13 13:10:32 by joltra-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_a(t_node **stack_a)
{
	int	tmp;

	if (*stack_a && (*stack_a)->next)
	{
		tmp = (*stack_a)->value;
		(*stack_a)->value = (*stack_a)->next->value;
		(*stack_a)->next->value = tmp;
	}
	write(1, "sa\n", 3);
}

void	swap_b(t_node **stack_b)
{
	int	tmp;

	if (*stack_b && (*stack_b)->next)
	{
		tmp = (*stack_b)->value;
		(*stack_b)->value = (*stack_b)->next->value;
		(*stack_b)->next->value = tmp;
	}
	write(1, "sb\n", 3);
}

void	swap_ss(t_node **stack_a, t_node **stack_b)
{
	int	tmp1;
	int	tmp2;

	if (*stack_a && (*stack_a)->next)
	{
		tmp1 = (*stack_a)->value;
		(*stack_a)->value = (*stack_a)->next->value;
		(*stack_a)->next->value = tmp1;
	}
	if (*stack_b && (*stack_b)->next)
	{
		tmp2 = (*stack_b)->value;
		(*stack_b)->value = (*stack_b)->next->value;
		(*stack_b)->next->value = tmp2;
	}
	write (1, "ss\n", 3);
}
