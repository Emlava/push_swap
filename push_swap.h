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
# include "libft/libft.h"

typedef struct s_node
{
	int				nb;
	struct s_node	*prev;
	struct s_node	*next;
}	t_stack_node;

typedef struct s_chunk
{
	int			locations[501][2];
	int			to_push;
}	t_chunk;

typedef struct s_sizes
{
	int	real_ac;
	int	size_of_a;
	int	size_of_b;
	int	chunk_size;
}	t_sizes;

typedef struct s_arg_nbrs_rt
{
	int	a;
	int	b;
}	t_arg_nbrs_rt;

typedef struct s_op_count_resources
{
	size_t	total_op_count;
	ssize_t	lowest_op_count;
	int		lowest_op_args[2];
}	t_op_count_resources;

/* ---- fill_stack_a.c ---- */
void	fill_stack_a(int ac, int *real_ac, char *av[], t_stack_node *stack_a);

/* ---- fill_stack_a_utilities --- */
void	skip_spaces(char **arg_str);
void	copy_sub_str(char **arg_str, char *sub_str, t_stack_node *stack_a);
int		multiple_args_in_str(char *str);
void	check_for_dups(t_stack_node *curr, int nb, t_stack_node *stack_a);
void	free_stack(t_stack_node *curr);

/* ---- general_utilities.c ---- */
int		check_if_sorted(t_stack_node *stack_a);
void	rotate_to_top(char which_stack, t_stack_node **stack,
			int arg_nbr, int size_of_stack);
void	rotate_stacks(t_stack_node **stack_a, t_stack_node **stack_b,
			t_arg_nbrs_rt arg_nbrs, t_sizes sizes);

/* ---- rules.c ---- */
void	rules(t_stack_node **stack_a, t_stack_node **stack_b, char *rule);

/* ---- actions.c ---- */
void	swap(t_stack_node *top);
void	push(t_stack_node **top_1, t_stack_node **top_2);
void	rotate(t_stack_node **top);
void	rev_rotate(t_stack_node **top);

/* ---- manage_chunks.c ---- */
void	pb_by_chunks(t_stack_node **stack_a, t_stack_node **stack_b,
			t_sizes sizes);

/* ---- find_extremes.c ---- */
int		find_highest(t_stack_node **ptr, int size_of_stack);
int		find_next_highest(t_stack_node **ptr, int size_of_stack,
			int curr_highest);
int		find_lowest(t_stack_node **ptr, int ac);
int		find_next_lowest(t_stack_node **ptr, int size_of_a, int curr_lowest);

/* ---- manage_pa.c ---- */
void	manage_pa(t_stack_node **stack_a, t_stack_node **stack_b,
			t_sizes sizes);

#endif