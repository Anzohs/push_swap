/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hladeiro <hladeiro@student.42lisboa.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 17:37:21 by hladeiro          #+#    #+#             */
/*   Updated: 2024/09/20 17:37:23 by hladeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	is_sorted(t_stack **stack)
{
	t_stack	*tmp;

	tmp = *stack;
	if (!tmp)
		return (0);
	while (tmp->next)
	{
		if (tmp->value > tmp->next->value)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

static void	sort_tree(t_stack **a)
{
	t_stack	*tmp;

	tmp = (*a)->next;
	if ((*a)->value > tmp->value)
	{
		if (tmp->value > tmp->next->value && (*a)->value > tmp->next->value)
		{
			ra(a);
			sa(a);
		}
		else if (tmp->value < tmp->next->value && \
				(*a)->value > tmp->next->value)
			ra(a);
		else
			sa(a);
	}
	else if ((*a)->value > tmp->next->value)
		rra(a);
	else
	{
		rra(a);
		sa(a);
	}
}

void	sort_stack(t_stack **a, t_stack **b, int size)
{
	if (*b)
		write(1, "a\n", 1);
	if (size > 5)
		exit(0);
	if (size == 5)
		exit(0);
	if (size == 4)
		exit(0);
	if (size == 3)
		sort_tree(a);
	if (size == 2)
		sa(a);
}

void	sort(t_stack **stack)
{
	t_stack	*b;

	b = NULL;
	while (!is_sorted(stack))
	{
		sort_stack(stack, &b, stack_len(stack));
	}
	ft_stack_free(*stack);
}
