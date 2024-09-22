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

static int	radix(t_stack **a)
{
	int		value;
	int		bits;
	t_stack	*tmp;

	value = (*a)->value;
	bits = 0;
	tmp = *a;
	while (tmp)
	{
		if (tmp->value > value)
			value = tmp->value;
		tmp = tmp->next;
	}
	while ((value >> bits) != 0)
		bits++;
	return (bits);
}

void	ft_big_sort(t_stack **a, t_stack **b)
{
	int bits;
	int i;
	int j;
	int stack_size;

	i = 0;
	j = 0;
	bits = radix(a);
	stack_size = stack_len(a);
    while (i < bits)
    {
    	while (j < stack_size)
     	{
			if (((*a)->value >> i) & 1)
				ra(a);
			else
				pb(a, b);
			j++;
		}
		i++;
    }
    while (*b)
    {
        pa(a, b);
    }
}
