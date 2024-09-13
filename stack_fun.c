/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_fun.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hladeiro <hladeiro@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 10:48:16 by hladeiro          #+#    #+#             */
/*   Updated: 2024/09/13 12:25:37 by hladeiro         ###   ########.fr       */
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
	write(1, "ra\n", 3);
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
	write(1, "rb\n", 3);
}

void rr(t_stack **stack, t_stack **stack2)
{
	ra(stack);
	rb(stack2);
	write(1, "rr\n", 3);
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
	write(1, "rra\n", 4);
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
	write(1, "rrb\n", 4);
}

void rrr(t_stack **stack, t_stack **stack2)
{
	rra(stack);
	rrb(stack2);
	write(1, "rrr\n", 4);
}
