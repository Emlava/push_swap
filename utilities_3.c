/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities_3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elara-va <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 08:11:24 by elara-va          #+#    #+#             */
/*   Updated: 2025/07/23 08:11:26 by elara-va         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	determine_x(int *x, int ac)
{
	if (ac < 6)
		*x = 0;
	else if (ac >= 6)
		*x = 3;
	if (ac > 60 && ac < 200)	
	{
		while (ac / *x > 20)
			(*x)++;
	}
	else if (ac >= 200)
	{
		while (ac / *x > 35)
			(*x)++;
	}
	return ;
}

int	find_highest(struct s_node **ptr, int size_of_stack)
{
	struct s_node	*highest;

	highest = *ptr;
	while ((*ptr)->next != NULL)
	{
		if ((*ptr)->next->nb > highest->nb)
			highest = (*ptr)->next;
		*ptr = (*ptr)->next;
	}
	while ((*ptr)->nb != highest->nb)
	{
		*ptr = (*ptr)->prev;
		size_of_stack--;
	}
	return (size_of_stack);
}

int	find_next_highest(struct s_node **ptr, int size_of_stack, int curr_highest)
{
	struct s_node	*next_highest;

	next_highest = *ptr;
	while (next_highest->next != NULL && next_highest->nb > curr_highest)
		next_highest = next_highest->next;
	*ptr = next_highest;
	while ((*ptr)->next != NULL)
	{
		if ((*ptr)->next->nb < curr_highest && (*ptr)->next->nb > next_highest->nb)
			next_highest = (*ptr)->next;
		*ptr = (*ptr)->next;
	}
	while ((*ptr)->nb != next_highest->nb)
	{
		*ptr = (*ptr)->prev;
		size_of_stack--;
	}
	return (size_of_stack);
}

void	rotate_to_top(char which_stack, struct s_node **stack, int arg_nbr, int size_of_stack)
{
	if (which_stack == 'A')
	{
		if (arg_nbr <= (size_of_stack / 2) + 1)
		{
			while (arg_nbr-- > 1)
				rules(stack, NULL, "ra");
		}
		else
		{
			while (arg_nbr++ < size_of_stack + 1)
				rules(stack, NULL, "rra");
		}
		return ;
	}
	if (arg_nbr <= (size_of_stack / 2) + 1)
	{
		while (arg_nbr-- > 1)
			rules(NULL, stack, "rb");
	}
	else
	{
		while (arg_nbr++ < size_of_stack + 1)
			rules(NULL, stack, "rrb");
	}
	return ;
}

int	define_arg_nbr_b(struct s_node *highest_b, struct s_node *lowest_b,
	struct s_sizes sizes, int value_to_top_a)
{
	int				arg_nbr_h_b;
	int				arg_nbr_l_b;
	struct s_node	*highest_b_cpy;

	arg_nbr_h_b = find_highest(&highest_b, sizes.size_of_b);
	arg_nbr_l_b = find_lowest(&lowest_b, sizes.size_of_b);
	highest_b_cpy = highest_b;
	if (value_to_top_a > highest_b->nb)
		return (arg_nbr_h_b);
	else if (value_to_top_a < lowest_b->nb)
		return (arg_nbr_l_b);
	else
	{
		highest_b = highest_b_cpy;
		arg_nbr_h_b = find_next_highest(&highest_b, sizes.size_of_b, value_to_top_a);
		return (arg_nbr_h_b);
	}
}

int	get_value_from_location(struct s_chunks chunk)
{
	size_t	i;

	i = 0;
	while (chunk.to_push != chunk.locations[i][0])
		i++;
	return (chunk.locations[i][1]);
}

void	prepare_stacks(struct s_node **stack_a, struct s_node **stack_b,
	struct s_chunks chunk, struct s_sizes sizes)
{
	struct s_node			*highest_b;
	struct s_node			*lowest_b;
	int						value_to_top_a;
	int						arg_nbr_b;
	struct s_arg_nbrs_rt	arg_nbrs;

	if (*stack_b == NULL)
	{
		rotate_to_top('A', stack_a, chunk.to_push, sizes.size_of_a);
		return ;
	}
	highest_b = *stack_b;
	lowest_b = *stack_b;
	sizes.size_of_b = sizes.ac - sizes.size_of_a;
	value_to_top_a = get_value_from_location(chunk);
	arg_nbr_b = define_arg_nbr_b(highest_b, lowest_b, sizes, value_to_top_a);
	arg_nbrs.a = chunk.to_push;
	arg_nbrs.b = arg_nbr_b;
	rotate_stacks(stack_a, stack_b, arg_nbrs, sizes);
	return ;
}
