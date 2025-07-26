/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elara-va <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/20 20:52:26 by elara-va          #+#    #+#             */
/*   Updated: 2025/07/22 15:31:36 by elara-va         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	find_chunk_values(struct s_node *stack_a,
	struct s_chunks *chunk, int size_of_a)
{
	struct s_node	*lowest;
	size_t			i;
	int				curr_lowest;

	lowest = stack_a;
	i = 0;
	chunk->locations[i][0] = find_lowest(&lowest, size_of_a);
	chunk->locations[i][1] = lowest->nb;
	while ((int)i + 1 < chunk->chunk_size && (int)i + 1 < size_of_a)
	{
		curr_lowest = lowest->nb;
		lowest = stack_a;
		i++;
		chunk->locations[i][0] = find_next_lowest(&lowest, size_of_a, curr_lowest);
		chunk->locations[i][1] = lowest->nb;
	}
	chunk->locations[i + 1][0] = 0;
	return ;
}

void	location_to_push(struct s_chunks *chunk, int size_of_a)
{
	size_t	i;
	int		closer_to_top;
	int		closer_to_bottom;

	i = 0;
	closer_to_top = chunk->locations[i][0];
	closer_to_bottom = chunk->locations[i][0];
	while (chunk->locations[i + 1][0] != 0)
	{
		if (chunk->locations[i + 1][0] < closer_to_top)
			closer_to_top = chunk->locations[i + 1][0];
		else if (chunk->locations[i + 1][0] > closer_to_bottom)
			closer_to_bottom = chunk->locations[i + 1][0];
		i++;
	}
	if (closer_to_bottom <= (size_of_a / 2) + 1)
		chunk->to_push = closer_to_top;
	else if (closer_to_top > (size_of_a / 2) + 1)
		chunk->to_push = closer_to_bottom;
	else if (closer_to_top - 1 < (size_of_a - closer_to_bottom) + 1)
		chunk->to_push = closer_to_top;
	else
		chunk->to_push = closer_to_bottom;
	return ;
}

void	pb_by_chunks(struct s_node **stack_a, struct s_node **stack_b,
	struct s_sizes sizes)
{
	struct s_chunks	chunk;
	struct s_node	*highest_b;
	int				arg_nbr_h_b;

	chunk.chunk_size = sizes.ac / sizes.x;
	while (sizes.size_of_a && chunk.chunk_size)
	{
		find_chunk_values(*stack_a, &chunk, sizes.size_of_a);
		location_to_push(&chunk, sizes.size_of_a);
		prepare_stacks(stack_a, stack_b, chunk, sizes);
		if (sizes.size_of_a == 1)
		{
			highest_b = *stack_b;
			arg_nbr_h_b = find_highest(&highest_b, sizes.ac - 1);
			if ((*stack_a)->nb > highest_b->nb)
				return ;
		}
		rules(stack_a, stack_b, "pb");
		chunk.chunk_size--;
		sizes.size_of_a--;
	}
	if (sizes.size_of_a == 0)
		rotate_to_top('B', stack_b, arg_nbr_h_b + 1, sizes.ac);
	return ;
}

