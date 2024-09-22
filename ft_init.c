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

#include "push_swap.h"

static int	split_len(char **s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

void	ft_init_stack(t_stack **stack, char **s, int argv)
{
	int	i;

	if (argv == 2)
		i = 0;
	else
		i = 1;
	while (s[i])
		add_node(stack, (int)ft_atol(s[i++]));
	if (argv > 2)
	{
		if (stack_len(stack) != argv - 1)
		{
			ft_putstr_fd("Error\n", 2);
			ft_stack_free(*stack);
			return ;
		}
	}
	else
	{
		if (stack_len(stack) != split_len(s))
		{
			ft_stack_free(*stack);
			ft_putstr_fd("Error\n", 2);
			return ;
		}
	}
	sort(stack);
}
