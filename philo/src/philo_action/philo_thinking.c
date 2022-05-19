/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_thinking.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajung <ajung@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 20:58:12 by ajung             #+#    #+#             */
/*   Updated: 2022/05/19 16:56:34 by ajung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"


static int	calculate_if_philo_can_wait(t_philo *philo)
{
	t_data		*data;

	data = _data();
	if (time_since_last_meal(philo) >= data->time_to_die / 2)
		return (CAN_NOT_WAIT);
	else
		return (CAN_WAIT);
}

int	philo_thinking(t_philo *philo)
{
	philo_printf_thinking(philo);
	while(calculate_if_philo_can_wait(philo) == CAN_WAIT)
		usleep(100);
	return (SUCCESS);
}
