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

void	create_list(t_node **stack_a, int num)
{
	t_node	*node;
	t_node	*staux;

	node = (t_node *) malloc (sizeof(t_node));
	if (!node)
		return ;
	node->value = num;
	node->next = NULL;
	staux = *stack_a;
	if (!*stack_a)
		*stack_a = node;
	else
	{
		while(staux->next)
			staux = staux->next;
		staux = node;
	}
	printf("%d\n", staux->value);
}

int	main(int argc, char **argv)
{
	t_node	*stack_a;
	//t_node	*stack_b;
	int		num;
	char	**splited;
	int		i;

	stack_a = NULL;
	//stack_b = NULL;
	i = 0;
	if (argc < 2 || argv[1][0] == '\0')
		return (0);
	splited = ft_split(argv[1], ' ');
	while (splited[i])
	{
		num = ft_atoi(splited[i++]);
		create_list(&stack_a, num);
	}
}
