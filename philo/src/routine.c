/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajung <ajung@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 17:16:06 by ajung             #+#    #+#             */
/*   Updated: 2022/05/18 21:45:21 by ajung            ###   ########.fr       */
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
		if (get_status_philo_is_dead() == TRUE | philo->have_eaten >= data->max_eat)
			return (FAILURE);
	}
	return (SUCCESS);
}

//coder fct calcul check philo dead
int	calculate_if_philo_dead(t_philo *philo)
{
	t_timeval	time_now;
	t_data		*data;

	data = _data();
	gettimeofday(&time_now, NULL);
	if (time_now.tv_sec * 1000 + time_now.tv_usec / 1000 - get_status_time_last_meal(philo)
		>= data->time_to_die)
	{
		dprintf(2, "calcul = %d\n", time_now.tv_sec * 1000 + time_now.tv_usec / 1000 - get_status_time_last_meal(philo)
					>= (unsigned long) data->time_to_die);
		change_status_philo_is_dead(TRUE);
		change_status_philo_who_died(philo->nb);
	}
	if (get_status_philo_is_dead() == TRUE)
		return (DEAD);
	else
		return (NOT_DEAD);

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
		if (calculate_if_philo_dead(philo) == DEAD)
			break ;	
		philo_eating(philo);
		if (calculate_if_philo_dead(philo) == DEAD)
			break ;
		philo_sleeping(philo);
	}
	if (philo->have_eaten >= data->max_eat)
		philo->finish_eating = TRUE;
	return (NULL);
}
