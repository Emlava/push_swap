/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elara-va <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 14:39:13 by elara-va          #+#    #+#             */
/*   Updated: 2025/07/04 13:52:18 by elara-va         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static size_t	if_space_or_sign(const char *nptr, t_stack_node *stack_a)
{
	size_t	i;

	i = 0;
	while (nptr[i] == ' ')
		i++;
	if (nptr[i] == '+' || nptr[i] == '-')
		i++;
	if (nptr[i] < '0' || nptr[i] > '9')
	{
		free_stack(stack_a);
		write(2, "Error\n", 6);
		exit(EXIT_FAILURE);
	}
	return (i);
}

static int	atoi_err(const char *nptr, t_stack_node *stack_a)
{
	size_t		i;
	int			minus;
	long long	result;

	minus = 0;
	result = 0;
	i = if_space_or_sign(nptr, stack_a);
	if (i && nptr[i - 1] == '-')
		minus = 1;
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		result = result * 10 + (nptr[i] - '0');
		i++;
	}
	if (minus)
		result = -result;
	if (nptr[i] != '\0' || result < INT_MIN || result > INT_MAX)
	{
		free_stack(stack_a);
		write(2, "Error\n", 6);
		exit(EXIT_FAILURE);
	}
	return ((int)result);
}

static void	manage_string_with_multiple_args(int *real_ac, char *arg_str,
	t_stack_node *stack_a, t_stack_node **curr)
{
	char			sub_str[11];

	skip_spaces(&arg_str);
	while (*arg_str)
	{
		(*curr)->next = NULL;
		copy_sub_str(&arg_str, sub_str, stack_a);
		(*curr)->nb = atoi_err(sub_str, stack_a);
		skip_spaces(&arg_str);
		if (*arg_str == '-' || *arg_str == '+'
			|| (*arg_str >= '0' && *arg_str <= '9'))
		{
			(*curr)->next = malloc(sizeof(t_stack_node));
			if (!(*curr)->next)
				exit(EXIT_FAILURE);
			(*curr)->next->prev = *curr;
			*curr = (*curr)->next;
		}
		if (real_ac)
			(*real_ac)++;
	}
	if (real_ac)
		(*real_ac)--;
	return ;
}

void	fill_stack_a(int ac, int *real_ac, char *av[], t_stack_node *stack_a)
{
	t_stack_node	*curr;
	int				i;

	stack_a->prev = NULL;
	curr = stack_a;
	i = 0;
	while (i < ac)
	{
		if (multiple_args_in_str(av[i]))
			manage_string_with_multiple_args(real_ac, av[i], stack_a, &curr);
		else
		{
			curr->next = NULL;
			curr->nb = atoi_err(av[i], stack_a);
		}
		check_for_dups(curr, curr->nb, stack_a);
		if (i++ + 1 != ac)
		{
			curr->next = malloc(sizeof(t_stack_node));
			if (!curr->next)
				exit(EXIT_FAILURE);
			curr->next->prev = curr;
			curr = curr->next;
		}
	}
}
