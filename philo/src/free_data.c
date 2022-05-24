/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajung <ajung@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 19:46:53 by ajung             #+#    #+#             */
/*   Updated: 2022/05/24 21:23:05 by ajung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	free_data(void)
{
	t_data	*data;
	int		i;

	data = _data();
	i = 0;
	free(data->philo);
	free(data->mutex.fork);
	//destroy mes mutex
}
