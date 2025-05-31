/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dario <dario@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 18:44:46 by dario             #+#    #+#             */
/*   Updated: 2025/05/31 19:20:36 by dario            ###   ########.fr       */
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

size_t	get_time(void)
{
	struct timeval	time;

	if (gettimeofday(&time, NULL) == -1)
		error_exit("Error getting current time");
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}

void	join_threads(t_table *table)
{
	int	i;
	printf("Empezando destruccion de todo\n");
	i = 0;
	while (i < table->philo_num)
	{
		safe_thread_handle(&table->philos[i].thread_id, NULL, NULL, JOIN);
		printf("Frikiton nº %i destruido\n", i);
		// safe_mutex_handle(&table->forks[i].fork, DESTROY);
		++i;
	}
	// safe_mutex_handle(&table->end_sim_mtx, DESTROY);
	// safe_mutex_handle(&table->sim_start_mtx, DESTROY);
	// safe_mutex_handle(&table->print_status_mtx, DESTROY);
	// safe_mutex_handle(&table->last_meal_mtx, DESTROY);
	printf("Todo detruido\n");
}
