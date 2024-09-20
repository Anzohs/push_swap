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

static void	same_value(char **s)
{
	int	i;
	int	j;

	i = 0;
	while (s[i])
	{
		j = i + 1;
		while (s[j])
		{
			if (ft_atoi(s[i]) == ft_atoi(s[j]))
			{
				ft_putstr_fd("Error\n", 2);
				ft_free(s);
				exit(1);
			}
			j++;
		}
		i++;
	}
}

static int	check_arg(char **s, int argc)
{
	int	i;
	int	j;

	if (argc == 2)
		i = 0;
	else
		i = 1;
	same_value(s);
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
	if (argc < 2)
		return (0);
	if (argc == 2)
	{
		s = ft_split(argv[1], ' ');
		if (!check_arg(s, argc))
			return (0);
		ft_init_stack(&a, s);
		ft_free(s);
		if (!is_valid(&a))
			ft_stack_free(a);
		return (0);
	}
	else
	{
		if (!check_arg(argv, argc))
			return (0);
	}
	return (1);
}
