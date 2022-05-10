/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajung <ajung@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 16:16:15 by ajung             #+#    #+#             */
/*   Updated: 2022/05/10 19:19:22 by ajung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"


int	init_mutex()
{
	t_data	*data;

	data = _data();
	pthread_mutex_init(&(data->mutex.printf), NULL);
	pthread_mutex_init(&(data->mutex.compteur), NULL);

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
		return (FAILURE);
	i = 0;
	while (i < data->nb_philo)
	{
		philo = _philo(i);
		philo->nb = i + 1;
		i++;
	}
	return (SUCCESS);
}

int	init_compteur(int *compteur)
{
	t_data	*data;

	data = _data();
	*compteur = 0;
	data->compteur = compteur;
	return (SUCCESS);
}


int	init_data(int argc, char **argv, int *compteur)
{
	(void) argc;
	init_compteur(compteur);
	init_nb_philo(argv);
	init_mutex();
	return (SUCCESS);
}
