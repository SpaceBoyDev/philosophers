/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dario <dario@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 19:38:23 by dario             #+#    #+#             */
/*   Updated: 2025/05/27 20:36:12 by dario            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	end_sim(t_table *table)
{
	safe_mutex_handle(&table->end_sim_mtx, LOCK);
	table->end_sim = true;
	safe_mutex_handle(&table->end_sim_mtx, UNLOCK);
}

bool	anyone_died(t_table *table)
{
	int		i;
	t_philo	*philo;

	philo = table->philos;
	while (1)
	{
		i = -1;
		while (++i < table->philo_num)
		{
			safe_mutex_handle(&table->last_meal_mtx, LOCK);
			if ((get_time() - philo[i].last_meal_time) > table->time_to_die)
			{
				print_status(&philo[i], DEAD);
				end_sim(&table);
				return (true);
			}
			safe_mutex_handle(&table->last_meal_mtx, UNLOCK);
			if (table->satisfied == table->philo_num)
				return (false);
		}
	}
	return (false);
}

bool	sim_continues(t_table *table)
{
	bool	ret;
	safe_mutex_handle(&table->end_sim_mtx, LOCK);
	ret = table->end_sim;
	safe_mutex_handle(&table->end_sim_mtx, UNLOCK);
	return (!ret);
}
