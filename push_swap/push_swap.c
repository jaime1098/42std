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

void	count_movs(t_node **stack_a, t_variable *variable, int search)
{
	t_node	*aux;
	t_node	*find;

	find = NULL;
	aux = *stack_a;
	variable->total = 0;
	variable->racount = 0;
	while (aux)
	{
		variable->total++;
		if (aux->ideal == search)
			find = aux;
		aux = aux->next;
		if (!find)
		variable->racount++;
	}
	//printf("total = %d, ra = %d\n", variable->total, variable->racount);
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

void	read_args(char **argv, t_variable *variable, t_node **stack_a)
{
	int	i;
	int	j;

	i = 0;
	while (argv[++i])
	{
		j = 0;
		variable->splited = ft_split(argv[i], ' ');
		while (variable->splited[j])
		{
			variable->num = ft_atoi(variable->splited[j]);
			create_list(stack_a, *variable);
			j++;
		}
	}
	free (variable->splited);
}

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

void	ft_order(t_node **stack_a, t_node **stack_b, t_variable *variable)
{
	t_node	*aux_a;
	int		search;
	//t_node *aux_b;
	search = 1;
	aux_a = *stack_a;
	variable->ideal--;
	//print_stacks(*stack_a, *stack_b);
	while (variable->ideal > search)
	{
		count_movs(stack_a, variable, search);
		if (variable->total - variable->racount > variable->total / 2)
			rotate_a(stack_a);
		else
			rrotate_a(stack_a);
		aux_a = *stack_a;
		if (aux_a->ideal == search)
		{
			push_b(stack_a, stack_b);
			search++;
		}
	}
	while (variable->ideal-- > 1)
		push_a(stack_a, stack_b);
	//print_stacks(*stack_a, *stack_b);
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
	read_args(argv, &variable, &stack_a);
	variable.min = INT_MAX;
	variable.max = INT_MIN;
	variable.ideal = 1;
	get_ideal(&stack_a, &variable);
	//print_stacks(stack_a, stack_b);
	ft_order(&stack_a, &stack_b, &variable);
	//print_stacks(stack_a, stack_b);
	return (0);
}
