/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elara-va <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/28 19:04:05 by elara-va          #+#    #+#             */
/*   Updated: 2025/07/04 13:53:26 by elara-va         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_stack_node *top)
{
	int	tmp;

	if (top == NULL || top->next == NULL)
		return ;
	tmp = top->nb;
	top->nb = top->next->nb;
	top->next->nb = tmp;
	return ;
}

void	push(t_stack_node **top_1, t_stack_node **top_2)
{
	t_stack_node	*new_top_1;

	if (*top_2 == NULL)
		return ;
	new_top_1 = *top_2;
	*top_2 = (*top_2)->next;
	if (*top_2)
		(*top_2)->prev = NULL;
	if (*top_1)
		(*top_1)->prev = new_top_1;
	new_top_1->prev = NULL;
	new_top_1->next = *top_1;
	*top_1 = new_top_1;
	return ;
}

void	rotate(t_stack_node **top)
{
	t_stack_node	*new_top;
	t_stack_node	*bottom;

	if (*top == NULL || (*top)->next == NULL)
		return ;
	new_top = (*top)->next;
	new_top->prev = NULL;
	bottom = *top;
	while (bottom->next != NULL)
		bottom = bottom->next;
	bottom->next = *top;
	(*top)->prev = bottom;
	(*top)->next = NULL;
	*top = new_top;
	return ;
}

void	rev_rotate(t_stack_node **top)
{
	t_stack_node	*bottom;

	if (*top == NULL || (*top)->next == NULL)
		return ;
	bottom = *top;
	while (bottom->next != NULL)
		bottom = bottom->next;
	bottom->prev->next = NULL;
	bottom->prev = NULL;
	bottom->next = *top;
	(*top)->prev = bottom;
	*top = bottom;
	return ;
}
