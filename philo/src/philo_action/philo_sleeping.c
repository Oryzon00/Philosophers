/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_sleeping.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajung <ajung@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 21:05:52 by ajung             #+#    #+#             */
/*   Updated: 2022/05/20 18:03:18 by ajung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	philo_sleeping(t_philo *philo)
{
	t_data	*data;

	data = _data();
	philo_printf_sleeping(philo);
	ft_usleep(philo, data->time_to_sleep);
	return (SUCCESS);
}
