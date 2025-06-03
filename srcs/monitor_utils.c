/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dario <dario@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 19:38:23 by dario             #+#    #+#             */
/*   Updated: 2025/06/03 13:55:44 by dario            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static void	end_sim(t_table *table)
{
	safe_mutex_handle(&table->end_sim_mtx, LOCK);
	table->end_sim = true;
	safe_mutex_handle(&table->end_sim_mtx, UNLOCK);
}

static bool	all_philos_ready(t_table *table)
{
	int	ret;
	safe_mutex_handle(&table->philos_ready_mtx, LOCK);
	ret = table->philos_ready;
	safe_mutex_handle(&table->philos_ready_mtx, UNLOCK);
	return (ret == table->philo_num);
}

bool	anyone_died(t_table *table)
{
	int		i;

	while (!all_philos_ready(table))
		usleep(50);
	// safe_mutex_handle(&table->philos_ready_mtx, LOCK);
	// if (table->philos_ready != table->philo_num)
	// {
	// 	safe_mutex_handle(&table->philos_ready_mtx, UNLOCK);
	// 	return (anyone_died(table));
	// }
	// safe_mutex_handle(&table->philos_ready_mtx, UNLOCK);
	while (1)
	{
		i = -1;
		while (++i < table->philo_num)
		{
			safe_mutex_handle(&table->last_meal_mtx, LOCK);
			if ((get_time() - table->philos[i].last_meal_time)
				> table->time_to_die)
			{
				//safe_mutex_handle(&table->print_status_mtx, LOCK);
				print_status(&table->philos[i], MSG_DIED, BG_RED);
				end_sim(table);
				//safe_mutex_handle(&table->print_status_mtx, UNLOCK);
				safe_mutex_handle(&table->last_meal_mtx, UNLOCK);
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

void	print_status(t_philo *philo, char *msg_status, char *bg_color)
{
	size_t	time;

	time = get_time() - philo->start_time;
	safe_mutex_handle(&philo->table->print_status_mtx, LOCK);
	if (!sim_continues(philo->table))
	{
		safe_mutex_handle(&philo->table->print_status_mtx, UNLOCK);
		return ;
	}
	printf("%s%li %i %s"BG_RST"\n", bg_color, time, philo->id, msg_status);
	safe_mutex_handle(&philo->table->print_status_mtx, UNLOCK);
}
