/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hladeiro <hladeiro@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 09:58:13 by hladeiro          #+#    #+#             */
/*   Updated: 2024/09/12 16:14:10 by hladeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_error(void);

void add_node(t_stack **stack, int value)
{
	t_stack *new;
	t_stack *tmp;

	new = ft_calloc(1, sizeof(t_stack));
	if (!new)
	{
		ft_error();
		while (*stack)
		{
			tmp = *stack;
			*stack = (*stack)->next;
			free(tmp);
		}
		return ;
	}
	new->value = value;
	if (!*stack)
	{
		*stack = new;
		(*stack)->next = NULL;
		return ;
	}
	tmp = *stack;
	if (tmp->next)
	{
	while (tmp->next)
		tmp = tmp->next;
	}
	tmp->next = new;
}

void	ft_error(void)
{
	ft_putstr_fd("Error\n", 2);
	exit(1);
}

void split_argv(char **argv, t_stack **stack_a)
{
	char **split;
	int i;
	int j;

	i = -1;
	split = ft_split(argv[1], ' ');
	if (!split)
	{
		ft_putstr_fd("split of the string gonne wrong\n", 2);
		return ;
	}
	while (split[++i] != NULL)
	{
		j = 0;
		while (split[i][j])
		{
			if (!ft_isdigit(split[i][j]))
				ft_error();
			j++;
		}
		add_node(stack_a, ft_atoi(split[i]));
		free(split[i]);
	}
	free(split);
}

void add_argv(int argc, char **argv, t_stack **stack_a)
{
	int i;
	int j;

	i = 0;
	while (++i < argc)
	{
		j = 0;
		while (argv[i][j])
		{
			if (!ft_isdigit(argv[i][j]))
				ft_error();
			j++;
		}
		add_node(stack_a, ft_atoi(argv[i]));
	}
	if (!*stack_a)
		ft_error();
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;

	stack_a = NULL;
	if (argc < 2)
		return (0);
	if (argc == 2)
		split_argv(argv, &stack_a);
	else
		add_argv(argc, argv, &stack_a);
	while (stack_a)
	{
		t_stack *tmp = stack_a;
		printf("stack value: %d\n", stack_a->value);
		stack_a = stack_a->next;
		free(tmp);
	}
	return (0);
}
