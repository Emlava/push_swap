/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elara-va <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/12 14:43:42 by elara-va          #+#    #+#             */
/*   Updated: 2025/07/12 14:43:46 by elara-va         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

static void	s_rules(t_stack_node **stack_a, t_stack_node **stack_b, char *rule)
{
	if (ft_strncmp(rule, "sa\n", 3) == 0)
		swap(*stack_a);
	else if (ft_strncmp(rule, "sb\n", 3) == 0)
		swap(*stack_b);
	else if (ft_strncmp(rule, "ss\n", 3) == 0)
	{
		swap(*stack_a);
		swap(*stack_b);
	}
	return ;
}

static void	p_r_rr_rules(t_stack_node **stack_a, t_stack_node **stack_b,
	char *rule)
{
	if (ft_strncmp(rule, "pa\n", 3) == 0)
		push(stack_a, stack_b);
	else if (ft_strncmp(rule, "pb\n", 3) == 0)
		push(stack_b, stack_a);
	else if (ft_strncmp(rule, "ra\n", 3) == 0)
		rotate(stack_a);
	else if (ft_strncmp(rule, "rb\n", 3) == 0)
		rotate(stack_b);
	else if (ft_strncmp(rule, "rr\n", 3) == 0)
	{
		rotate(stack_a);
		rotate(stack_b);
	}
	else if (ft_strncmp(rule, "rra\n", 4) == 0)
		rev_rotate(stack_a);
	else if (ft_strncmp(rule, "rrb\n", 4) == 0)
		rev_rotate(stack_b);
	else if (ft_strncmp(rule, "rrr\n", 4) == 0)
	{
		rev_rotate(stack_a);
		rev_rotate(stack_b);
	}
	return ;
}

void	rules_bonus(t_stack_node **stack_a, t_stack_node **stack_b, char *rule)
{
	if (rule[0] == 's')
		s_rules(stack_a, stack_b, rule);
	else
		p_r_rr_rules(stack_a, stack_b, rule);
	return ;
}
