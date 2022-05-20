/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_eating.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajung <ajung@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 21:00:40 by ajung             #+#    #+#             */
/*   Updated: 2022/05/20 18:03:11 by ajung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"


int	philo_eating(t_philo *philo)
{
	t_data		*data;

	data = _data();
	philo_printf_eating(philo);
	change_status_time_last_meal(philo);
	philo->have_eaten++;
	ft_usleep(philo, data->time_to_eat);
	return (SUCCESS);
}
