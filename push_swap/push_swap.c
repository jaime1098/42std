/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joltra-r <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 15:01:16 by joltra-r          #+#    #+#             */
/*   Updated: 2024/02/11 15:01:18 by joltra-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	get_ideal(t_node **stack_a, t_variable *variable)
{
	t_node	*list;
	t_node	*listideal;

	list = *stack_a;
	listideal = NULL;
	while (list)
	{
		if (variable->min > list->value && list->value > variable->max)
		{
			variable->min = list->value;
			listideal = list;
			list = list->next;
		}
		else
			list = list->next;
	}
	if (listideal)
	{
		listideal->ideal = variable->ideal++;
		variable->max = listideal->value;
		variable->min = INT_MAX;
		list = *stack_a;
		get_ideal(stack_a, variable);
	}
}

void	ft_order(t_node **stack_a, t_node **stack_b)
{
	t_node *sexo;

	sexo = *stack_a;
	while (sexo->ideal != 1)
		rotate_a(stack_a);
	print_stacks(*stack_a, *stack_b);
	push_b(stack_a, stack_b);
	print_stacks(*stack_a, *stack_b);
}

void	create_list(t_node **stack_a, t_variable variable)
{
	t_node	*node;
	t_node	*staux;

	node = (t_node *) malloc (sizeof(t_node));
	if (!node)
		return ;
	node->value = variable.num;
	node->next = NULL;
	staux = *stack_a;
	if (!*stack_a)
		*stack_a = node;
	else
	{
		while (staux->next)
			staux = staux->next;
		staux->next = node;
	}
}

int	main(int argc, char **argv)
{
	t_node		*stack_a;
	t_node		*stack_b;
	t_variable	variable;
	int			i;

	stack_a = NULL;
	stack_b = NULL;
	i = -1;
	if (argc < 2 || argv[1][0] == '\0')
		return (0);
	variable.splited = ft_split(argv[1], ' ');
	while (variable.splited[++i])
	{
		variable.num = ft_atoi(variable.splited[i]);
		create_list(&stack_a, variable);
	}
	variable.min = INT_MAX;
	variable.max = INT_MIN;
	variable.ideal = 1;
	get_ideal(&stack_a, &variable);
	ft_order(&stack_a, &stack_b);
	return (0);
}
