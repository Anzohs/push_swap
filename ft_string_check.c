/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string_check.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hladeiro <hladeiro@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 22:17:54 by hladeiro          #+#    #+#             */
/*   Updated: 2024/09/21 22:17:56 by hladeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	str_len(char *s)
{
	int	len;
	int	l;

	len = 0;
	l = 0;
	if (!s || !*s)
		return (11);
	while (*s)
	{
		if (!l && !(*s >= '1' && *s <= '9'))
			s++;
		else
		{
			l++;
			s++;
			len++;
		}
	}
	return (len);
}
