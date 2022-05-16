/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_thinking.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajung <ajung@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 20:58:12 by ajung             #+#    #+#             */
/*   Updated: 2022/05/16 21:12:28 by ajung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	can_wait(int nb)
{
	t_data		*data;
	t_timeval	time_now;

	data = _data();
	pthread_mutex_lock(&(data->mutex.time_last_meal));
	gettimeofday(&time_now, NULL);
	if (time_now.tv_usec / 1000 - (data->philo[nb - 1]).time_last_meal
		> data->time_to_die / 2)
	{
		pthread_mutex_unlock(&(data->mutex.time_last_meal));
		return (TRUE);
	}
	else
	{
		pthread_mutex_unlock(&(data->mutex.time_last_meal));
		return (FALSE);
	}
}

int	philo_thinking(int philo_nb)
{
	philo_printf_thinking(philo_nb);
	while(can_wait(philo_nb) == TRUE)
		usleep(1000);
	return (SUCCESS);
}
