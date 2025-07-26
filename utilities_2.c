/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elara-va <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 18:11:57 by elara-va          #+#    #+#             */
/*   Updated: 2025/07/17 18:11:59 by elara-va         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_if_sorted(struct s_node *stack_a)
{
	struct s_node	*curr;

	curr = stack_a;
	while (curr->next != NULL && curr->nb < curr->next->nb)
		curr = curr->next;
	if (curr->next == NULL)
		return (1);
	return (0);
}

int	find_lowest(struct s_node **ptr, int size_of_stack)
{
	struct s_node	*lowest;

	lowest = *ptr;
	while ((*ptr)->next != NULL)
	{
		if ((*ptr)->next->nb < lowest->nb)
			lowest = (*ptr)->next;
		*ptr = (*ptr)->next;
	}
	while ((*ptr)->nb != lowest->nb)
	{
		*ptr = (*ptr)->prev;
		size_of_stack--;
	}
	return (size_of_stack);
}

int	find_next_lowest(struct s_node **ptr, int size_of_stack, int curr_lowest)
{
	struct s_node	*next_lowest;

	next_lowest = *ptr;
	while (next_lowest->next != NULL && next_lowest->nb < curr_lowest)
		next_lowest = next_lowest->next;
	*ptr = next_lowest;
	while ((*ptr)->next != NULL)
	{
		if ((*ptr)->next->nb > curr_lowest && (*ptr)->next->nb < next_lowest->nb)
			next_lowest = (*ptr)->next;
		*ptr = (*ptr)->next;
	}
	while ((*ptr)->nb != next_lowest->nb)
	{
		*ptr = (*ptr)->prev;
		size_of_stack--;
	}
	return (size_of_stack);
}

void	push_lowest(struct s_node **stack_a, struct s_node **stack_b, int *size_of_stack)
{
	struct s_node	*lowest;
	int				arg_nbr;

	while (*size_of_stack >= 4)
	{
		lowest = *stack_a;
		arg_nbr = find_lowest(&lowest, *size_of_stack);
		rotate_to_top('A', stack_a, arg_nbr, *size_of_stack);
		rules(stack_a, stack_b, "pb");
		(*size_of_stack)--;
	}
	return ;
}

int	get_log_2(int ac)
{
	int log;

	log = 0;
	while (ac / 2 >= 1)
	{
		ac /= 2;
		log++;
	}
	return (log);
}
