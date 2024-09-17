/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   double_ss.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hladeiro <hladeiro@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 15:11:42 by hladeiro          #+#    #+#             */
/*   Updated: 2024/09/17 15:36:20 by hladeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sa_1(t_stack **stack)
{
	t_stack	*tmp;

	if (!stack || !(*stack)->next)
		return ;
	tmp = *stack;
	*stack = (*stack)->next;
	tmp->next = (*stack)->next;
	(*stack)->next = tmp;
}

void	ss(t_stack **stack_a, t_stack **stack_b)
{
	sa_1(stack_a);
	sa_1(stack_b);
	ft_putstr_fd("ss\n", 1);
}
