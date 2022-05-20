/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   finish_eating.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajung <ajung@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 16:37:12 by ajung             #+#    #+#             */
/*   Updated: 2022/05/20 16:39:07 by ajung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int get_status_finish_eating(t_philo *philo)
{
	t_data	*data;
	int		ret;

	data=_data();
	pthread_mutex_lock(&data->mutex.finish_eating);
	ret = philo->finish_eating;
	pthread_mutex_unlock(&data->mutex.finish_eating);
	return (ret);
}

int	change_status_finish_eating(t_philo *philo, int status)
{
	t_data	*data;

	data = _data();
	pthread_mutex_lock(&data->mutex.finish_eating);
	philo->finish_eating = status;
	pthread_mutex_unlock(&data->mutex.finish_eating);
	return (SUCCESS);
}
