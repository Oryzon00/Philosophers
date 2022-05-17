/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajung <ajung@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 17:16:06 by ajung             #+#    #+#             */
/*   Updated: 2022/05/17 21:23:47 by ajung            ###   ########.fr       */
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
	int		philo_dead;

	data = _data();
	philo = philo_ptr;
	philo_dead = FALSE;
	while (not_dead_and_must_eat(philo) == SUCCESS)
	{
		philo_thinking(philo);
		if (check_status_philo_is_dead(data) == TRUE)
			break ;
		usleep(1000);
		philo_eating(philo);
		if (check_status_philo_is_dead(data) == TRUE)
			break ;
		usleep(1000);
		philo_sleeping(philo);
		if (check_status_philo_is_dead(data) == TRUE)
			break ;
		usleep(1000);
	}
	if (philo->have_eaten >= data->max_eat)
		philo->finish_eating = TRUE;
	return (NULL);
}
