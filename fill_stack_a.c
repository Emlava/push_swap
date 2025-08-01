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

void	free_stack(t_stack_node *curr)
{
	t_stack_node	*tmp;

	while (curr != NULL)
	{
		tmp = curr;
		curr = curr->next;
		free(tmp);
	}
	return ;
}

static void	check_for_dups(t_stack_node *curr, int nb, t_stack_node *stack_a)
{
	curr = curr->prev;
	while (curr != NULL)
	{
		if (curr->nb == nb)
		{
			free_stack(stack_a);
			write(2, "Error\n", 6);
			exit(EXIT_FAILURE);
		}
		curr = curr->prev;
	}
	return ;
}

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

void	fill_stack_a(int ac, char *av[], t_stack_node *stack_a)
{
	t_stack_node	*curr;
	int				i;

	stack_a->prev = NULL;
	curr = stack_a;
	i = 0;
	while (i < ac)
	{
		curr->next = NULL;
		curr->nb = atoi_err(av[i], stack_a);
		check_for_dups(curr, curr->nb, stack_a);
		if (i + 1 != ac)
		{
			curr->next = malloc(sizeof(t_stack_node));
			if (!curr->next)
				exit(EXIT_FAILURE);
			curr->next->prev = curr;
			curr = curr->next;
		}
		i++;
	}
	return ;
}
