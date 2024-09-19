/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hladeiro <hladeiro@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 09:58:13 by hladeiro          #+#    #+#             */
/*   Updated: 2024/09/17 14:26:57 by hladeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf/ft_printf.h"
#include "push_swap.h"

static void	ft_free(char **s)
{
	int	i;

	i = 0;
	while (s[i])
		free(s[i++]);
	free(s);
}

static void	ft_stack_free(t_stack *s)
{
	t_stack	*tmp;

	tmp = s;
	while (s->next)
	{
		s = s->next;
		free(tmp);
		tmp = s;
	}
	free(s);
}

static int	check_arg(char **s, int argc)
{
	int	i;
	int	j;

	if (argc == 2)
		i = 0;
	else
		i = 1;
	while (s[i])
	{
		j = 0;
		while (s[i][j])
		{
			if (!ft_isdigit(s[i][j]) && s[i][j] != '-')
			{
				ft_putstr_fd("Error\n", 2);
				return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}

int	main(int argc, char **argv)
{
	char	**s;
	t_stack	*a;

	a = NULL;
	ft_bzero(a, sizeof(t_stack));
	if (argc < 2)
		return (0);
	if (argc == 2)
	{
		s = ft_split(argv[1], ' ');
		if (!check_arg(s, argc))
			return (0);
		ft_init_stack(&a, s);
		ft_free(s);
		ft_stack_free(a);
	}
	else
	{
		if (!check_arg(argv, argc))
			return (0);
	}
	return (1);
}
