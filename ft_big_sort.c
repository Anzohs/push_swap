/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_big_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hladeiro <hladeiro@student.42lisboa.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 17:34:55 by hladeiro          #+#    #+#             */
/*   Updated: 2024/09/22 17:34:57 by hladeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf/ft_printf.h"
#include "push_swap.h"

static int	smallest_last(t_stack **a)
{
	t_stack	*tmp;
	int		i;
	int		pos;
	int		count;

	tmp = *a;
	i = tmp->value;
	count = stack_len(a) / 2 - 1;
	pos = count;
	while (--count && tmp)
	{
		tmp = tmp->next;
	}
	count = stack_len(a) / 2;
	while(tmp)
	{
		if (tmp->value < i)
		{
			i = tmp->value;
			pos = count;
		}
		tmp = tmp->next;
		count++;
	}
	return (pos);
}

static int	smalles_num(t_stack **a)
{
	t_stack	*tmp;
	int		i;
	int		pos;
	int		count;

	tmp = *a;
	i = tmp->value;
	count = 0;
	pos = 0;
	while(tmp && count <= stack_len(a) / 2)
	{
		if (tmp->value < i)
		{
			i = tmp->value;
			pos = count;
		}
		tmp = tmp->next;
		count++;
	}
	return (pos);
}

void	ft_big_sort(t_stack **a, t_stack **b)
{
	int	i;
	while (*a)
	{
		if (stack_len(a)/2 - smalles_num(a) < stack_len(a) - smallest_last(a))
		{
			i = smallest_last(a);
			while (i != stack_len(a))
			{
				rra(a);
				i++;
			}
			if (!b || !*b)
				pb(a, b);
			else if ((*a)->value > (*b)->value)
			{
					pb(a, b);
					rb(b);
			}
			else
			{
			rrb(b);
			pb(a, b);
			rb(b);
			}
		}
		else
		{
			i = smalles_num(a);
			while (i != 0)
			{
				ra(a);
				i--;
			}
			if (!b || !*b)
				pb(a, b);
			else if (*b && (*a)->value > (*b)->value)
			{
				pb(a, b);
				rb(b);
			}
			else if (*b)
			{
				rrb(b);
				pb(a, b);
				rb(b);
			}
			else
				pb(a, b);
		}
	}
	while(*b)
	{
		pa(a,b);
	}
}
