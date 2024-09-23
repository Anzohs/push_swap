/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_four.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hladeiro <hladeiro@student.42lisboa.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 17:25:49 by hladeiro          #+#    #+#             */
/*   Updated: 2024/09/21 17:25:51 by hladeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf/ft_printf.h"
#include "push_swap.h"

static int	helper(t_stack **a)
{
	t_stack	*tmp;
	int		i;

	tmp = *a;
	i = tmp->value;
	while (tmp)
	{
		if (tmp->value < i)
			i = tmp->value;
		tmp = tmp->next;
	}
	return (i);
}

static int	five_sorte(t_stack **a, int num)
{
	t_stack	*t;
	int		i;

	t = *a;
	i = 1;
	while (t->value != num && t)
	{
		t = t->next;
		i++;
	}
	return (i);
}

void	ft_sort_five(t_stack **a, t_stack **b)
{
	while (stack_len(a) >= 4)
	{
		if (five_sorte(a, helper(a)) == 1)
			pb(a, b);
		else if (five_sorte(a, helper(a)) > 3)
		{
			while (five_sorte(a, helper(a)) != 1)
			{
				rra(a);
			}
		}
		else
		{
			while (five_sorte(a, helper(a)) != 1)
				ra(a);
		}
	}
	if (!is_sorted(a))
		sort_stack(a, NULL, 3);
	pa(a, b);
	pa(a, b);
}

void	ft_index(t_stack **a)
{
	t_stack	*tmp;
	int		i;
	int		len;

	tmp = *a;
	len = stack_len(a);
	i = 1;
	while (len)
	{
		while (tmp)
		{
			if (tmp->value == min_num(a))
				tmp->index = i++;
			tmp = tmp->next;
		}
		len--;
		tmp = *a;
	}
}
