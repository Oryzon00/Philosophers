/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajung <ajung@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 17:16:06 by ajung             #+#    #+#             */
/*   Updated: 2022/05/20 18:49:56 by ajung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int not_dead_and_must_eat(t_philo *philo)
{
	t_data	*data;

	data = _data();
	if (data->argc == 5)
	{
		if (get_status_philo_is_dead() == TRUE)
			return (FAILURE);
	}
	else if (data->argc == 6)
	{
		if (get_status_philo_is_dead() == TRUE
			| philo->have_eaten >= data->max_eat)
		{
			if (philo->have_eaten >= data->max_eat)
				change_status_finish_eating(philo, TRUE);
			return (FAILURE);
		}
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
		if (check_if_philo_dead(philo) == DEAD)
			break ;	
		philo_eating(philo);
		if (check_if_philo_dead(philo) == DEAD)
			break ;
		philo_sleeping(philo);
		if (check_if_philo_dead(philo) == DEAD)
			break ;
	}
	return (NULL);
}
