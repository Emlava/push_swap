/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elara-va <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 13:31:28 by elara-va          #+#    #+#             */
/*   Updated: 2025/07/04 13:59:18 by elara-va         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <unistd.h>
# include <stddef.h>
# include <limits.h>
# include <stdlib.h>
# include "Libft/libft.h"

struct s_node
{
	int				nb;
	struct s_node	*prev;
	struct s_node	*next;
};

void	fill_stack_a(int ac, char *av[], struct s_node *stack_a);
void	swap(struct s_node *top);
void    push(struct s_node **top_1, struct s_node **top_2);
void    rotate(struct s_node **top);
void    rev_rotate(struct s_node **top);
void    s_rules(struct s_node *stack_a, struct s_node *stack_b, char *rule);
void    p_rules(struct s_node **stack_a, struct s_node **stack_b, char *rule);
void    r_rules(struct s_node **stack_a, struct s_node **stack_b, char *rule);
void    rr_rules(struct s_node **stack_a, struct s_node **stack_b, char *rule);
void	push_swap(struct s_node *stack_a);
void	free_stack(struct s_node *curr);

#endif