/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hladeiro <hladeiro@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 11:51:08 by hladeiro          #+#    #+#             */
/*   Updated: 2024/09/11 11:55:35 by hladeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void sa(t_stack **stack)
{
	int tmp;

	if (!*stack || !(*stack)->next)
		return ;
	tmp = (*stack)->value;
	(*stack)->value = (*stack)->next->value;
	(*stack)->next->value = tmp;
}

void sb(t_stack **stack)
{
	int tmp;

	if (!*stack || !(*stack)->next)
		return ;
	tmp = (*stack)->value;
	(*stack)->value = (*stack)->next->value;
	(*stack)->next->value = tmp;
}

void ss(t_stack **stack, t_stack **stack2)
{
	sa(stack);
	sb(stack2);
}

void pa(t_stack **stack, t_stack **stack2)
{
	t_stack *tmp;

	if (!*stack2)
		return ;
	tmp = *stack2;
	*stack2 = (*stack2)->next;
	tmp->next = *stack;
	*stack = tmp;
}

void pb(t_stack **stack, t_stack **stack2)
{
	t_stack *tmp;

	if (!*stack)
		return ;
	tmp = *stack;
	*stack = (*stack)->next;
	tmp->next = *stack2;
	*stack2 = tmp;
}
