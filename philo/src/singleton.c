/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   singleton.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajung <ajung@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 17:12:36 by ajung             #+#    #+#             */
/*   Updated: 2022/05/09 17:13:49 by ajung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_data	*_data(void)
{
	static int		check;
	static t_data	data;

	if (check == 0)
	{
		check = 1;
		ft_bzero(&data, sizeof(t_data));
	}
	return (&data);
}

t_philo	*_philo(int i)
{
	t_data	*data;

	data = _data();
	return (&(data->philo[i]));
}
