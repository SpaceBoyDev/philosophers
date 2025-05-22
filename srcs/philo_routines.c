/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_routines.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dario <dario@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 20:30:48 by dario             #+#    #+#             */
/*   Updated: 2025/05/22 19:16:50 by dario            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

// void	*philo_routine(void *param)
// {
// 	t_philo	*philo;

// 	philo = (t_philo *)param;
// 	safe_mutex_handle(&philo->table->meal_mtx, LOCK);
// 	philo->last_meal_time = philo->table->sim_start;
// 	safe_mutex_handle(&philo->table->meal_mtx, UNLOCK);
// 	if (philo->table->philo_num == 1)
// 		return (single_philo_routine(philo)); //TODO: Implement func
// 	if (philo->id % 2 != 0)
// 		usleep(100);
// 	while (simulation_continues(philo)) //TODO: Implement func
// 	{
// 		eat_routine(philo); //TODO: Implement func
// 		if (philo->table->meals_num > 0
// 			&& philo->meals_counter >= philo->table->meals_num)
// 		{
			
// 		}
// 	}
// }

void	*philo_routine(void *param)
{
	t_philo	*philo;

	printf("wakala\n");
	philo = (t_philo *)param;
	philo->start_time = get_current_time();
	//safe_usleep(philo, 5000000000);
	return (NULL);
}