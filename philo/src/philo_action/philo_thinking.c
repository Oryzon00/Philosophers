/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_thinking.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajung <ajung@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 20:58:12 by ajung             #+#    #+#             */
/*   Updated: 2022/05/18 20:25:34 by ajung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	can_wait(t_philo *philo)
{
/* 	t_data		*data;
	t_timeval	time_now;

	data = _data();
	gettimeofday(&time_now, NULL);
	if (time_now.tv_usec / 1000 - get_status_time_last_meal(philo)
		> data->time_to_die / 2)
		return (TRUE);
	else
		return (FALSE); */
	(void) philo;
	return (FALSE);
}

int	philo_thinking(t_philo *philo)
{
	philo_printf_thinking(philo);
	while(can_wait(philo) == TRUE)
		usleep(1000);
	return (SUCCESS);
}
