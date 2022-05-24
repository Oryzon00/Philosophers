/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time_last_meal.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajung <ajung@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 18:23:30 by ajung             #+#    #+#             */
/*   Updated: 2022/05/24 14:39:16 by ajung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_timeval	get_status_time_last_meal(t_philo *philo)
{
	t_data		*data;
	t_timeval	time_last_meal;

	data = _data();
	pthread_mutex_lock(&data->mutex.time_last_meal);
	time_last_meal = philo->time_last_meal;
	pthread_mutex_unlock(&data->mutex.time_last_meal);
	return (time_last_meal);
}

int	change_status_time_last_meal(t_philo *philo)
{
	t_data		*data;
	t_timeval	time_last_meal;

	data = _data();
	pthread_mutex_lock(&(data->mutex.time_last_meal));
	gettimeofday(&time_last_meal, NULL);
	philo->time_last_meal = time_last_meal;
	pthread_mutex_unlock(&(data->mutex.time_last_meal));
	return (SUCCESS);
}
