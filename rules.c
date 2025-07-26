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

void    s_rules(struct s_node **stack_a, struct s_node **stack_b, char *rule)
{
    if (ft_strncmp(rule, "sa", 2) == 0)
        swap(*stack_a);
    else if (ft_strncmp(rule, "sb", 2) == 0)
        swap(*stack_b);
    else if (ft_strncmp(rule, "ss", 2) == 0)
    {
        swap(*stack_a);
        swap(*stack_b);
    }
    return ;
}

void    p_r_rr_rules(struct s_node **stack_a, struct s_node **stack_b, char *rule)
{
    if (ft_strncmp(rule, "pa", 2) == 0)
        push(stack_a, stack_b);
    else if (ft_strncmp(rule, "pb", 2) == 0)
        push(stack_b, stack_a);
    else if (ft_strncmp(rule, "ra", 2) == 0)
        rotate(stack_a);
    else if (ft_strncmp(rule, "rb", 2) == 0)
        rotate(stack_b);
    else if (ft_strncmp(rule, "rr", 3) == 0)
    {
        rotate(stack_a);
        rotate(stack_b);
    }
    else if (ft_strncmp(rule, "rra", 3) == 0)
        rev_rotate(stack_a);
    else if (ft_strncmp(rule, "rrb", 3) == 0)
        rev_rotate(stack_b);
    else if (ft_strncmp(rule, "rrr", 3) == 0)
    {
        rev_rotate(stack_a);
        rev_rotate(stack_b);
    }
    return ;
}

int    rules(struct s_node **stack_a, struct s_node **stack_b, char *rule)
{
    static int  nbr_of_ops;

    if (rule[0] == 's')
        s_rules(stack_a, stack_b, rule);
    else if (rule[0] != 'o')
        p_r_rr_rules(stack_a, stack_b, rule);
    else
        return (nbr_of_ops);
    ft_printf("%s\n", rule);
    nbr_of_ops++;
    return (0);
}
