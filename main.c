/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elara-va <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 16:48:58 by elara-va          #+#    #+#             */
/*   Updated: 2025/07/20 16:05:24 by elara-va         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_3(t_stack_node **stack_a)
{
	int	top;
	int	mid;
	int	bottom;

	top = (*stack_a)->nb;
	mid = (*stack_a)->next->nb;
	bottom = (*stack_a)->next->next->nb;
	if ((top > mid && (mid > bottom || bottom > top))
		|| (top < mid && top < bottom))
		rules(stack_a, NULL, "sa");
	else if (top < mid && top > bottom)
		rules(stack_a, NULL, "rra");
	else
		rules(stack_a, NULL, "ra");
	if (!check_if_sorted(*stack_a))
		sort_3(stack_a);
	return ;
}

static void	sort_4_5(t_stack_node **stack_a, t_stack_node **stack_b, int ac)
{
	int				size_of_a;
	t_stack_node	*lowest;
	int				arg_nbr;

	size_of_a = ac;
	while (size_of_a >= 4)
	{
		lowest = *stack_a;
		arg_nbr = find_lowest(&lowest, size_of_a);
		rotate_to_top('A', stack_a, arg_nbr, size_of_a);
		if (!check_if_sorted(*stack_a))
		{
			rules(stack_a, stack_b, "pb");
			size_of_a--;
		}
		else
			break ;
	}
	if (!check_if_sorted(*stack_a))
		sort_3(stack_a);
	while (size_of_a < ac)
	{
		rules(stack_a, stack_b, "pa");
		size_of_a++;
	}
}

static void	sort_6_500(t_stack_node **stack_a, t_stack_node **stack_b,
	t_sizes sizes)
{
	t_stack_node	*lowest_a;

	sizes.chunk_size = sizes.real_ac / 3;
	sizes.size_of_a = sizes.real_ac;
	while (sizes.size_of_a > 3)
	{
		pb_by_chunks(stack_a, stack_b, sizes);
		sizes.size_of_a -= sizes.chunk_size;
	}
	sort_3(stack_a);
	sizes.size_of_b = sizes.real_ac - 3;
	sizes.size_of_a = 3;
	manage_pa(stack_a, stack_b, sizes);
	lowest_a = *stack_a;
	rotate_to_top('A', stack_a, find_lowest(&lowest_a,
			sizes.real_ac), sizes.real_ac);
	return ;
}

static void	sort(t_stack_node **stack_a, t_sizes sizes)
{
	t_stack_node	*stack_b;

	stack_b = NULL;
	if (sizes.real_ac == 2)
		rules(stack_a, NULL, "sa");
	else if (sizes.real_ac == 3)
		sort_3(stack_a);
	else if (sizes.real_ac >= 4 && sizes.real_ac <= 5)
		sort_4_5(stack_a, &stack_b, sizes.real_ac);
	else if (sizes.real_ac >= 6)
		sort_6_500(stack_a, &stack_b, sizes);
	return ;
}

int	main(int ac, char *av[])
{
	t_stack_node	*stack_a;
	t_sizes			sizes;

	if (ac < 2)
		return (0);
	stack_a = malloc(sizeof(t_stack_node));
	if (!stack_a)
		return (1);
	ac--;
	sizes.real_ac = ac;
	fill_stack_a(ac, &sizes.real_ac, av + 1, stack_a);
	if (check_if_sorted(stack_a))
	{
		free_stacks_exit(stack_a, NULL, 0);
		return (0);
	}
	sort(&stack_a, sizes);
	free_stacks_exit(stack_a, NULL, 0);
	return (0);
}
