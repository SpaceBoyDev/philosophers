/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_status.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dario <dario@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 21:29:22 by dario             #+#    #+#             */
/*   Updated: 2025/05/30 01:41:57 by dario            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	print_status(t_philo *philo, char *msg_status)
{
	size_t	time;

	if (!sim_continues(philo->table))
		return ;
	time = get_time() - philo->start_time;
	safe_mutex_handle(&philo->table->print_status_mtx, LOCK);
	printf("%li %i %s"BG_RST"\n", time, philo->id, msg_status);
	safe_mutex_handle(&philo->table->print_status_mtx, UNLOCK);
}
