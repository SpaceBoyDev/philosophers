/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_status.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dario <dario@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 21:29:22 by dario             #+#    #+#             */
/*   Updated: 2025/05/27 20:26:13 by dario            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	print_status(t_philo *philo, t_philo_status status)
{
	long	time;

	time = get_time() - philo->start_time;
	safe_mutex_handle(&philo->table->print_status_mtx, LOCK);
	if (status == TAKEN)
		printf(BG_BLUE"%li %i has taken a fork"BG_RST"\n", time, philo->id);
	else if (status == EATING)
		printf(BG_GREEN"%li %i is eating"BG_RST"\n", time, philo->id);
	else if (status == SLEEPING)
		printf(BG_MAGENTA"%li %i is sleeping"BG_RST"\n", time, philo->id);
	else if (status == THINKING)
		printf(BG_CYAN"%li %i is thinking"BG_RST"\n", time, philo->id);
	else if (status == DEAD)
		printf(BG_RED"%li %i died"BG_RST"\n", time, philo->id);
	else
		error_exit("Error when printing status\n");
	safe_mutex_handle(&philo->table->print_status_mtx, UNLOCK);
}
