/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_action.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajung <ajung@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 17:12:38 by ajung             #+#    #+#             */
/*   Updated: 2022/05/13 19:27:43 by ajung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/* 
◦ timestamp_in_ms X has taken a fork
◦ timestamp_in_ms X is eating
◦ timestamp_in_ms X is sleeping
◦ timestamp_in_ms X is thinking
◦ timestamp_in_ms X died 
*/

int	philo_sleeping(int philo_nb)
{
	t_data	*data;
	int		timestamp;

	//time stamp = difference sec * 1000 + difference ms
	data = _data();
	pthread_mutex_lock(&(data->mutex.printf));
	timestamp = data->
	printf("%d philo %d is sleeping\n", timestamp, philo_nb);
	pthread_mutex_unlock(&(data->mutex.printf));
	return (SUCCESS);
}

int	philo_eating(int philo_nb)
{
	t_data	*data;
	int		timestamp;

	data = _data();
	pthread_mutex_lock(&(data->mutex.printf));
	timestamp = 
	printf("%d philo %d is eating\n", timestamp, philo_nb);
	pthread_mutex_unlock(&(data->mutex.printf));
	return (SUCCESS);
}

int	philo_take_fork(int philo_nb)
{
	t_data	*data;
	int		timestamp;

	data = _data();
	pthread_mutex_lock(&(data->mutex.printf));
	timestamp = 
	printf("%d philo %d has taken a fork\n", timestamp, philo_nb);
	pthread_mutex_unlock(&(data->mutex.printf));
	return (SUCCESS);
}

int	philo_thinking(int philo_nb)
{
	t_data	*data;
	int		timestamp;

	data = _data();
	pthread_mutex_lock(&(data->mutex.printf));
	timestamp =
	printf("%d philo %d is thinking\n", timestamp, philo_nb);
	pthread_mutex_unlock(&(data->mutex.printf));
	return (SUCCESS);
}

int	philo_died(int philo_nb)
{
	t_data	*data;
	int		timestamp;

	data = _data();
	pthread_mutex_lock(&(data->mutex.printf));
	timestamp = 
	printf("%d philo %d died\n", timestamp, philo_nb);
	pthread_mutex_unlock(&(data->mutex.printf));
	return (SUCCESS);
}
