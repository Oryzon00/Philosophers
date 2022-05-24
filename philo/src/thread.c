/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajung <ajung@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 19:56:23 by ajung             #+#    #+#             */
/*   Updated: 2022/05/24 21:20:54 by ajung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

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
			pthread_create(&(philo->id), NULL, &ft_routine, philo);
		i++;
	}
	usleep(100);
	i = 0;
	while (i < data->nb_philo)
	{
		philo = _philo(i);
		if (philo && philo->nb % 2 == 1)
			if (pthread_create(&(philo->id), NULL, &ft_routine, philo) > 0)
				dprintf(2, "---------------PTHREAD CREATE C'EST DE LA MERDE\n----------");
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
	dprintf(2, "start join thread\n");
	while (i < data->nb_philo)
	{
		philo = _philo(i);
		if (philo)
			pthread_join(philo->id, NULL);
		i++;
	}
	dprintf(2, "end join thread\n");
	return (SUCCESS);
}
