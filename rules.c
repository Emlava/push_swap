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

#include "push_swap.h"

void    s_rules(struct s_node *stack_a, struct s_node *stack_b, char *rule)
{
    if (ft_strncmp(rule, "sa", 2) == 0)
    {
        swap(stack_a);
        write(1, "sa\n", 3);
    }
    else if (ft_strncmp(rule, "sb", 2) == 0)
    {
        swap(stack_b);
        write(1, "sb\n", 3);
    }
    else if (ft_strncmp(rule, "ss", 2) == 0)
    {
        swap(stack_a);
        swap(stack_b);
        write(1, "ss\n", 3);
    }
    return ;
}

void    p_rules(struct s_node **stack_a, struct s_node **stack_b, char *rule)
{
    if (ft_strncmp(rule, "pa", 2) == 0)
    {
        push(stack_a, stack_b);
        write(1, "pa\n", 3);
    }
    else if (ft_strncmp(rule, "pb", 2) == 0)
    {
        push(stack_b, stack_a);
        write(1, "pb\n", 3);
    }
    return ;
}

void    r_rules(struct s_node **stack_a, struct s_node **stack_b, char *rule)
{
    if (ft_strncmp(rule, "ra", 2) == 0)
    {
        rotate(stack_a);
        write(1, "ra\n", 3);
    }
    else if (ft_strncmp(rule, "rb", 2) == 0)
    {
        rotate(stack_b);
        write(1, "rb\n", 3);
    }
    else if (ft_strncmp(rule, "rr", 3) == 0)
    {
        rotate(stack_a);
        rotate(stack_b);
        write(1, "rr\n", 3);
    }
    return ;
}

void    rr_rules(struct s_node **stack_a, struct s_node **stack_b, char *rule)
{
    if (ft_strncmp(rule, "rra", 3) == 0)
    {
        rev_rotate(stack_a);
        write(1, "rra\n", 4);
    }
    else if (ft_strncmp(rule, "rrb", 3) == 0)
    {
        rev_rotate(stack_b);
        write(1, "rrb\n", 4);
    }
    else if (ft_strncmp(rule, "rrr", 3) == 0)
    {
        rev_rotate(stack_a);
        rev_rotate(stack_b);
        write(1, "rrr\n", 4);
    }
    return ;
}