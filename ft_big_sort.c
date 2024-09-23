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

#include "push_swap.h"

static int	radix(t_stack **a)
{
	int		value;
	int		bits;
	t_stack	*tmp;

	value = (*a)->index;
	bits = 0;
	tmp = *a;
	while (tmp)
	{
		if (tmp->index > value)
			value = tmp->index;
		tmp = tmp->next;
	}
	while ((value >> bits) != 0)
		bits++;
	return (bits);
}

void	ft_big_sort(t_stack **a, t_stack **b)
{
	int	bits;
	int	i;
	int	j;
	int	stack_size;

	i = 0;
	bits = radix(a);
	stack_size = stack_len(a);
	while (i < bits)
	{
		j = 0;
		while (j < stack_size)
		{
			if ((((*a)->index >> i) & 1) == 1)
				ra(a);
			else
				pb(a, b);
			j++;
		}
		while (*b)
			pa(a, b);
		i++;
	}
}
