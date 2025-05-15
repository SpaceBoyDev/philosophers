/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dario <dario@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 18:44:46 by dario             #+#    #+#             */
/*   Updated: 2025/05/12 18:53:02 by dario            ###   ########.fr       */
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

void	*ft_malloc(size_t bytes)
{
	void	*result;

	result = malloc(sizeof(void) * bytes);
	if (!result)
		error_exit("Error in malloc");
	return (result);
}

long	get_current_time(void)
{
	struct timeval	time;

	if (gettimeofday(&time, NULL) == -1)
		error_exit("Error getting current time");
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}

void	print_status(t_philo *philo, t_philo_status status)
{
	long	time;

	time = get_current_time() - philo->table->sim_start;
	if (status == TAKEN)
		printf("%li %i has taken a fork\n", time, philo->id);
	else if (status == EATING)
		printf("%li %i is eating\n", time, philo->id);
	else if (status == SLEEPING)
		printf("%li %i is sleeping\n", time, philo->id);
	else if (status == THINKING)
		printf("%li %i is thiking\n", time, philo->id);
	else if (status == DEAD)
		printf("%li %i died\n", time, philo->id);
	else
		error_exit("Error when printing status");
}
