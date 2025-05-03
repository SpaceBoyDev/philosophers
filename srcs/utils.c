/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dario <dario@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 18:44:46 by dario             #+#    #+#             */
/*   Updated: 2025/05/03 23:46:47 by dario            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (2048);
	return (0);
}

long	ft_atol(const char *str)
{
	long	num;
	int		negative;

	num = 0;
	negative = 1;
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		++str;
	if (*str == '-')
	{
		if (!ft_isdigit(*(str + 1)))
			return (0);
		negative = -1;
		++str;
	}
	if (*str == '+' && ft_isdigit(*(str + 1)))
		++str;
	else if (*str == '+' && !ft_isdigit(*(str + 1)))
		return (0);
	while (ft_isdigit(*str))
	{
		num = (num * 10) + ((int)*str - '0');
		++str;
	}
	return (num * negative);
}