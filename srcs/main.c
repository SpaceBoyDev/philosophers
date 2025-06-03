/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dario <dario@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 18:30:05 by dario             #+#    #+#             */
/*   Updated: 2025/06/03 13:49:59 by dario            ###   ########.fr       */
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

int	main(int argc, char **argv)
{
	t_table	table;
	t_philo	philos[PHILO_MAX];
	t_fork	forks[PHILO_MAX];

	if (argc != 5 && argc != 6)
		error_exit("Execute like this:\n"
			"./philo <philo_num> <time_to_die> <time_to_eat>"
			" <time_to_sleep> <[meals_num]>");
	check_args(argv);
	init_table(argv, &table, philos, forks);
	init_data(&table);
	if (!create_threads(&table))
		return (1);
	usleep(1000);
	join_threads(&table);
	return (0);
}
