/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajung <ajung@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 19:03:46 by ajung             #+#    #+#             */
/*   Updated: 2022/05/16 21:01:19 by ajung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>



int	init_time_last_meal(void)
{
	t_timeval	time_now;
	t_philo		*philo;
	int			i;
	t_data		*data;

	i = 0;
	data = _data();
	while (i < data->nb_philo)
	{
		philo = _philo(i);
		gettimeofday(&time_now, NULL);
		philo->time_last_meal = time_now.tv_usec / 1000;
		i++;
	}
	return (SUCCESS);
}

int	init_start_time(void)
{
	t_timeval		time_now;
	t_data			*data;

	data = _data();
	gettimeofday(&time_now, NULL);
	data->time.start_sec = time_now.tv_sec;
	data->time.start_ms = time_now.tv_usec / 1000;
	init_time_last_meal();
	return (SUCCESS);
}

int	get_timestamp(void)
{
	int			timestamp;
	t_timeval	time;
	t_data		*data;

	data = _data();
	gettimeofday(&time, NULL);
	timestamp = (time.tv_sec - data->time.start_sec) * 1000
				 + (time.tv_usec / 1000 - data->time.start_ms);

	return (timestamp);
}
