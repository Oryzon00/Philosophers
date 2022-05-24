/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajung <ajung@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 17:16:06 by ajung             #+#    #+#             */
/*   Updated: 2022/05/24 21:18:27 by ajung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	check_nb_philo_valable(void)
{
	t_data	*data;

	data = _data();
	if (data->nb_philo < 1)
	{
		change_status_philo_is_dead(TRUE);
		change_status_philo_who_died(1);
	}
	else if (data->nb_philo == 1)
	{
		usleep(data->time_to_die * 1000);
		change_status_philo_is_dead(TRUE);
		change_status_philo_who_died(1);
	}
}

int	not_dead_and_must_eat(t_philo *philo)
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
	t_philo	*philo;
	int		philo_dead;

	data = _data();
	philo = philo_ptr;
	philo_dead = FALSE;
	check_nb_philo_valable();
	while (not_dead_and_must_eat(philo) == SUCCESS)
	{
		philo_thinking(philo);
		if (check_if_philo_dead(philo) == DEAD)
			break ;
		philo_take_fork(philo);
		if (check_if_philo_dead(philo) == DEAD)
			break ;
		philo_eating(philo);
		if (check_if_philo_dead(philo) == DEAD)
			break ;
		philo_sleeping(philo);
		if (check_if_philo_dead(philo) == DEAD)
			break ;
	}
	drop_fork(philo);
	dprintf(2, "philo %d is over\n", philo->nb);
	return (NULL);
}
