/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_stack_utilities_a.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elara-va <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/03 15:04:32 by elara-va          #+#    #+#             */
/*   Updated: 2025/08/03 15:04:33 by elara-va         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	skip_spaces(char **arg_str)
{
	while (**arg_str == ' ')
		(*arg_str)++;
	return ;
}

void	copy_sub_str(char **arg_str, char *sub_str, t_stack_node *stack_a)
{
	size_t	i;

	i = 0;
	if (**arg_str == '+' || **arg_str == '-')
	{
		sub_str[i] = **arg_str;
		i++;
		(*arg_str)++;
	}
	while (i < 12 && **arg_str >= '0' && **arg_str <= '9')
	{
		sub_str[i] = **arg_str;
		i++;
		(*arg_str)++;
	}
	sub_str[i] = '\0';
	if (**arg_str && **arg_str != ' ')
	{
		write(2, "Error\n", 6);
		free_stacks_exit(stack_a, NULL, 1);
	}
	return ;
}

int	multiple_args_in_str(char *str)
{
	while (*str == ' ')
		str++;
	if (*str == '-' || *str == '+')
		str++;
	while (*str >= '0' && *str <= '9')
		str++;
	while (*str == ' ')
		str++;
	if (*str == '-' || *str == '+' || (*str >= '0' && *str <= '9'))
		return (1);
	else
		return (0);
}

void	check_for_dups(t_stack_node *curr, int nb, t_stack_node *stack_a)
{
	curr = curr->prev;
	while (curr != NULL)
	{
		if (curr->nb == nb)
		{
			write(2, "Error\n", 6);
			free_stacks_exit(stack_a, NULL, 1);
		}
		curr = curr->prev;
	}
	return ;
}

void	free_stacks_exit(t_stack_node *curr_a, t_stack_node *curr_b,
	int exit_status)
{
	t_stack_node	*tmp;

	while (curr_a != NULL)
	{
		tmp = curr_a;
		curr_a = curr_a->next;
		free(tmp);
	}
	while (curr_b != NULL)
	{
		tmp = curr_b;
		curr_b = curr_b->next;
		free(tmp);
	}
	if (exit_status == 1)
		exit(EXIT_FAILURE);
	return ;
}
