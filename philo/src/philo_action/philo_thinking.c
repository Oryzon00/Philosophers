/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_thinking.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajung <ajung@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 20:58:12 by ajung             #+#    #+#             */
/*   Updated: 2022/05/24 18:10:54 by ajung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	calculate_time_to_live(t_philo *philo)
{
	int			time_since_last_meal;
	int			time_to_live;
	t_timeval	time_now;
	t_data		*data;

	data = _data();
	gettimeofday(&time_now, NULL);
	time_since_last_meal = diff_time(time_now, philo->time_last_meal);
	time_to_live = data->time_to_die - time_since_last_meal;
	return (time_to_live);
}

int	philo_thinking(t_philo *philo)
{
	t_data	*data;
	int		time_to_live;

	if (check_if_philo_dead(philo) == DEAD)
		return (FAILURE);
	data = _data();
	time_to_live = calculate_time_to_live(philo);
	philo_printf_thinking(philo);
	if (data->time_to_eat > data->time_to_sleep
		&& data->time_to_eat - data->time_to_sleep < time_to_live)
		usleep((data->time_to_eat - data->time_to_sleep) * 1100);
	else
		usleep(1000);
	return (SUCCESS);
}
