/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hladeiro <hladeiro@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 09:59:23 by hladeiro          #+#    #+#             */
/*   Updated: 2024/09/12 13:06:08 by hladeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "ft_printf/ft_printf.h"
# include <limits.h>

typedef struct s_stack
{
	struct s_stack		*next;
	long				value;
}				t_stack;

void	sa(t_stack **stack);
void	sb(t_stack **stack);
void	ss(t_stack **stack, t_stack **stack2);
void	pa(t_stack **stack, t_stack **stack2);
void	pb(t_stack **stack, t_stack **stack2);
void	ra(t_stack **stack);
void	rb(t_stack **stack);
void	rr(t_stack **stack, t_stack **stack2);
void	rra(t_stack **stack);
void	rrb(t_stack **stack);
void	rrr(t_stack **stack, t_stack **stack2);
void	ft_init_stack(t_stack **stack, char **s, int argc);
void	ft_stack_free(t_stack *s);
void	sort(t_stack **stack);
void	sort_stack(t_stack **a, t_stack **b, int size);
int		stack_len(t_stack **stack);
int		is_valid(t_stack **stack);

#endif
