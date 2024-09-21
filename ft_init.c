/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hladeiro <hladeiro@student.42lisboa.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 18:43:07 by hladeiro          #+#    #+#             */
/*   Updated: 2024/09/19 18:43:08 by hladeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_stack	*ft_last(t_stack *stack)
{
	t_stack	*tmp;

	tmp = stack;
	while (tmp->next)
		tmp = tmp->next;
	return (tmp);
}

static void	add_node(t_stack **stack, int i)
{
	t_stack	*s;

	s = ft_calloc(sizeof(t_stack), 1);
	if (!s)
		return ;
	s->value = i;
	s->next = NULL;
	if (!*stack)
		*stack = s;
	else
		ft_last(*stack)->next = s;
}

int	stack_len(t_stack **stack)
{
	t_stack	*tmp;
	int		i;

	i = 0;
	tmp = *stack;
	while (tmp)
	{
		i++;
		tmp = tmp->next;
	}
	return (i);
}

int	is_valid(t_stack **stack)
{
	t_stack	*tmp;

	tmp = *stack;
	while (tmp)
	{
		if (tmp->value > INT_MAX || tmp->value < INT_MIN)
		{
			ft_putstr_fd("Error\n", 2);
			return (0);
		}
		tmp = tmp->next;
	}
	return (1);
}

void	ft_init_stack(t_stack **stack, char **s, int argv)
{
	int	i;

	if (argv == 2)
		i = 0;
	else
		i = 1;
	while (s[i])
		add_node(stack, ft_atoi(s[i++]));
	if (!is_valid(stack))
	{
		ft_stack_free(*stack);
		ft_putstr_fd("Error\n", 2);
		return ;
	}
	sort(stack);
}
