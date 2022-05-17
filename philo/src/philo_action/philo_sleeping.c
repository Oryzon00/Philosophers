/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_sleeping.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajung <ajung@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 21:05:52 by ajung             #+#    #+#             */
/*   Updated: 2022/05/17 16:08:54 by ajung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	philo_sleeping(t_philo *philo)
{
	t_data	*data;

	data = _data();
	philo_printf_sleeping(philo);
	usleep(data->time_to_sleep);
	return (SUCCESS);
}
