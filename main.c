/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hladeiro <hladeiro@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 09:58:13 by hladeiro          #+#    #+#             */
/*   Updated: 2024/09/12 15:36:52 by hladeiro         ###   ########.fr       */
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

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	char	**split;
	int	i;

	stack_a = NULL;
	if (argc < 2)
		return (0);
	if (argc == 2)
		split = ft_split(argv[1], ' ');
	i = -1;
	while (split[++i] != NULL)
	{
		add_node(&stack_a, ft_atoi(split[i]));
		free(split[i]);
	}
	if (!stack_a)
	{
		ft_error();
		return (0);
	}
	while (stack_a)
	{
		t_stack *tmp = stack_a;
		printf("stack value: %d\n", stack_a->value);
		stack_a = stack_a->next;
		free(tmp);
	}
	free(split);
	return (0);
}
