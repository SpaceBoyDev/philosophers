/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dario <dario@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 00:07:14 by dario             #+#    #+#             */
/*   Updated: 2025/05/04 00:29:34 by dario            ###   ########.fr       */
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