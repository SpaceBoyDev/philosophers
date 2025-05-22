/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   safe_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dario <dario@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 21:31:09 by dario             #+#    #+#             */
/*   Updated: 2025/05/22 18:48:34 by dario            ###   ########.fr       */
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
	int	wake_up;

	wake_up = get_current_time() + time_to_usleep;
	while (get_current_time() < wake_up)
	{
		if (has_sim_ended(philo->table))
			break ;
		usleep(50);
	}
}