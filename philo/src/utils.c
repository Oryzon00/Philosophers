/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajung <ajung@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 17:12:38 by ajung             #+#    #+#             */
/*   Updated: 2022/05/09 20:25:08 by ajung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"


int	init_data(int argc, char **argv, pthread_mutex_t *mutex, int *compteur)
{
	t_data			*data;
	t_philo			*philo;
	int				i;

	(void) argc;
	data = _data();
	data->nb_philo = ft_atoi(argv[1]);
	data->philo = malloc(sizeof(t_philo) * data->nb_philo);
	if (!data->philo)
		return (FAILURE);
	i = 0;
	while (i < data->nb_philo)
	{
		philo = _philo(i);
		philo->nb = i + 1;
		i++;
	}
	*compteur = 0;
	data->compteur = compteur;
	pthread_mutex_init(mutex, NULL);
	data->mutex = mutex;
	return (SUCCESS);
}
