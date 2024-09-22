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

#include "ft_printf/libft/libft.h"
#include "push_swap.h"

static void	str_check(char **s, int argc)
{
	int	i;

	if (!s || !*s)
	{
		if (s)
			ft_free(s);
		ft_putstr_fd("Error\n", 2);
		exit(0);
	}
	if (argc == 2)
		i = -1;
	else
		i = 0;
	while (s[++i])
	{
		if (str_len(s[i]) > 10)
		{
			if (argc == 2)
				ft_free(s);
			ft_putstr_fd("Error\n", 2);
			exit(0);
		}
	}
}

static void	same_value(char **s, int argc, int i)
{
	int	j;

	while (s[++i])
	{
		j = i;
		while (s[++j])
		{
			if (ft_atol(s[i]) == ft_atol(s[j]))
			{
				ft_putstr_fd("Error\n", 2);
				if (argc == 2)
					ft_free(s);
				exit(1);
			}
		}
		if (ft_atol(s[i]) > INT_MAX || ft_atol(s[i]) < INT_MIN)
		{
			if (argc == 2)
				ft_free(s);
			exit(0);
			ft_putstr_fd("Error\n", 2);
		}
	}
}

static void	valid_arg(char **s, int argc, int i)
{
	int	j;

	while (s[++i])
	{
		j = -1;
		while (s[i][++j])
		{
			if (j != 0 && (s[i][j] == '-' || s[i][j] == '+'))
			{
				if (argc == 2)
					ft_free(s);
				ft_putstr_fd("Error\n", 2);
				exit(0);
			}
			if (!ft_isdigit(s[i][j]) && s[i][j] != '-' && s[i][j] != '+')
			{
				if (argc == 2)
					ft_free(s);
				ft_putstr_fd("Error\n", 2);
				exit(0);
			}
		}
	}
}

static void	check_arg(char **s, int argc)
{
	int	i;

	if (argc == 2)
		i = 0;
	else
		i = 1;
	str_check(s, argc);
	same_value(s, argc, i - 1);
	valid_arg(s, argc, i - 1);
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
		if (!s)
			return (1);
		check_arg(s, argc);
		ft_init_stack(&a, s, argc);
		ft_free(s);
	}
	else
	{
		check_arg(argv, argc);
		ft_init_stack(&a, argv, argc);
	}
	return (1);
}

//ARG=$(seq -99999 99999 | shuf -n 5); valgrind ./push_swap $ARG | ./checker_linux $ARG
