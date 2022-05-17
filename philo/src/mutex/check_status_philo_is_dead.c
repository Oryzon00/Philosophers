/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_status_philo_is_dead.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajung <ajung@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 21:25:25 by ajung             #+#    #+#             */
/*   Updated: 2022/05/17 21:28:40 by ajung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int check_status_philo_is_dead(t_data *data)
{
	pthread_mutex_lock(&data->mutex.philo_is_dead);
	if (data->philo_is_dead == TRUE)
	{
		pthread_mutex_unlock(&data->mutex.philo_is_dead);
		return (TRUE);
	}
	else
	{
		pthread_mutex_unlock(&data->mutex.philo_is_dead);
		return (FALSE);
	}
}
