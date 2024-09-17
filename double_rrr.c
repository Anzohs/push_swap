/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   doube_rrr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hladeiro <hladeiro@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 15:21:26 by hladeiro          #+#    #+#             */
/*   Updated: 2024/09/17 15:35:34 by hladeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void 	rra_1(t_stack **stack)
{
	t_stack	*tmp;

	if (!stack || !(*stack)->next)
		return ;
	tmp = *stack;
	while (tmp->next->next)
		tmp = tmp->next;
	tmp->next->next = *stack;
	*stack = tmp->next;
	tmp->next = NULL;
}

void	rrr(t_stack **stack_a, t_stack **stack_b)
{
	rra_1(stack_a);
	rra_1(stack_b);
	ft_putstr_fd("rrr\n",1);
}
