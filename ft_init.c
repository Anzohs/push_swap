/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hladeiro <hladeiro@student.42lisboa.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 18:43:07 by hladeiro          #+#    #+#             */
/*   Updated: 2024/09/19 18:43:08 by hladeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf/ft_printf.h"
#include "ft_printf/libft/libft.h"
#include "push_swap.h"

static t_stack	*ft_last(t_stack *stack)
{
	t_stack	*tmp;

	tmp = stack;

	while(tmp->next)
		tmp = tmp->next;
	return tmp;
}

static void	add_node(t_stack **stack, int i)
{
	t_stack	*s;

	s = ft_calloc(sizeof(t_stack), 1);
	if (!s)
		return;
	s->value = i;
	s->next = NULL;
	if (!*stack)
		*stack = s;
	else
		ft_last(*stack)->next = s;

}

void	ft_init_stack(t_stack **stack, char **s)
{
	int i;

	i = 0;
	while(s[i])
		add_node(stack, ft_atoi(s[i++]));
}
