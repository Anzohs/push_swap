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

static int	smallest_num(t_stack **a)
{
	t_stack *tmp = *a;
    int smallest = tmp->value;
    int pos = 0;
    int count = 0;

    while (tmp)
    {
        if (tmp->value < smallest)
        {
            smallest = tmp->value;
            pos = count;
        }
        tmp = tmp->next;
        count++;
    }
    return pos;
}

void	ft_big_sort(t_stack **a, t_stack **b)
{
	int pos;

    while (*a)
    {
        pos = smallest_num(a);
        if (pos <= stack_len(a) / 2)
        {
            while (pos > 0)
            {
                ra(a);
                pos--;
            }
        }
        else
        {
            while (pos < stack_len(a))
            {
                rra(a);
                pos++;
            }
        }
        pb(a, b);
    }

    while (*b)
    {
        pa(a, b);
    }
}
