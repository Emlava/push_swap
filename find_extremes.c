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

int	find_highest(t_stack_node **ptr, int size_of_stack)
{
	t_stack_node	*highest;

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

int	find_next_highest(t_stack_node **ptr, int size_of_stack, int curr_highest)
{
	t_stack_node	*next_highest;

	next_highest = *ptr;
	while (next_highest->next != NULL && next_highest->nb > curr_highest)
		next_highest = next_highest->next;
	*ptr = next_highest;
	while ((*ptr)->next != NULL)
	{
		if ((*ptr)->next->nb < curr_highest
			&& (*ptr)->next->nb > next_highest->nb)
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

int	find_lowest(t_stack_node **ptr, int size_of_stack)
{
	t_stack_node	*lowest;

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

int	find_next_lowest(t_stack_node **ptr, int size_of_stack, int curr_lowest)
{
	t_stack_node	*next_lowest;

	next_lowest = *ptr;
	while (next_lowest->next != NULL && next_lowest->nb < curr_lowest)
		next_lowest = next_lowest->next;
	*ptr = next_lowest;
	while ((*ptr)->next != NULL)
	{
		if ((*ptr)->next->nb > curr_lowest
			&& (*ptr)->next->nb < next_lowest->nb)
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
