/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajung <ajung@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 20:22:11 by ajung             #+#    #+#             */
/*   Updated: 2022/05/23 20:22:46 by ajung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	init_divers(int argc)
{
	t_data	*data;

	data = _data();
	data->argc = argc;
	data->philo_is_dead = FALSE;
	data->philo_who_died = -1;
	return (SUCCESS);
}

int	init_time_to(char **argv, int argc)
{
	t_data	*data;

	data = _data();
	data->time_to_die = ft_atoi(argv[2]);
	data->time_to_eat = ft_atoi(argv[3]);
	data->time_to_sleep = ft_atoi(argv[4]);
	if (argc == 6)
		data->max_eat = ft_atoi(argv[5]);
	return (SUCCESS);
}
