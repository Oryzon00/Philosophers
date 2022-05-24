/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oryzon <oryzon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 19:56:23 by ajung             #+#    #+#             */
/*   Updated: 2022/05/25 00:53:37 by oryzon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	error_thread_create(void)
{
	t_data	*data;

	data = _data();
	pthread_mutex_lock(&data->mutex.printf);
	printf("-----Il faut changer de PC-------\n");
	pthread_mutex_unlock(&data->mutex.printf);
	return (SUCCESS);
}

int	init_thread(void)
{
	int		i;
	t_data	*data;
	t_philo	*philo;

	data = _data();
	i = 0;
	while (i < data->nb_philo)
	{
		philo = _philo(i);
		if (philo && philo->nb % 2 == 0)
			if (pthread_create(&(philo->id), NULL, &ft_routine, philo) > 0)
				error_thread_create();
		i++;
	}
	usleep(100);
	i = 0;
	while (i < data->nb_philo)
	{
		philo = _philo(i);
		if (philo && philo->nb % 2 == 1)
			if (pthread_create(&(philo->id), NULL, &ft_routine, philo) > 0)
				error_thread_create();
		i++;
	}
	return (SUCCESS);
}

int	join_thread(void)
{
	int		i;
	t_philo	*philo;
	t_data	*data;

	data = _data();
	i = 0;
	while (i < data->nb_philo)
	{
		philo = _philo(i);
		if (philo)
			pthread_join(philo->id, NULL);
		i++;
	}
	return (SUCCESS);
}
