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

static void	sort_tree(t_stack **a);

static void	sort_four(t_stack **a, t_stack **b)
{
	if (!b || !*b)
		pb(a, b);
	if (!is_sorted(a))
		sort_tree(a);
	if ((*b)->value < (*a)->value)
		pa(a, b);
	else if ((*b)->value < (*a)->next->value && (*b)->value > (*a)->value)
	{
		ra(a);
		pa(a, b);
		rra(a);
	}
	else if ((*b)->value > ft_last(*a)->value)
	{
		pa(a, b);
		ra(a);
	}
	else
	{
		rra(a);
		pa(a, b);
		ra(a);
		ra(a);
	}
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

int	is_sorted(t_stack **stack)
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

void	sort_stack(t_stack **a, t_stack **b, int size)
{
	if (size > 5)
	{
		ft_index(a);
		ft_big_sort(a, b);
	}
	if (size == 5)
		ft_sort_five(a, b);
	if (size == 4)
		sort_four(a, b);
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
