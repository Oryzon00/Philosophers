/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_eating.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajung <ajung@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 21:00:40 by ajung             #+#    #+#             */
/*   Updated: 2022/05/23 19:05:44 by ajung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	drop_fork(t_philo *philo)
{
	if (philo->right_fork != NULL)
		pthread_mutex_unlock(philo->right_fork);
	if (philo->left_fork != NULL)
		pthread_mutex_unlock(philo->left_fork);
	philo->right_fork = NULL;
	philo->left_fork = NULL;
	return (SUCCESS);
}

int	philo_eating(t_philo *philo)
{
	t_data		*data;

	data = _data();
	if (check_if_philo_dead(philo) == DEAD)
		return (FAILURE);
	philo_printf_eating(philo);
	change_status_time_last_meal(philo);
	philo->have_eaten++;
	ft_usleep(philo, data->time_to_eat);
	drop_fork(philo);
	return (SUCCESS);
}
