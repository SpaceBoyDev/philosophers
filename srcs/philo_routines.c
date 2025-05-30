/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_routines.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dario <dario@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 20:30:48 by dario             #+#    #+#             */
/*   Updated: 2025/05/30 19:23:18 by dario            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static void	sleep_think_routine(t_philo *philo)
{
	print_status(philo, MSG_SLEEPING);
	safe_usleep(philo, philo->table->time_to_sleep);
	print_status(philo, MSG_THINKING);
}

static void	eat_routine(t_philo *philo)
{
	if (philo->id % 2 == 0)
	{
		safe_mutex_handle(&philo->l_fork->fork, LOCK);
		print_status(philo, MSG_TAKEN_L);
		safe_mutex_handle(&philo->r_fork->fork, LOCK);
		print_status(philo, MSG_TAKEN_R);
	}
	else
	{
		safe_mutex_handle(&philo->r_fork->fork, LOCK);
		print_status(philo, MSG_TAKEN_R);
		safe_mutex_handle(&philo->l_fork->fork, LOCK);
		print_status(philo, MSG_TAKEN_L);
	}
	safe_mutex_handle(&philo->table->last_meal_mtx, LOCK);
	philo->last_meal_time = get_time();
	if (sim_continues(philo->table))
		++philo->meals_counter;
	safe_mutex_handle(&philo->table->last_meal_mtx, UNLOCK);
	print_status(philo, MSG_EATING);
	safe_usleep(philo, philo->table->time_to_eat);
	safe_mutex_handle(&philo->r_fork->fork, UNLOCK);
	safe_mutex_handle(&philo->l_fork->fork, UNLOCK);
}

static void	*lonely_philo(t_philo *philo)
{
	safe_mutex_handle(&philo->l_fork->fork, LOCK);
	print_status(philo, MSG_TAKEN_L);
	safe_usleep(philo, philo->table->time_to_die);
	print_status(philo, MSG_DIED);
	safe_mutex_handle(&philo->l_fork->fork, UNLOCK);
	return (NULL);
}

void	*philo_routine(void *param)
{
	t_philo	*philo;

	philo = (t_philo *)param;
	safe_mutex_handle(&philo->table->sim_start_mtx, LOCK);
	philo->start_time = philo->table->sim_start;
	philo->last_meal_time = philo->start_time;
	safe_mutex_handle(&philo->table->sim_start_mtx, UNLOCK);
	if (philo->id % 2 == 0)
	safe_usleep(philo, 100);
	safe_mutex_handle(&philo->table->philos_ready_mtx, LOCK);
	++philo->table->philos_ready;
	safe_mutex_handle(&philo->table->philos_ready_mtx, UNLOCK);
	if (philo->table->philo_num == 1)
		return (lonely_philo(philo));
	while (sim_continues(philo->table))
	{
		eat_routine(philo);
		if (philo->table->meals_num > 0
			&& philo->meals_counter >= philo->table->meals_num)
		{
			safe_mutex_handle(&philo->table->satisfied_mtx, LOCK);
			++philo->table->satisfied;
			safe_mutex_handle(&philo->table->satisfied_mtx, UNLOCK);
			safe_mutex_handle(&philo->l_fork->fork, UNLOCK);
			safe_mutex_handle(&philo->r_fork->fork, UNLOCK);
			return (NULL);
		}
		sleep_think_routine(philo);
	}
	return (NULL);
}
