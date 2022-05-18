/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_is_dead.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajung <ajung@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 21:25:25 by ajung             #+#    #+#             */
/*   Updated: 2022/05/18 20:28:23 by ajung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int get_status_philo_is_dead(void)
{
	t_data	*data;
	int		ret;

	data=_data();
	pthread_mutex_lock(&data->mutex.philo_is_dead);
	ret = data->philo_is_dead;
	pthread_mutex_unlock(&data->mutex.philo_is_dead);
	return (ret);
}

int	change_status_philo_is_dead(int status)
{
	t_data	*data;

	data = _data();
	pthread_mutex_lock(&data->mutex.philo_is_dead);
	data->philo_is_dead = status;
	pthread_mutex_unlock(&data->mutex.philo_is_dead);
	return (SUCCESS);
}
