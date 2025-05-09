/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dario <dario@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 18:38:42 by dario             #+#    #+#             */
/*   Updated: 2025/05/09 14:21:57 by dario            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdbool.h>
# include <limits.h>

# include <pthread.h>
# include <sys/time.h>
# include <errno.h>

# define RST	"\033[0m"
# define RED	"\033[1;31m"
# define BLUE	"\033[1;34m"
# define GREEN	"\033[1;32m"
# define YELLOW	"\033[1;33m"

typedef pthread_mutex_t	t_mtx;
typedef struct s_table	t_table;

typedef enum e_philo_status
{
	TAKEN,
	EATING,
	SLEEPING,
	THINKING,
	DEAD
}			t_philo_status;

typedef enum e_opcode
{
	LOCK,
	UNLOCK,
	INIT,
	DESTROY,
	CREATE,
	JOIN,
	DETACH
}			t_opcode;

typedef struct s_fork
{
	t_mtx	fork;
	int		fork_id;
}				t_fork;

typedef struct s_philo
{
	int			id;
	long		meals_counter;
	bool		full;
	long		last_meal_time;
	t_fork		*l_fork;
	t_fork		*r_fork;
	pthread_t	thread_id;
	t_table		*table;
}				t_philo;

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
typedef struct s_table
{
	long	philo_num;
	long	time_to_die;
	long	time_to_eat;
	long	time_to_sleep;
	long	meals_num;
	long	sim_start;
	bool	end_sim;
	t_fork	*forks;
	t_philo	*philos;
}				t_table;

// Initialization
void	check_args(char **args);
void	init_table(char **args, t_table *table);
void	init_data(t_table *table);

// Handle Mutex
void	safe_mutex_handle(t_mtx *mutex, t_opcode opcode);

// Handle Threads
void	safe_thread_handle(pthread_t *thread, void *(func)(void *),
			void *data, t_opcode opcode);

// Utils
long	ft_atol(const char *str);
void	*ft_malloc(size_t bytes);
long	get_current_time(void);
void	print_status(t_philo *philo, t_philo_status status);

// Handle Errors
void	error_exit(const char *error_message);

// DEBUG
void	print_table(t_table *table);
void	print_philos(t_table *table);
void	print_forks(t_table *table);

#endif