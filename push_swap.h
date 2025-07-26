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

struct s_chunks
{
	int			chunk_size;
	int			locations[101][2];
	int			to_push;
};

struct	s_sizes
{
	int	ac;
	int	size_of_a;
	int	size_of_b;
	int	x;
};

struct	s_arg_nbrs_rt
{
	int	a;
	int	b;
};

int		fill_stack_a(int ac, char *av[], struct s_node *stack_a);
int		check_if_sorted(struct s_node *stack_a);
void	swap(struct s_node *top);
void	push(struct s_node **top_1, struct s_node **top_2);
void	rotate(struct s_node **top);
void	rev_rotate(struct s_node **top);
void	s_rules(struct s_node **stack_a, struct s_node **stack_b, char *rule);
void	p_r_rr_rules(struct s_node **stack_a, struct s_node **stack_b,
			char *rule);
int		rules(struct s_node **stack_a, struct s_node **stack_b, char *rule);
void	determine_x(int *x, int ac);
void	push_lowest(struct s_node **stack_a, struct s_node **stack_b, int *ac);
int		find_next_lowest(struct s_node **ptr, int size_of_a, int curr_lowest);
int		find_lowest(struct s_node **ptr, int ac);
void	find_chunk_values(struct s_node *stack_a,
			struct s_chunks *chunk, int size_of_a);
void	location_to_push(struct s_chunks *chunk, int size_of_a);
void	rotate_to_top(char which_stack, struct s_node **stack,
		int arg_nbr, int size_of_stack);
int		find_highest(struct s_node **ptr, int size_of_stack);
int		find_next_highest(struct s_node **ptr, int size_of_stack, int curr_highest);
void	rotate_stacks(struct s_node **stack_a, struct s_node **stack_b,
		struct s_arg_nbrs_rt arg_nbrs, struct s_sizes sizes);
void	prepare_stacks(struct s_node **stack_a, struct s_node **stack_b, struct s_chunks chunk, struct s_sizes sizes);
void	pb_by_chunks(struct s_node **stack_a, struct s_node **stack_b,
			struct s_sizes sizes);
void	free_stack(struct s_node *curr);
int		get_log_2(int ac);

#endif