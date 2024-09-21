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

#include "push_swap.h"

static void	ft_free(char **s)
{
	int	i;

	i = 0;
	while (s[i])
		free(s[i++]);
	free(s);
}

static void	same_value(char **s, int argc)
{
	int	i;
	int	j;

	if (argc == 2)
		i = -1;
	else
		i = 0;
	if (!*s || !s)
	{
		if (s && argc == 2)
			ft_free(s);
		ft_putstr_fd("Error\n", 2);
		exit(0);
	}
	while (s[++i])
	{
		j = i;
		while (s[++j])
		{
			//alterar o ft_atoi
			if (ft_atoi(s[i]) == ft_atoi(s[j]))
			{
				ft_putstr_fd("Error\n", 2);
				if (argc == 2)
					ft_free(s);
				exit(1);
			}
		}
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
	same_value(s, argc);
	while (s[i])
	{
		j = 0;
		while (s[i][j])
		{
			if (j != 0 && (s[i][j] == '-' || s[i][j] == '+'))
			{
				if (argc == 2)
					ft_free(s);
				ft_putstr_fd("Error\n", 2);
				return (0);
			}
			if (!ft_isdigit(s[i][j]) && s[i][j] != '-' && s[i][j] != '+')
			{
				if (argc == 2)
					ft_free(s);
				ft_putstr_fd("Error\n", 2);
				return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}

void	ft_stack_free(t_stack *s)
{
	t_stack	*tmp;

	tmp = s;
	while (s->next)
	{
		s = s->next;
		free(tmp);
		tmp = s;
	}
	if (s)
		free(s);
	s = NULL;
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
		ft_init_stack(&a, s, argc);
		ft_free(s);
	}
	else
	{
		if (!check_arg(argv, argc))
			return (0);
		ft_init_stack(&a, argv, argc);
	}
	return (1);
}
