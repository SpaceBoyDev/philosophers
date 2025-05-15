/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_variables.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dario <dario@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 19:58:04 by dario             #+#    #+#             */
/*   Updated: 2025/05/13 18:45:42 by dario            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	free_philos(t_table *table)
{
	t_philo	*philo;
	int	i;

	if (!table || !table->philos)
		return;
	i = -1;
	while (++i < table->philo_num)
	{
		philo = table->philos + i;
		philo->table = NULL;
		safe_thread_handle(philo->thread_id, NULL, NULL, JOIN);
		//philo->r_fork;
		safe_mutex_handle(&philo->r_fork->fork, DESTROY);
		free(philo->r_fork);
		free(philo);
		philo = NULL;
	}
	table->philos = NULL;
}

void	free_all_structs(t_table *table)
{
	free_philos(table);
}