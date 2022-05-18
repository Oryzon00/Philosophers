/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajung <ajung@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 16:16:15 by ajung             #+#    #+#             */
/*   Updated: 2022/05/18 17:55:24 by ajung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"


int	init_mutex()
{
	t_data	*data;

	data = _data();
	pthread_mutex_init(&(data->mutex.printf), NULL);
	pthread_mutex_init(&(data->mutex.time_last_meal), NULL);
	pthread_mutex_init(&(data->mutex.philo_who_died), NULL);

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
		ft_putstr("Memory alloc failed\n");
		return (FAILURE);
	}
	init_philo_data();
	return (SUCCESS);
}

int	init_divers(int argc)
{
	t_data	*data;

	data = _data();
	data->argc = argc;
	data->philo_is_dead = FALSE;
	data->philo_who_died = -1;
	return (SUCCESS);
}

// * 1000 conversion milliseconde en microseconde pour usleep
int	init_time_to(char **argv, int argc)
{
	t_data	*data;

	data = _data();
	data->time_to_die = ft_atoi(argv[2]);
	data->time_to_eat = ft_atoi(argv[3]) * 1000;
	data->time_to_sleep = ft_atoi(argv[4]) * 1000;
	if (argc == 6)
		data->max_eat = ft_atoi(argv[5]);
	return (SUCCESS);
}


int	init_data(int argc, char **argv)
{
	if (init_nb_philo(argv) == FAILURE)
		return (FAILURE);
	init_time_to(argv, argc);
	init_mutex();
	init_divers(argc);
	init_start_time();
	return (SUCCESS);
}
