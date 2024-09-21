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

static void	case_one(t_stack **a, t_stack *tmp)
{}

void	ft_sort_four(t_stack **a)
{
	t_stack	*tmp;

	tmp = (*a)->next;
	if ((*a)->value > (*a)->next->value)
		sa(a);
}
