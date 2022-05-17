/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_eating.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajung <ajung@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 21:00:40 by ajung             #+#    #+#             */
/*   Updated: 2022/05/17 19:48:18 by ajung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"


static int	update_time_last_meal(t_philo *philo)
{
	t_data		*data;
	t_timeval	time_now;

	data = _data();
	pthread_mutex_lock(&(data->mutex.time_last_meal));
	gettimeofday(&time_now, NULL);
	philo->time_last_meal = time_now.tv_usec / 1000;
	pthread_mutex_unlock(&(data->mutex.time_last_meal));
	return (SUCCESS);
}

int	philo_eating(t_philo *philo)
{
	t_data		*data;

	data = _data();
	philo_printf_eating(philo);
	update_time_last_meal(philo);
	philo->have_eaten++;
	usleep(data->time_to_eat);
	return (SUCCESS);
}
