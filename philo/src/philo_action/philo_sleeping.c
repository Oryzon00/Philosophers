/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_sleeping.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajung <ajung@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 21:05:52 by ajung             #+#    #+#             */
/*   Updated: 2022/05/24 18:27:48 by ajung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	philo_sleeping(t_philo *philo)
{
	t_data	*data;

	data = _data();
	if (check_if_philo_dead(philo) == DEAD)
		return (FAILURE);
	philo_printf_sleeping(philo);
	ft_usleep(philo, data->time_to_sleep * 1000);
	return (SUCCESS);
}
