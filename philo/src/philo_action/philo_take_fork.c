/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_take_fork.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajung <ajung@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 20:59:23 by ajung             #+#    #+#             */
/*   Updated: 2022/05/23 20:07:13 by ajung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	take_right_fork(t_philo *philo)
{
	t_data	*data;

	data = _data();
	pthread_mutex_lock(&data->mutex.fork[philo->nb - 1]);
	philo->right_fork = &data->mutex.fork[philo->nb - 1];
	return (SUCCESS);
}

static int	take_left_fork(t_philo *philo)
{
	t_data	*data;

	data = _data();
	if (philo->nb == data->nb_philo)
	{
		pthread_mutex_lock(&data->mutex.fork[0]);
		philo->left_fork = &data->mutex.fork[0];
	}
	else
	{
		pthread_mutex_lock(&data->mutex.fork[philo->nb]);
		philo->left_fork = &data->mutex.fork[philo->nb];
	}
	return (SUCCESS);
}

static int	take_fork_1(t_philo *philo)
{
	t_data	*data;

	data = _data();
	if (philo->nb % 2 == 0)
		take_right_fork(philo);
	else
		take_left_fork(philo);
	if (check_if_philo_dead(philo) == DEAD)
		return (FAILURE);
	philo_printf_take_fork(philo);
	return (SUCCESS);
}

static int	take_fork_2(t_philo *philo)
{
	t_data	*data;

	data = _data();
	if (philo->nb % 2 == 0)
		take_left_fork(philo);
	else
		take_right_fork(philo);
	if (check_if_philo_dead(philo) == DEAD)
		return (FAILURE);
	philo_printf_take_fork(philo);
	return (SUCCESS);
}

int	philo_take_fork(t_philo *philo)
{
	take_fork_1(philo);
	if (check_if_philo_dead(philo) == DEAD)
		return (FAILURE);
	take_fork_2(philo);
	return (SUCCESS);
}
