/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hladeiro <hladeiro@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 09:58:13 by hladeiro          #+#    #+#             */
/*   Updated: 2024/09/13 14:45:08 by hladeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_error(char **split);
int		is_sorted(t_stack *stack);
void	sort(t_stack **stack);
int	same_values(char **split);
int len(t_stack **stack);
void sort_long(t_stack **stack);


void sort_long(t_stack **stack)
{

}

int len(t_stack **stack)
{
	t_stack *tmp;
	int i;

	i = 0;
	tmp = *stack;
	while (tmp)
	{
		i++;
		tmp = tmp->next;
	}
	return (i);
}

int	same_values(char **split)
{
	int i;
	int j;

	i = 0;
	while (split[i + 1])
	{
		j = i + 1;
		while (split[j])
		{
			if (ft_atoi(split[i]) == ft_atoi(split[j]))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

void sort(t_stack **stack)
{
	t_stack *tmp;
	t_stack *tmp2;
	int i;
	int j;
	int k;

	i = 0;
	j = 0;
	k = 0;
	tmp = *stack;
	
	if (len(stack) == 2)
	{
		if (tmp->value > tmp->next->value)
			sa(stack);
		return ;
	}
	if (len(stack) > 3)
	{
		sort_long(stact);
		return ;
	}
	if (tmp->next && tmp->next->next)
	{
		tmp2 = tmp->next;
		if(tmp->value > tmp2->value && tmp2->value < tmp2->next->value  && tmp->value < tmp2->next->value )
			sa(stack);
		else if (tmp->value < tmp2->value && tmp2->value > tmp2->next->value && tmp->value < tmp2->next->value)
		{
			rra(stack);
			sa(stack);
		}
		else if (tmp->value > tmp2->value && tmp->value > tmp2->next->value && tmp2->value < tmp2->next->value)
			ra(stack);
		else if (tmp->value > tmp2->value && tmp2->value > tmp2->next->value)
		{
			ra(stack);
			sa(stack);
		}
	}
}

int is_sorted(t_stack *stack)
{
	t_stack *tmp;

	tmp = stack;
	while (tmp->next)
	{
		if (tmp->value > tmp->next->value)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

void add_node(t_stack **stack, int value)
{
	t_stack *new;
	t_stack *tmp;
	char **c;	

	new = ft_calloc(1, sizeof(t_stack));
	if (!new)
	{
		ft_error(c);
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

void	ft_error(char **split)
{
	ft_putstr_fd("Error\n", 2);
	if (!split)
		exit(1);
	while (*split)
	{
		free(*split);
		split++;
	}
	if (split)
		free(split);
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
	if (same_values(split))
		ft_error(split);
	while (split[++i] != NULL)
	{
		j = 0;
		while (split[i][j])
		{
			if (!ft_isdigit(split[i][j]))
				ft_error(split);
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
	char **c;

	i = 0;
	while (++i < argc)
	{
		j = 0;
		while (argv[i][j])
		{
			if (!ft_isdigit(argv[i][j]))
				ft_error(c);
			j++;
		}
		add_node(stack_a, ft_atoi(argv[i]));
	}
	if (!*stack_a)
		ft_error(c);
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
	if (is_sorted(stack_a))
		ft_putstr_fd("stack is sorted\n", 1);
	else
	{
		while (is_sorted(stack_a) == 0)
		{
			sort(&stack_a);
		}
	}
		sort(&stack_a);
	while (stack_a)
	{
		t_stack *tmp = stack_a;
		stack_a = stack_a->next;
		free(tmp);
	}
	return (0);
}
