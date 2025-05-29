/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_variables.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dario <dario@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 19:58:04 by dario             #+#    #+#             */
/*   Updated: 2025/05/29 17:17:03 by dario            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	join_threads(t_table *table)
{
	int	i;
	printf("Empezando destruccion de todo\n");
	i = -1;
	while (++i < table->philo_num)
	{
		safe_thread_handle(&table->philos[i].thread_id, NULL, NULL, JOIN);
		//safe_mutex_handle(&table->forks[i].fork, DESTROY);
	}
	// safe_mutex_handle(&table->end_sim_mtx, DESTROY);
	// safe_mutex_handle(&table->sim_start_mtx, DESTROY);
	// safe_mutex_handle(&table->print_status_mtx, DESTROY);
	// safe_mutex_handle(&table->last_meal_mtx, DESTROY);
	printf("Todo detruido\n");
}
