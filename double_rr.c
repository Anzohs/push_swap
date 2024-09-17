/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   double_rr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hladeiro <hladeiro@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 15:05:45 by hladeiro          #+#    #+#             */
/*   Updated: 2024/09/17 15:35:56 by hladeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

static void ra_1(t_stack **stack)
{
	t_stack *tmp;

	if (!*stack || !(*stack)->next)
		return ;
	tmp = *stack;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = *stack;
	while ((*stack)->next != tmp)
		*stack = (*stack)->next;
	(*stack)->next = NULL;
	*stack = tmp;
}

void rr(t_stack **stack_a, t_stack **stack_b)
{
	ra_1(stack_a);
	ra_1(stack_b);
	ft_putstr_fd("rr\n", 1);
}
