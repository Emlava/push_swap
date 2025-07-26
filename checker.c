/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elara-va <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/28 19:08:42 by elara-va          #+#    #+#             */
/*   Updated: 2025/07/07 15:09:03 by elara-va         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "push_swap.h"

int	main(int ac, char *av[])
{
	struct s_node	*stack_a;
	struct s_node	*stack_b;
	size_t			op_count;
	struct s_node	*curr_a;
	struct s_node	*curr_b;
	char			rule[5];

	if (ac < 2)
		return (0);
	stack_a = malloc(sizeof(struct s_node));
	stack_b = NULL;
	ac--;
	op_count = 0;
	fill_stack_a(ac, av + 1, stack_a);
	if (stack_a->next == NULL)
	{	
		ft_printf("\n\t——\t\t\t——\n\t%d\n\t——\t\t\t——\n\tA\t\t\tB\n\n", stack_a->nb);
		return (0);
	}
	while (ft_strncmp(rule, "exit", 5) != 0)
	{
		ft_printf("\nInput size: %d\nOperation count: %d\n\n\t——\t\t\t——\n", ac, op_count);
		curr_a = stack_a;
		curr_b = stack_b;
		while (curr_a != NULL || curr_b != NULL)
		{
			if (curr_a && curr_b)
				ft_printf("\t%d\t\t\t%d\n", curr_a->nb, curr_b->nb);
			else if (curr_a && !curr_b)
				ft_printf("\t%d\t\t\t\n", curr_a->nb);
			else if (!curr_a && curr_b)
				ft_printf("\t\t\t\t%d\n", curr_b->nb);
			if (curr_a)
				curr_a = curr_a->next;
			if (curr_b)	
				curr_b = curr_b->next;
		}
		if (curr_a && curr_b)
			ft_printf("\t%d\t\t\t%d\n", curr_a->nb, curr_b->nb);
		if (curr_a && !curr_b)
			ft_printf("\t%d\t\t\t\n", curr_a->nb);
		if (!curr_a && curr_b)
			ft_printf("\t\t\t\t%d\n", curr_b->nb);
		ft_printf("\t——\t\t\t——\n\tA\t\t\tB\n\n");
		ft_printf("Enter rule (\"exit\" to stop): ");
		scanf("%s", rule);
		if (ft_strncmp(rule, "sa", 5) == 0)
			swap(stack_a);
		else if (ft_strncmp(rule, "sb", 5) == 0)
			swap(stack_b);
		else if (ft_strncmp(rule, "ss", 5) == 0)
		{
			swap(stack_a);
			swap(stack_b);
		}
		else if (ft_strncmp(rule, "pa", 5) == 0)
			push(&stack_a, &stack_b);
		else if (ft_strncmp(rule, "pb", 5) == 0)
			push(&stack_b, &stack_a);
		else if (ft_strncmp(rule, "ra", 5) == 0)
			rotate(&stack_a);
		else if (ft_strncmp(rule, "rb", 5) == 0)
			rotate(&stack_b);
		else if (ft_strncmp(rule, "rr", 5) == 0)
		{
			rotate(&stack_a);
			rotate(&stack_b);
		}
		else if (ft_strncmp(rule, "rra", 5) == 0)
			rev_rotate(&stack_a);
		else if (ft_strncmp(rule, "rrb", 5) == 0)
			rev_rotate(&stack_b);
		else if (ft_strncmp(rule, "rrr", 5) == 0)
		{
			rev_rotate(&stack_a);
			rev_rotate(&stack_b);
		}
		else if (ft_strncmp(rule, "exit", 5) != 0)
		{
			ft_printf("\nINVALID RULE\n");
			continue ;
		}
		op_count++;
	}
	free_stack(stack_a);
	free_stack(stack_b);
	return (0);
}
