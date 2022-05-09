/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajung <ajung@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 19:23:45 by ajung             #+#    #+#             */
/*   Updated: 2022/05/09 20:47:08 by ajung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"


int	create_thread(void)
{
	int		i;
	t_data	*data;
	t_philo	*philo;

	data = _data();
	i = 0;
	while (i < data->nb_philo)
	{
		philo = _philo(i);
		philo->nb = i + 1;
		pthread_create(&(philo->id), NULL, &ft_routine, philo);
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
		pthread_join(philo->id, NULL);
		i++;
	}
	return (SUCCESS);
}

int main(int argc, char **argv)
{
	pthread_mutex_t	mutex;
	int				compteur;

	if (check_input(argc, argv) == FAILURE)
		return (FAILURE);
	init_data(argc, argv, &mutex, &compteur);
	create_thread();
	join_thread();
	//free t_philo * philo;
	return (SUCCESS);
}
