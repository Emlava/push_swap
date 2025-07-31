/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   A.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elara-va <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/27 14:24:23 by elara-va          #+#    #+#             */
/*   Updated: 2025/07/27 14:24:24 by elara-va         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	rr_rrr_ops(int arg_nbr_b, int arg_nbr_a, t_sizes sizes)
{
	int	rr_rrr_ops;

	rr_rrr_ops = 0;
	if (arg_nbr_a <= (sizes.size_of_a / 2) + 1
		&& arg_nbr_b <= (sizes.size_of_b / 2) + 1)
	{
		while (arg_nbr_a-- > 1 && arg_nbr_b-- > 1)
			rr_rrr_ops++;
	}
	else if (arg_nbr_a > (sizes.size_of_a / 2) + 1
		&& arg_nbr_b > (sizes.size_of_b / 2) + 1)
	{
		while (arg_nbr_a++ < sizes.size_of_a + 1
			&& arg_nbr_b++ < sizes.size_of_b + 1)
			rr_rrr_ops++;
	}
	return (rr_rrr_ops);
}

static size_t	determine_total_op_count(int arg_nbr_b, int arg_nbr_a,
	t_sizes sizes)
{
	int	op_count;

	op_count = 0;
	if (arg_nbr_b <= (sizes.size_of_b / 2) + 1)
		op_count = arg_nbr_b - 1;
	else
		op_count = (sizes.size_of_b + 1) - arg_nbr_b;
	if (arg_nbr_a <= (sizes.size_of_a / 2) + 1)
		op_count += arg_nbr_a - 1;
	else
		op_count += (sizes.size_of_a + 1) - arg_nbr_a;
	op_count -= rr_rrr_ops(arg_nbr_b, arg_nbr_a, sizes);
	return (op_count);
}

static void	check_if_lowest_op_count(t_op_count_resources *opcr, int *arg_nbr_b,
	int arg_nbr_a, t_sizes sizes)
{
	opcr->total_op_count
		= determine_total_op_count(*arg_nbr_b, arg_nbr_a, sizes);
	if (opcr->lowest_op_count == -1
		|| opcr->total_op_count < (size_t)opcr->lowest_op_count)
	{
		opcr->lowest_op_count = (ssize_t)opcr->total_op_count;
		opcr->lowest_op_args[0] = *arg_nbr_b;
		opcr->lowest_op_args[1] = arg_nbr_a;
	}
	(*arg_nbr_b)++;
	return ;
}

static void	easiest_to_accommodate(t_stack_node *stack_a,
	t_stack_node *stack_b, t_arg_nbrs_rt *arg_nbrs, t_sizes sizes)
{
	t_stack_node			*highest_a;
	t_stack_node			*lowest_a;
	int						arg_nbr_l_a;
	t_op_count_resources	opcr;

	arg_nbrs->b = 1;
	arg_nbrs->a = 0;
	opcr.lowest_op_count = -1;
	while (stack_b != NULL)
	{
		highest_a = stack_a;
		lowest_a = stack_a;
		find_highest(&highest_a, sizes.size_of_a);
		arg_nbr_l_a = find_lowest(&lowest_a, sizes.size_of_a);
		if (stack_b->nb < highest_a->nb && stack_b->nb > lowest_a->nb)
		{
			lowest_a = stack_a;
			arg_nbr_l_a
				= find_next_lowest(&lowest_a, sizes.size_of_a, stack_b->nb);
		}
		check_if_lowest_op_count(&opcr, &arg_nbrs->b, arg_nbr_l_a, sizes);
		stack_b = stack_b->next;
	}
	arg_nbrs->b = opcr.lowest_op_args[0];
	arg_nbrs->a = opcr.lowest_op_args[1];
}

void	manage_pa(t_stack_node **stack_a, t_stack_node **stack_b,
	t_sizes sizes)
{
	t_arg_nbrs_rt	arg_nbrs;

	while (*stack_b != NULL)
	{
		easiest_to_accommodate(*stack_a, *stack_b, &arg_nbrs, sizes);
		rotate_stacks(stack_a, stack_b, arg_nbrs, sizes);
		rules(stack_a, stack_b, "pa");
		sizes.size_of_b--;
		sizes.size_of_a++;
	}
	return ;
}
