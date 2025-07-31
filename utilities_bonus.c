/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elara-va <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 07:05:56 by elara-va          #+#    #+#             */
/*   Updated: 2025/07/30 07:05:57 by elara-va         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

int	check_if_sorted_bonus(t_stack_node *stack_a)
{
	t_stack_node	*curr;

	curr = stack_a;
	while (curr->next != NULL && curr->nb < curr->next->nb)
		curr = curr->next;
	if (curr->next == NULL)
		return (1);
	return (0);
}

void	free_instruction_list(t_instruction_node *curr)
{
	t_instruction_node	*tmp;

	while (curr != NULL)
	{
		tmp = curr;
		curr = curr->next;
		free(tmp);
	}
	return ;
}
