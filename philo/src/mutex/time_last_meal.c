/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time_last_meal.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajung <ajung@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 18:23:30 by ajung             #+#    #+#             */
/*   Updated: 2022/05/18 21:43:35 by ajung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

unsigned long	get_status_time_last_meal(t_philo *philo)
{
	t_data				*data;
	unsigned long		ret;
	
	data = _data();
	pthread_mutex_lock(&data->mutex.time_last_meal);
	ret = philo->time_last_meal;
	pthread_mutex_unlock(&data->mutex.time_last_meal);
	return (ret);
}

int	change_status_time_last_meal(t_philo *philo)
{
	t_data		*data;
	t_timeval	time_now;

	data = _data();
	pthread_mutex_lock(&(data->mutex.time_last_meal));
	gettimeofday(&time_now, NULL);
	philo->time_last_meal = time_now.tv_sec * 1000 + time_now.tv_usec / 1000;
	pthread_mutex_unlock(&(data->mutex.time_last_meal));
	return (SUCCESS);
}
