/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elara-va <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 16:24:00 by elara-va          #+#    #+#             */
/*   Updated: 2025/07/29 16:24:03 by elara-va         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

static int	check_for_invalid_instructions(char *instruction)
{
	if (ft_strncmp(instruction, "sa\n", 4) == 0
		|| ft_strncmp(instruction, "sb\n", 4) == 0
		|| ft_strncmp(instruction, "ss\n", 4) == 0)
		return (0);
	else if (ft_strncmp(instruction, "pa\n", 4) == 0
		|| ft_strncmp(instruction, "pb\n", 4) == 0)
		return (0);
	else if (ft_strncmp(instruction, "ra\n", 4) == 0
		|| ft_strncmp(instruction, "rb\n", 4) == 0
		|| ft_strncmp(instruction, "rr\n", 4) == 0)
		return (0);
	else if (ft_strncmp(instruction, "rra\n", 5) == 0
		|| ft_strncmp(instruction, "rrb\n", 5) == 0
		|| ft_strncmp(instruction, "rrr\n", 5) == 0)
		return (0);
	else
		return (1);
}

static void	create_instruction_list(t_instruction_node *instructions)
{
	t_instruction_node	*curr_node;
	char				*curr_instruction;

	curr_node = instructions;
	curr_instruction = get_next_line(0);
	while (curr_instruction)
	{
		if (check_for_invalid_instructions(curr_instruction) == 1)
		{
			ft_printf("Error\n");
			free(curr_instruction);
			free_instruction_list(instructions);
			exit(EXIT_FAILURE);
		}
		curr_node->instruction = curr_instruction;
		curr_instruction = get_next_line(0);
		create_next_instruction_node(curr_instruction,
			&curr_node, instructions);
	}
	return ;
}

static void	run_instructions(t_stack_node **stack_a, t_stack_node **stack_b,
	t_instruction_node *instructions)
{
	while (instructions != NULL)
	{
		rules_bonus(stack_a, stack_b, instructions->instruction);
		instructions = instructions->next;
	}
	return ;
}

static void	give_output(t_stack_node *stack_a, t_stack_node *stack_b)
{
	if (stack_b == NULL && check_if_sorted_bonus(stack_a) == 1)
		ft_printf("OK\n");
	else
	{
		free_stack(stack_b);
		ft_printf("KO\n");
	}
	return ;
}

int	main(int ac, char *av[])
{
	t_stack_node		*stack_a;
	t_stack_node		*stack_b;
	t_instruction_node	*instructions;

	if (ac < 2)
		return (0);
	stack_a = malloc(sizeof(t_stack_node));
	if (!stack_a)
		return (1);
	stack_b = NULL;
	ac--;
	fill_stack_a(ac, NULL, av + 1, stack_a);
	if (!check_if_sorted_bonus(stack_a))
	{
		instructions = malloc(sizeof(t_instruction_node));
		if (!instructions)
			return (1);
		create_instruction_list(instructions);
		run_instructions(&stack_a, &stack_b, instructions);
		free_instruction_list(instructions);
	}
	give_output(stack_a, stack_b);
	free_stack(stack_a);
	return (0);
}
