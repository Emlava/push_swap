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

void	sort_3(struct s_node **stack_a)
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

void	sort_4_5(struct s_node **stack_a, struct s_node **stack_b, int ac)
{
	int	size_of_a;

	size_of_a = ac;
	push_lowest(stack_a, stack_b, &size_of_a);
	sort_3(stack_a);
	while (size_of_a < ac)
	{
		rules(stack_a, stack_b, "pa");
		size_of_a++;
	}
	return ;
}

void	sort_6_100(struct s_node **stack_a, struct s_node **stack_b,
	struct s_sizes sizes)
{
	int				chunk_size;
	struct s_node	*highest_b;
	int				arg_nbr;

	chunk_size = sizes.ac / sizes.x;
	sizes.size_of_a = sizes.ac;
	while (sizes.size_of_a > 0)
	{
		pb_by_chunks(stack_a, stack_b, sizes);
		sizes.size_of_a -= chunk_size;
	}
	if (*stack_a)
		sizes.size_of_b = sizes.ac - 1;
	else
		sizes.size_of_b = sizes.ac;
	while (*stack_b != NULL)
	{
		highest_b = *stack_b;
		arg_nbr = find_highest(&highest_b, sizes.size_of_b);
		rotate_to_top('B', stack_b, arg_nbr, sizes.size_of_b--);
		rules(stack_a, stack_b, "pa");
	}	
	return ;
}

void	sort(struct s_node **stack_a, struct s_sizes sizes)
{
	struct s_node	*stack_b;

	stack_b = NULL;
	determine_x(&sizes.x, sizes.ac);
	if (sizes.ac == 2)
		rules(stack_a, NULL, "sa");
	else if (sizes.ac == 3)
		sort_3(stack_a);
	else if (sizes.ac >= 4 && sizes.ac <= 5)
		sort_4_5(stack_a, &stack_b, sizes.ac);
	else if (sizes.ac > 6)
		sort_6_100(stack_a, &stack_b, sizes);
}

int	main(int ac, char *av[])
{
	struct s_node	*stack_a;
	struct s_sizes	sizes;
	int				ops;

	if (ac < 2)
		return (0);
	stack_a = malloc(sizeof(struct s_node));
	if (!stack_a)
		return (1);
	ac--;
	if (fill_stack_a(ac, av + 1, stack_a) == -1)
		return (1);
	if (check_if_sorted(stack_a))
	{
		ft_printf("Already sorted!\n");
		free_stack(stack_a);
		return (0);
	}
	sizes.ac = ac;
	sort(&stack_a, sizes);
	ops = rules(NULL, NULL, "o");
	ft_printf("\nInput size: %d \nOperations: %d\nn * log_2(n) = %d\n",
		ac, ops, ac * get_log_2(ac));
	free_stack(stack_a);
	return (0);
}
