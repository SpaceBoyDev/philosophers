/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_status.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dario <dario@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 21:29:22 by dario             #+#    #+#             */
/*   Updated: 2025/05/28 21:58:14 by dario            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	print_status(t_philo *philo, char *msg_status)
{
	size_t	time;

	time = get_time() - philo->start_time;
	//printf("time -> %li\n", time);
	//printf(BG_WHITE"get_time -> %li\nsim_start -> %li\ntime -> %li"BG_RST"\n", get_time(), philo->table->sim_start, time);
	safe_mutex_handle(&philo->table->print_status_mtx, LOCK);
	printf("%li %i %s"BG_RST"\n", time, philo->id, msg_status);
	safe_mutex_handle(&philo->table->print_status_mtx, UNLOCK);
}
