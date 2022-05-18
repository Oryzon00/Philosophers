/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_printf.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajung <ajung@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 18:28:35 by ajung             #+#    #+#             */
/*   Updated: 2022/05/18 18:12:34 by ajung            ###   ########.fr       */
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

int	philo_printf_sleeping(t_philo *philo)
{
	t_data	*data;
	int		timestamp;

	//time stamp = difference sec * 1000 + difference ms
	data = _data();
	pthread_mutex_lock(&(data->mutex.printf));
	timestamp = get_timestamp();
	printf("%d \tphilo %d is sleeping\n", timestamp, philo->nb);
	pthread_mutex_unlock(&(data->mutex.printf));
	return (SUCCESS);
}

int	philo_printf_eating(t_philo *philo)
{
	t_data	*data;
	int		timestamp;

	data = _data();
	pthread_mutex_lock(&(data->mutex.printf));
	timestamp = get_timestamp();
	printf("%d \tphilo %d is eating\n", timestamp, philo->nb);
	pthread_mutex_unlock(&(data->mutex.printf));
	return (SUCCESS);
}

int	philo_printf_take_fork(t_philo *philo)
{
	t_data	*data;
	int		timestamp;

	data = _data();
	pthread_mutex_lock(&(data->mutex.printf));
	timestamp = get_timestamp();
	printf("%d \tphilo %d has taken a fork\n", timestamp, philo->nb);
	pthread_mutex_unlock(&(data->mutex.printf));
	return (SUCCESS);
}

int	philo_printf_thinking(t_philo *philo)
{
	t_data	*data;
	int		timestamp;

	data = _data();
	pthread_mutex_lock(&(data->mutex.printf));
	timestamp = get_timestamp();
	printf("%d \tphilo %d is thinking\n", timestamp, philo->nb);
	pthread_mutex_unlock(&(data->mutex.printf));
	return (SUCCESS);
}

int	philo_printf_died(int philo_who_died)
{
	t_data	*data;
	int		timestamp;

	data = _data();
	//pthread_mutex_lock(&(data->mutex.printf));
	timestamp = get_timestamp();
	printf("%d \tphilo %d died\n", timestamp, philo_who_died);
	pthread_mutex_unlock(&(data->mutex.printf));
	return (SUCCESS);
}
