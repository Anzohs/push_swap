/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hladeiro <hladeiro@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 21:49:54 by hladeiro          #+#    #+#             */
/*   Updated: 2024/09/21 21:50:59 by hladeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long	ft_atol(char *npt)
{
	int		i;
	long	pos;
	long	result;

	pos = 1;
	i = 0;
	result = 0;
	while ((npt[i] >= 9 && npt [i] <= 13) || npt[i] == ' ')
		i++;
	if (npt[i] == '-' || npt[i] == '+')
	{
		if (npt[i] == '-')
			pos *= -1;
		i++;
	}
	while (ft_isdigit(npt[i]))
	{
		result = (result * 10) + (npt[i] - '0');
		i++;
	}
	return (result * pos);
}
