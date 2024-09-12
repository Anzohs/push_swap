/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_fun.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hladeiro <hladeiro@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 10:48:16 by hladeiro          #+#    #+#             */
/*   Updated: 2024/09/11 12:00:47 by hladeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void ra(t_stack **stack)
{
	t_stack *tmp;
	t_stack *tmp2;

	if (!*stack || !(*stack)->next)
		return ;
	tmp = *stack;
	tmp2 = *stack;
	while (tmp->next)
		tmp = tmp->next;
	*stack = tmp2->next;
	tmp->next = tmp2;
	tmp2->next = NULL;
}

void rb(t_stack **stack)
{
	t_stack *tmp;
	t_stack *tmp2;

	if (!*stack || !(*stack)->next)
		return ;
	tmp = *stack;
	tmp2 = *stack;
	while (tmp->next)
		tmp = tmp->next;
	*stack = tmp2->next;
	tmp->next = tmp2;
	tmp2->next = NULL;
}

void rr(t_stack **stack, t_stack **stack2)
{
	ra(stack);
	rb(stack2);
}

void rra(t_stack **stack)
{
	t_stack *tmp;
	t_stack *tmp2;

	if (!*stack || !(*stack)->next)
		return ;
	tmp = *stack;
	while (tmp->next->next)
		tmp = tmp->next;
	tmp2 = tmp->next;
	tmp->next = NULL;
	tmp2->next = *stack;
	*stack = tmp2;
}

void rrb(t_stack **stack)
{
	t_stack *tmp;
	t_stack *tmp2;

	if (!*stack || !(*stack)->next)
		return ;
	tmp = *stack;
	while (tmp->next->next)
		tmp = tmp->next;
	tmp2 = tmp->next;
	tmp->next = NULL;
	tmp2->next = *stack;
	*stack = tmp2;
}

void rrr(t_stack **stack, t_stack **stack2)
{
	rra(stack);
	rrb(stack2);
}
