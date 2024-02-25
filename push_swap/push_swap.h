/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joltra-r <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 14:59:14 by joltra-r          #+#    #+#             */
/*   Updated: 2024/02/11 14:59:16 by joltra-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <limits.h>

typedef struct s_variable
{
	char	**splited;
	int		min;
	int		max;
	int		num;
	int		ideal;
	int		total;
	int		racount;
}				t_variable;

typedef struct s_node
{
	int				value;
	int				ideal;
	struct s_node	*next;
}				t_node;

void	get_ideal(t_node **stack_a, t_variable *variable);
void	ft_order(t_node **stack_a, t_node **stack_b, t_variable *variable);
void	count_movs(t_node **stack_a, t_variable *variable, int search);
void	print_stacks(t_node *stack_a, t_node *stack_b);
void	push_a(t_node **stack_a, t_node **stack_b);
void	push_b(t_node **stack_a, t_node **stack_b);
void	swap_a(t_node **stack_a);
void	swap_b(t_node **stack_b);
void	swap_ss(t_node **stack_a, t_node **stack_b);
void	rotate_a(t_node **stack_a);
void	rotate_b(t_node **stack_b);
void	rotate_rr(t_node **stack_a, t_node **stack_b);
void	rrotate_a(t_node **stack_a);
void	rrotate_b(t_node **stack_b);
void	rrotate_rr(t_node **stack_a, t_node **stack_b);

#endif