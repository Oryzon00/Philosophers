/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajung <ajung@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 17:12:38 by ajung             #+#    #+#             */
/*   Updated: 2022/05/10 17:21:59 by ajung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	printf_mutex(int philo_nb, int *compteur)
{
	t_data	*data;

	data = _data();
	pthread_mutex_lock(&(data->mutex.printf));
	printf("I am philo number %d\n", philo_nb);
	pthread_mutex_lock(&(data->mutex.compteur));
	printf("compteur = %d\n", *compteur);
	pthread_mutex_unlock(&(data->mutex.compteur));
	pthread_mutex_unlock(&(data->mutex.printf));
	return (SUCCESS);
}

int	compteur_mutex()
{
	t_data	*data;

	data = _data();
	pthread_mutex_lock(&(data->mutex.compteur));
	(*data->compteur)++;
	pthread_mutex_unlock(&(data->mutex.compteur));
	return (SUCCESS);
}
