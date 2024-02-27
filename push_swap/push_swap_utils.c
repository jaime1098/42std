/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joltra-r <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 17:17:44 by joltra-r          #+#    #+#             */
/*   Updated: 2024/02/17 17:17:45 by joltra-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*ft_nodelast(t_node *lst)
{
	if (lst == NULL)
		return (NULL);
	while (lst->next != NULL)
		lst = lst->next;
	return (lst);
}

void	print_stack_a(t_node *stack_a)
{
	if (!stack_a)
		stack_a = NULL;
	printf("Stack A:\n");
	while (stack_a != NULL)
	{
		if (stack_a)
		{
			printf("%d\n", stack_a->value);
			stack_a = stack_a->next;
		}
	}
	printf("\n");
}

void	print_stacks(t_node *stack_a, t_node *stack_b)
{
	if (!stack_b)
		stack_b = NULL;
	if (!stack_a)
		stack_a = NULL;
	printf("Stack A:	Stack B\n");
	while (stack_a != NULL || stack_b != NULL)
	{
		if (stack_a)
		{
			printf("%d", stack_a->value);
			stack_a = stack_a->next;
		}
		printf("		");
		if (stack_b != NULL)
		{
			printf("%d", stack_b->value);
			stack_b = stack_b->next;
		}
		printf("\n");
	}
	printf("\n");
}

// void	print_stacks(t_node *stack_a, t_node *stack_b)
// {
// 	printf("Stack A:\n ");
// 	while (stack_a)
// 	{
// 		printf("%d\n ", stack_a->value);
// 		stack_a = stack_a->next;
// 	}
// 	printf("\nStack B:\n ");
// 	while (stack_b)
// 	{
// 		printf("%d\n ", stack_b->value);
// 		stack_b = stack_b->next;
// 	}
// 	printf("\n");
// }
