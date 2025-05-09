/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialization.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dario <dario@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 21:29:22 by dario             #+#    #+#             */
/*   Updated: 2025/05/09 14:26:49 by dario            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

/* ./philo 10 			15			 10				20			30
* philo_num^ time_to_die^ time_to_eat^ time_to_sleep^ meals_num^
* philo_num: número de philos
* time_to_die (ms): tiempo que debe pasar entre la última comida y que el
* 				philo vuelva a empezar a comer para que muera
* time_to_eat (ms): tiempo que tiene un philo para comer. Tendrá los forks
*				ocupados durante este tiempo
* time_to_sleep (ms): tiempo que tiene un philo para dormir
* meals_num (opcional): cantidad de comidas que deben tener todos los philos
*				para que la simulación termine. Si no se especifia, la
*				simulación terminará con la muerte de un philo
*/

void	check_args(char **args)
{
	int	i;
	int	atol;

	i = 1;
	while (args[i])
	{
		atol = ft_atol(args[i]);
		if (atol > INT_MAX || atol < INT_MIN)
			error_exit("Argument is outside int limits!");
		if (atol < 1 && i == 1)
			error_exit("Numbers of philos must be 1 or more");
		if (atol < 0)
			error_exit("Arguments cannot be below 0");
		++i;
	}
}

void	init_table(char **args, t_table *table)
{
	table->sim_start = get_current_time();
	table->end_sim = false;
	table->philo_num = ft_atol(args[1]);
	table->time_to_die = ft_atol(args[2]);
	table->time_to_eat = ft_atol(args[3]);
	table->time_to_sleep = ft_atol(args[4]);
	if (args[5])
		table->meals_num = ft_atol(args[5]);
	else
		table->meals_num = -1;
}

void	init_data(t_table *table)
{
	t_philo	*philo;
	int		i;

	philo = table->philos;
	i = -1;
	table->forks = ft_malloc(sizeof(t_fork) * table->philo_num);
	while (++i < table->philo_num)
	{
		table->forks[i].fork_id = i;
		safe_mutex_handle(&(table->forks[i].fork), INIT);
	}
	philo = ft_malloc(sizeof(t_philo) * table->philo_num);
	i = -1;
	while (++i < table->philo_num)
	{
		philo = table->philos + i;
		philo->id = i + 1;
		philo->full = false;
		philo->meals_counter = 0;
		philo->table = table;
		philo->r_fork = &table->forks[i];
		philo->l_fork = &table->forks[(i + 1) % table->philo_num];
	}
}
