/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_status.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dario <dario@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 21:29:22 by dario             #+#    #+#             */
/*   Updated: 2025/05/20 21:29:43 by dario            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	print_status(t_philo *philo, t_philo_status status)
{
	long	time;

	time = get_current_time() - philo->table->sim_start;
	if (status == TAKEN)
		printf("%li %i has taken a fork\n", time, philo->id);
	else if (status == EATING)
		printf("%li %i is eating\n", time, philo->id);
	else if (status == SLEEPING)
		printf("%li %i is sleeping\n", time, philo->id);
	else if (status == THINKING)
		printf("%li %i is thiking\n", time, philo->id);
	else if (status == DEAD)
		printf("%li %i died\n", time, philo->id);
	else
		error_exit("Error when printing status");
}
