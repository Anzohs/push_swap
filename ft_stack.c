/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hladeiro <hladeiro@student.42lisboa.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 20:43:12 by hladeiro          #+#    #+#             */
/*   Updated: 2024/09/21 20:43:14 by hladeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*ft_last(t_stack *stack)
{
	t_stack	*tmp;

	tmp = stack;
	while (tmp->next)
		tmp = tmp->next;
	return (tmp);
}

int	min_num(t_stack **stack)
{
	t_stack	*tmp;
	int		num;

	tmp = *stack;
	while (tmp)
	{
		if (tmp->index == 0)
		{
			num = tmp->value;
			break ;
		}
		tmp = tmp->next;
	}
	tmp = *stack;
	while (tmp)
	{
		if (tmp->value < num && tmp->index == 0)
			num = tmp->value;
		tmp = tmp->next;
	}
	return (num);
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

void	add_node(t_stack **stack, int i)
{
	t_stack	*s;

	s = ft_calloc(sizeof(t_stack), 1);
	if (!s)
		return ;
	s->value = i;
	s->next = NULL;
	s->index = 0;
	if (!*stack)
		*stack = s;
	else
		ft_last(*stack)->next = s;
}

void	ft_stack_free(t_stack *s)
{
	t_stack	*tmp;

	tmp = s;
	while (s->next)
	{
		s = s->next;
		free(tmp);
		tmp = s;
	}
	if (s)
		free(s);
	s = NULL;
}
