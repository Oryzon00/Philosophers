/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_dead.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajung <ajung@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 19:12:22 by ajung             #+#    #+#             */
/*   Updated: 2022/05/17 21:27:33 by ajung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

//time temps actuel - time_since_last_meal >= time_to_die -->dead
static t_philo	*calcule_if_philo_dead(t_data *data)
{
	t_philo		*philo;
	t_timeval	time_now;
	int			i;

	i = 0;
	while (i < data->nb_philo)
	{
		philo = _philo(i);
		gettimeofday(&time_now, NULL);
		pthread_mutex_lock(&data->mutex.time_last_meal);
		if (time_now.tv_usec / 1000 - philo->time_last_meal
			>= data->time_to_die)
		{
			pthread_mutex_unlock(&data->mutex.time_last_meal);
			return (philo);
		}
		pthread_mutex_unlock(&data->mutex.time_last_meal);
		i++;
	}
	return (NULL);
}

static int	check_all_have_eaten(t_data *data)
{
	t_philo	*philo;
	int		i;

	i = 0;
	while (i < data->nb_philo)
	{
		philo = _philo(i);
		if (philo->finish_eating == FALSE)
			return (FALSE);
		else
			i++;
	}
	if (i == data->nb_philo - 1)
		return (TRUE);
	else
		return (FALSE);
}

static int stop_routine(t_data *data, t_philo *philo)
{
	
	pthread_mutex_lock(&data->mutex.printf);
	pthread_mutex_lock(&data->mutex.philo_is_dead);
	data->philo_is_dead = TRUE;
	pthread_mutex_unlock(&data->mutex.philo_is_dead);
	usleep(1000);
	philo_printf_died(philo);
	return (SUCCESS);
	
}

void	check_dead(void)
{
	t_data		*data;
	t_philo		*philo_dead;

	data = _data();
	while (data->philo_is_dead == FALSE)
	{
		philo_dead = calcule_if_philo_dead(data);
		if (philo_dead != NULL)
			stop_routine(data, philo_dead);
		else if (check_all_have_eaten(data) == TRUE)
			return ;
		else
			usleep(1000);
	}
}
