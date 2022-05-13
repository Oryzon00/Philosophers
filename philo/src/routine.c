/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajung <ajung@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 17:16:06 by ajung             #+#    #+#             */
/*   Updated: 2022/05/13 18:43:23 by ajung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int not_dead_and_must_eat(t_philo *philo)
{
	t_data	*data;

	data = _data();
	if (data->argc == 5)
	{
		if (data->philo_is_dead == TRUE)
			return (FAILURE);
	}
	else if (data->argc == 6)
	{
		if (data->philo_is_dead == TRUE | philo->have_eaten >= data->max_eat)
			return (FAILURE);
	}
	return (SUCCESS);
}

void	*ft_routine(void *philo_ptr)
{
	t_data	*data;
	t_philo *philo;

	data = _data();
	philo = philo_ptr;
	philo->have_eaten = 0;
	while (not_dead_and_must_eat(philo) == SUCCESS)
	{
		break ;
	}
	
	return (NULL);
}
