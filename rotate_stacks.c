/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_stacks.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elara-va <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 17:34:46 by elara-va          #+#    #+#             */
/*   Updated: 2025/07/25 17:34:48 by elara-va         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_stacks(struct s_node **stack_a, struct s_node **stack_b,
	struct s_arg_nbrs_rt arg_nbrs, struct s_sizes sizes)
{
	if (arg_nbrs.a <= (sizes.size_of_a / 2) + 1 && arg_nbrs.b <= (sizes.size_of_b / 2) + 1)
	{
		while (arg_nbrs.a > 1 && arg_nbrs.b > 1)
		{
			rules(stack_a, stack_b, "rr");
			arg_nbrs.a--;
			arg_nbrs.b--;
		}
	}
	else if (arg_nbrs.a > (sizes.size_of_a / 2) + 1 && arg_nbrs.b > (sizes.size_of_b / 2) + 1)
	{
		while (arg_nbrs.a < sizes.size_of_a + 1 && arg_nbrs.b < sizes.size_of_b + 1)
		{
			rules(stack_a, stack_b, "rrr");
			arg_nbrs.a++;
			arg_nbrs.b++;
		}
	}
	rotate_to_top('A', stack_a, arg_nbrs.a, sizes.size_of_a);
	rotate_to_top('B', stack_b, arg_nbrs.b, sizes.size_of_b);
	return ;
}
