/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dario <dario@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 18:38:42 by dario             #+#    #+#             */
/*   Updated: 2025/05/27 20:36:39 by dario            ###   ########.fr       */
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

# define BG_RST    "\033[0m"
# define BG_RED    "\033[41m"
# define BG_GREEN  "\033[42m"
# define BG_YELLOW "\033[43m"
# define BG_BLUE   "\033[44m"
# define BG_MAGENTA "\033[45m"
# define BG_CYAN   "\033[46m"
# define BG_WHITE  "\033[47m"

# define PHILO_MAX 200

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

typedef enum e_mtxop
{
	INIT,
	LOCK,
	UNLOCK,
	DESTROY
}			t_mtxop;

typedef enum e_threadop
{
	CREATE,
	JOIN,
	DETACH
}			t_threadop;

typedef struct s_fork
{
	t_mtx	fork;
	int		fork_id;
}				t_fork;

typedef struct s_philo
{
	int			id;
	long		meals_counter;
	bool		dead;
	long		start_time;
	long		last_meal_time;
	t_fork		*l_fork;
	t_fork		*r_fork;
	pthread_t	thread_id;
	t_table		*table;
}				t_philo;

typedef struct s_table
{
	long	philo_num;
	long	time_to_die;
	long	time_to_eat;
	long	time_to_sleep;
	long	meals_num;
	long	sim_start;
	t_mtx	sim_start_mtx;
	bool	end_sim;
	t_mtx	end_sim_mtx;
	int		satisfied;
	t_mtx	satisfied_mtx;
	t_mtx	print_status_mtx;
	t_mtx	last_meal_mtx;
	t_fork	*forks;
	t_philo	*philos;
}				t_table;

// Initialization
void	check_args(char **args);
void	init_table(char **args, t_table *table,
			t_philo *philos, t_fork *forks);
void	init_data(t_table *table);
void	create_threads(t_table *table);

// Philo Routines
void	*philo_routine(void *param);

// Safe Handlers
void	safe_mutex_handle(t_mtx *mutex, t_mtxop opcode);
void	safe_thread_handle(pthread_t *thread, void *(func)(void *),
			void *data, t_threadop opcode);

// Safe Functions
void	*safe_malloc(size_t bytes);
void	safe_usleep(t_philo *philo, size_t time_to_usleep);

// Utils
long	ft_atol(const char *str);
long	get_time(void);

// Monitor Utils
bool	anyone_died(t_table *table);
bool	sim_continues(t_table *table);

// Print Status
void	print_status(t_philo *philo, t_philo_status status);

// Free Variables
void	join_threads(t_table *table);

// Handle Errors
void	error_exit(const char *error_message);

// DEBUG
void	print_table(t_table *table);
void	print_philos(t_table *table);
void	print_forks(t_table *table);
void	print_result(t_table *table);

#endif