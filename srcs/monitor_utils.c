/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dario <dario@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 19:38:23 by dario             #+#    #+#             */
/*   Updated: 2025/05/22 18:48:39 by dario            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

bool	anyone_died(t_philo *philo)
{
	size_t	i;
	//t_philo	*philo;

	i = 0;
	while ((long)i < philo->table->philo_num)
	{
		philo += i;
		if (philo->dead)
			return (true);
	}
	return (false);
}

bool	has_sim_ended(t_table *table)
{
	bool	ret;
	safe_mutex_handle(&table->sim_mtx, LOCK);
	ret = table->end_sim;
	safe_mutex_handle(&table->sim_mtx, UNLOCK);
	return (ret);
}
