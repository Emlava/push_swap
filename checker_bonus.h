/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elara-va <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 16:24:14 by elara-va          #+#    #+#             */
/*   Updated: 2025/07/29 16:24:15 by elara-va         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_BONUS_H
# define CHECKER_BONUS_H
# include "push_swap.h"

typedef struct s_instruction_node
{
	char						*instruction;
	struct s_instruction_node	*next;
}	t_instruction_node;

void	rules_bonus(t_stack_node **stack_a, t_stack_node **stack_b, char *rule);
int		check_if_sorted_bonus(t_stack_node *stack_a);
void	create_next_instruction_node(char *curr_instruction,
			t_instruction_node **curr_node, t_instruction_node *instructions);
void	free_instruction_list(t_instruction_node *curr);

#endif
