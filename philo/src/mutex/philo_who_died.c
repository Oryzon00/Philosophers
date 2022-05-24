/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_who_died.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajung <ajung@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 17:56:08 by ajung             #+#    #+#             */
/*   Updated: 2022/05/24 14:39:11 by ajung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	change_status_philo_who_died(int status)
{
	t_data	*data;

	data = _data();
	pthread_mutex_lock(&data->mutex.philo_who_died);
	data->philo_who_died = status;
	pthread_mutex_unlock(&data->mutex.philo_who_died);
	return (SUCCESS);
}

int	get_status_philo_who_died(void)
{
	t_data	*data;
	int		ret;

	data = _data();
	pthread_mutex_lock(&data->mutex.philo_who_died);
	ret = data->philo_who_died;
	pthread_mutex_unlock(&data->mutex.philo_who_died);
	return (ret);
}
