/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time_utils2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajung <ajung@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 14:28:59 by ajung             #+#    #+#             */
/*   Updated: 2022/05/24 15:36:12 by ajung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_if_philo_dead(t_philo *philo)
{
	t_data		*data;

	data = _data();
	if (calculate_if_philo_dead(philo) == DEAD)
	{
		change_status_philo_is_dead(TRUE);
		change_status_philo_who_died(philo->nb);
	}
	if (get_status_philo_is_dead() == TRUE)
		return (DEAD);
	else
		return (NOT_DEAD);
}

int	diff_time(t_timeval t1, t_timeval t2)
{
	return ((t1.tv_sec - t2.tv_sec) * 1000 + (t1.tv_usec - t2.tv_usec) / 1000);
}

int	ft_usleep(t_philo *philo, int msec)
{
	t_timeval		t1;
	t_timeval		t2;
	t_data			*data;

	data = _data();
	(void) philo;
	if (msec < 0)
		return (FAILURE);
	gettimeofday(&t1, NULL);
	gettimeofday(&t2, NULL);
	while (diff_time(t1, t2) < msec + 1)
	{
		if (check_if_philo_dead(philo) == DEAD)
			break ;
		usleep (500);
		gettimeofday(&t1, NULL);
	}
	return (SUCCESS);
}
