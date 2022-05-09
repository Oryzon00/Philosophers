/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajung <ajung@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 17:16:06 by ajung             #+#    #+#             */
/*   Updated: 2022/05/09 20:45:48 by ajung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*ft_routine(void *philo_ptr)
{
	t_data	*data;
	t_philo *philo;

	data = _data();
	philo = philo_ptr;
	pthread_mutex_lock(data->mutex);
	printf("I am philo number %d\n", philo->nb);
	printf("compteur = %d\n", *(data->compteur));
	(*(data->compteur))++;
	pthread_mutex_unlock(data->mutex);
	return (NULL);
}
