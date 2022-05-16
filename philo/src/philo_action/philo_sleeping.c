/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_sleeping.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajung <ajung@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 21:05:52 by ajung             #+#    #+#             */
/*   Updated: 2022/05/16 21:06:11 by ajung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	philo_sleeping(int philo_nb)
{
	t_data	*data;

	data = _data();
	philo_printf_sleeping(philo_nb);
	usleep(data->time_to_sleep);
	return (SUCCESS);
}
