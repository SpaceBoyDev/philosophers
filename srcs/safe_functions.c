/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   safe_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dario <dario@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 21:31:09 by dario             #+#    #+#             */
/*   Updated: 2025/05/29 16:25:14 by dario            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	*safe_malloc(size_t bytes)
{
	void	*result;

	result = malloc(sizeof(void) * bytes);
	if (!result)
		error_exit("Error in malloc");
	return (result);
}

void	safe_usleep(t_philo *philo, size_t time_to_usleep)
{
	size_t	wake_up;

	wake_up = get_time() + time_to_usleep;
	//printf("time to sleep de %i es %zu\n", philo->id, time_to_usleep);
	while (get_time() < wake_up)
	{
		if (!sim_continues(philo->table))
			break ;
		usleep(500);
	}
	//printf("usleep de %i ha terminado\n", philo->id);
}