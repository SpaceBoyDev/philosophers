/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dario <dario@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 00:07:14 by dario             #+#    #+#             */
/*   Updated: 2025/05/06 19:19:05 by dario            ###   ########.fr       */
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

void	print_table(t_table *table)
{
	printf("╔════════════════════════════════════╗\n");
	printf("║         Philosopher Table          ║\n");
	printf("╠═══════════════╦════════════════════╣\n");
	printf("║  Attribute    ║       Value        ║\n");
	printf("╠═══════════════╬════════════════════╣\n");
	printf("║ philo_num     ║\t%ld\t     ║\n", table->philo_num);
	printf("║ time_to_die   ║\t%ld ms\t     ║\n", table->time_to_die);
	printf("║ time_to_eat   ║\t%ld ms\t     ║\n", table->time_to_eat);
	printf("║ time_to_sleep ║\t%ld ms\t     ║\n", table->time_to_sleep);
	printf("║ meals_num     ║\t%ld\t     ║\n", table->meals_num);
	printf("╚═══════════════╩════════════════════╝\n");
}

void	print_philos(t_table *table)
{
	int	i;

	printf("╔═══════════════════════╗\n");
	printf("║   Philosophers Table  ║\n");
	printf("╠═══════╦═══════╦═══════╣\n");
	printf("║  ID   ║l_fork ║r_fork ║\n");
	printf("╠═══════╬═══════╬═══════╣\n");
	for (i = 0; i < table->philo_num; i++)
	{
		printf("║ %i\t║ %i\t║ %i\t║\n", 
			table->philos[i].id, 
			table->philos[i].l_fork->fork_id, 
			table->philos[i].r_fork->fork_id);
	}
	printf("╚═══════╩═══════╩═══════╝\n");
}

void	print_forks(t_table *table)
{
	int	i;

	printf("╔═══════════════╗\n");
	printf("║     Forks     ║\n");
	printf("╠═══════════════╣\n");
	printf("║      ID       ║\n");
	printf("╠═══════════════╣\n");
	for (i = 0; i < table->philo_num; i++)
	{
		printf("║\t%i\t║\n", table->forks[i].fork_id);
	}
	printf("╚═══════════════╝\n");
}
