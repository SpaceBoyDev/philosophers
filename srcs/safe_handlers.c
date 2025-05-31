/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   safe_handlers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dario <dario@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 21:29:57 by dario             #+#    #+#             */
/*   Updated: 2025/05/31 19:35:26 by dario            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static void	handle_mutex_error(int status, t_mtxop opcode)
{
	if (status == 0)
		return ;
	if (status == EINVAL && (opcode == LOCK || opcode == UNLOCK))
		error_exit("The value specified by mutex is invalid");
	else if (status == EINVAL && opcode == INIT)
		error_exit("The value specified by attr is invalid");
	else if (status == EDEADLK)
		error_exit("A deadlock would occur if the thread blocked "
			"waiting for mutex");
	else if (status == EPERM)
		error_exit("The current thread does not hold a lock on mutex");
	else if (status == ENOMEM)
		error_exit("The process cannot allocate enough memory "
			"to create another mutex");
	else if (status == EBUSY)
		error_exit("Mutex is locked");
}

void	safe_mutex_handle(t_mtx *mutex, t_mtxop opcode)
{
	if (opcode == LOCK)
		handle_mutex_error(pthread_mutex_lock(mutex), opcode);
	else if (opcode == UNLOCK)
		handle_mutex_error(pthread_mutex_unlock(mutex), opcode);
	else if (opcode == INIT)
		handle_mutex_error(pthread_mutex_init(mutex, NULL), opcode);
	else if (opcode == DESTROY)
		handle_mutex_error(pthread_mutex_destroy(mutex), opcode);
	else
		error_exit("Bad opcode for mutex");
}

static void	handle_thread_error(int status, t_threadop opcode)
{
	if (status == 0)
		return ;
	if (status == EAGAIN)
		error_exit("No resources to create another thread");
	else if (status == EPERM)
		error_exit("The caller does not have appropiate permission");
	else if (status == EINVAL && opcode == CREATE)
		error_exit("The value specified by attr is invalid");
	else if (status == EINVAL && (opcode == JOIN || opcode == DETACH))
		error_exit("The value specified by thread is not joinable");
	else if (status == ESRCH)
		error_exit("No thread could be found corresponding to that ID");
	else if (status == EDEADLK)
		error_exit("A deadlock was detected or"
			" the value of thread specifies the calling thread");
}

void	safe_thread_handle(pthread_t *thread, void *(func)(void *),
		void *data, t_threadop opcode)
{
	if (opcode == CREATE)
		handle_thread_error(pthread_create(thread, NULL, func, data), opcode);
	else if (opcode == JOIN)
		handle_thread_error(pthread_join(*thread, NULL), opcode);
	else if (opcode == DETACH)
		handle_thread_error(pthread_detach(*thread), opcode);
	else
		error_exit("Bad opcode for thread");
}

void	safe_usleep(t_philo *philo, size_t time_to_usleep)
{
	size_t	wake_up;

	wake_up = get_time() + time_to_usleep;
	while (get_time() < wake_up)
	{
		if (!sim_continues(philo->table))
			break ;
		usleep(500);
	}
}
