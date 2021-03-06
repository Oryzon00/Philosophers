/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajung <ajung@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 16:16:15 by ajung             #+#    #+#             */
/*   Updated: 2022/05/24 18:18:17 by ajung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	init_mutex_fork(void)
{
	t_data	*data;
	int		i;

	data = _data();
	data->mutex.fork = malloc(sizeof(pthread_mutex_t) * data->nb_philo);
	i = 0;
	if (!data->mutex.fork)
	{
		printf("Memory alloc failed\n");
		return (FAILURE);
	}
	while (i < data->nb_philo)
	{
		pthread_mutex_init(&(data->mutex.fork[i]), NULL);
		i++;
	}
	return (SUCCESS);
}

int	init_mutex(void)
{
	t_data	*data;

	data = _data();
	pthread_mutex_init(&(data->mutex.printf), NULL);
	pthread_mutex_init(&(data->mutex.time_last_meal), NULL);
	pthread_mutex_init(&(data->mutex.philo_who_died), NULL);
	pthread_mutex_init(&data->mutex.finish_eating, NULL);
	return (SUCCESS);
}

static int	init_philo_data(void)
{
	t_philo	*philo;
	t_data	*data;
	int		i;

	i = 0;
	data = _data();
	while (i < data->nb_philo)
	{
		philo = _philo(i);
		philo->index = i;
		philo->nb = i + 1;
		philo->finish_eating = FALSE;
		philo->have_eaten = 0;
		philo->right_fork = NULL;
		philo->left_fork = NULL;
		i++;
	}
	return (SUCCESS);
}

int	init_nb_philo(char **argv)
{
	t_data			*data;

	data = _data();
	data->nb_philo = ft_atoi(argv[1]);
	data->philo = malloc(sizeof(t_philo) * data->nb_philo);
	if (!data->philo)
	{
		printf("Memory alloc failed\n");
		return (FAILURE);
	}
	init_philo_data();
	return (SUCCESS);
}

int	init_data(int argc, char **argv)
{
	t_data	*data;

	data = _data();
	if (init_nb_philo(argv) == FAILURE)
		return (FAILURE);
	if (init_mutex_fork() == FAILURE)
		return (free(data->philo), FAILURE);
	init_time_to(argv, argc);
	init_mutex();
	init_divers(argc);
	init_start_time();
	return (SUCCESS);
}
