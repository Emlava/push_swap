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

static void	find_chunk_values(t_stack_node *stack_a,
	t_chunk *chunk, t_sizes sizes)
{
	t_stack_node	*lowest;
	size_t			i;
	int				curr_lowest;

	lowest = stack_a;
	i = 0;
	chunk->locations[i][0] = find_lowest(&lowest, sizes.size_of_a);
	chunk->locations[i][1] = lowest->nb;
	while ((int)i + 1 < sizes.chunk_size && (int)i + 1 < sizes.size_of_a)
	{
		curr_lowest = lowest->nb;
		lowest = stack_a;
		i++;
		chunk->locations[i][0]
			= find_next_lowest(&lowest, sizes.size_of_a, curr_lowest);
		chunk->locations[i][1] = lowest->nb;
	}
	chunk->locations[i + 1][0] = 0;
	return ;
}

static void	location_to_push(t_chunk *chunk, int size_of_a)
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

void	pb_by_chunks(t_stack_node **stack_a, t_stack_node **stack_b,
	t_sizes sizes)
{
	t_chunk	chunk;

	while (sizes.size_of_a > 3 && sizes.chunk_size)
	{
		find_chunk_values(*stack_a, &chunk, sizes);
		location_to_push(&chunk, sizes.size_of_a);
		rotate_to_top('A', stack_a, chunk.to_push, sizes.size_of_a);
		rules(stack_a, stack_b, "pb");
		sizes.chunk_size--;
		sizes.size_of_a--;
	}
	return ;
}
