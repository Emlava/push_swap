/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elara-va <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 16:48:58 by elara-va          #+#    #+#             */
/*   Updated: 2025/07/07 16:49:00 by elara-va         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_if_sorted(struct s_node *stack_a)
{
	struct s_node	*curr;

	curr = stack_a;
	while (curr->next != NULL && curr->nb < curr->next->nb)
		curr = curr->next;
	if (curr->next == NULL)
	{
		ft_printf("Already sorted!\n");
		free_stack(stack_a);
		exit(EXIT_SUCCESS);
	}
	return ;
}

void	sort(struct s_node *stack_a, int ac)
{
	struct s_node	*stack_b;

	stack_b = NULL;
	if (ac == 2)
		swap(stack_a);
	else if (ac == 3)
		
}

int	main(int ac, char *av[])
{
	struct s_node	*stack_a;

	if (ac < 2)
		return (0);
	stack_a = malloc(sizeof(struct s_node));
	ac--;
	fill_stack_a(ac, av + 1, stack_a);
    check_if_sorted(stack_a);
	sort(stack_a, ac);
	free_stack(stack_a);
	return (0);
}