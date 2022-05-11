/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajung <ajung@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 16:16:15 by ajung             #+#    #+#             */
/*   Updated: 2022/05/11 21:13:06 by ajung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"


int	init_mutex()
{
	t_data	*data;

	data = _data();
	pthread_mutex_init(&(data->mutex.printf), NULL);
	return (SUCCESS);
	
}

int	init_nb_philo(char **argv)
{
	t_data			*data;
	t_philo			*philo;
	int				i;

	data = _data();
	data->nb_philo = ft_atoi(argv[1]);
	data->philo = malloc(sizeof(t_philo) * data->nb_philo);
	if (!data->philo)
	{
		ft_putstr("Memory alloc failed\n");
		return (FAILURE);
	}
	i = 0;
	while (i < data->nb_philo)
	{
		philo = _philo(i);
		philo->nb = i + 1;
		i++;
	}
	return (SUCCESS);
}

int	init_divers(int argc)
{
	t_data	*data;

	data = _data();
	data->argc = argc;
	data->philo_is_dead = FALSE;
	return (SUCCESS);
}
int	init_time_to(char **argv, int argc)
{
	t_data	*data;

	data = _data();
	data->time_to_die = ft_atoi(argv[2]);
	data->time_to_eat = ft_atoi(argv[3]);
	data->time_to_sleep = ft_atoi(argv[4]);
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
	return (SUCCESS);
}
