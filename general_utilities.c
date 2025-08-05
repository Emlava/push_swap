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

int	check_if_sorted(t_stack_node *stack_a)
{
	t_stack_node	*curr;

	curr = stack_a;
	while (curr->next != NULL && curr->nb < curr->next->nb)
		curr = curr->next;
	if (curr->next == NULL)
		return (1);
	return (0);
}

void	rotate_to_top(char which_stack, t_stack_node **stack,
	int arg_nbr, int size_of_stack)
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

void	rotate_stacks(t_stack_node **stack_a, t_stack_node **stack_b,
	t_arg_nbrs_rt arg_nbrs, t_sizes sizes)
{
	if (arg_nbrs.a <= (sizes.size_of_a / 2) + 1
		&& arg_nbrs.b <= (sizes.size_of_b / 2) + 1)
	{
		while (arg_nbrs.a > 1 && arg_nbrs.b > 1)
		{
			rules(stack_a, stack_b, "rr");
			arg_nbrs.a--;
			arg_nbrs.b--;
		}
	}
	else if (arg_nbrs.a > (sizes.size_of_a / 2) + 1
		&& arg_nbrs.b > (sizes.size_of_b / 2) + 1)
	{
		while (arg_nbrs.a < sizes.size_of_a + 1
			&& arg_nbrs.b < sizes.size_of_b + 1)
		{
			rules(stack_a, stack_b, "rrr");
			arg_nbrs.a++;
			arg_nbrs.b++;
		}
	}
	rotate_to_top('A', stack_a, arg_nbrs.a, sizes.size_of_a);
	rotate_to_top('B', stack_b, arg_nbrs.b, sizes.size_of_b);
	return ;
}
