/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajung <ajung@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 17:12:38 by ajung             #+#    #+#             */
/*   Updated: 2022/05/11 21:35:43 by ajung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"


//printf is sleeping
//printf is eating
//printf has take a fork
//printf is thinking
//print has died

int	printf_mutex(int philo_nb, int timestamp)
{
	t_data	*data;

	data = _data();
	pthread_mutex_lock(&(data->mutex.printf));
	printf("%d philo %d is sleeping", philo_nb);
	pthread_mutex_unlock(&(data->mutex.printf));
	return (SUCCESS);
}

/* int	compteur_mutex()
{
	t_data	*data;

	data = _data();
	pthread_mutex_lock(&(data->mutex.compteur));
	(*data->compteur)++;
	pthread_mutex_unlock(&(data->mutex.compteur));
	return (SUCCESS);
}
 */
