/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajung <ajung@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 19:03:46 by ajung             #+#    #+#             */
/*   Updated: 2022/05/13 20:26:23 by ajung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

int	init_start_time(void)
{
	t_timeval		time;
	t_data			*data;

	gettimeofday(&time, NULL);
	data = _data();
	data->time.start_sec = time.tv_sec;
	data->time.start_ms = time.tv_usec / 1000;
	return (SUCCESS);
}

int	get_time_stamp
//time stamp = difference sec * 1000 + difference ms
