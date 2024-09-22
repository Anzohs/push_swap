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

#include "push_swap.h"

static void	helper(t_stack **a, t_stack **b)
{
	if ((*b)->value > (*a)->next->value && \
		(*b)->value < (*a)->next->next->value)
	{
		ra(a);
		ra(a);
		pa(a, b);
		rra(a);
		rra(a);
	}
	else
	{
		rra(a);
		rra(a);
		pa(a, b);
		ra(a);
		ra(a);
	}
}

static	void	five_sorte(t_stack **a, t_stack **b)
{
	if ((*b)->value > (*a)->value && (*b)->value < (*a)->next->value)
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
		helper(a, b);
}

void	ft_sort_five(t_stack **a, t_stack **b)
{
	pb(a, b);
	pb(a, b);
	if ((*b)->value > (*b)->next->value)
		sb(b);
	sort_stack(a, NULL, stack_len(a));
	sort_stack(a, b, stack_len(a) + 1);
	five_sorte(a, b);
}
