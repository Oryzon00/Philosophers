/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_dead.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oryzon <oryzon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 19:12:22 by ajung             #+#    #+#             */
/*   Updated: 2022/05/25 00:43:46 by oryzon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	check_all_have_eaten(t_data *data)
{
	t_philo	*philo;
	int		i;

	i = 0;
	while (i < data->nb_philo)
	{
		philo = _philo(i);
		if (get_status_finish_eating(philo) == FALSE)
			return (FALSE);
		else
			i++;
	}
	if (i == data->nb_philo)
		return (TRUE);
	else
		return (FALSE);
}

static int	stop_routine_dead(t_data *data)
{
	pthread_mutex_lock(&data->mutex.printf);
	usleep(2000);
	philo_printf_died(get_status_philo_who_died());
	pthread_mutex_unlock(&data->mutex.printf);
	return (SUCCESS);
}

/* static int	stop_routine_max_eat(void)
{
	t_data	*data;

	data = _data();
	pthread_mutex_lock(&data->mutex.printf);
	printf("----- All philos have eaten enough -----\n");
	pthread_mutex_unlock(&data->mutex.printf);
	return (SUCCESS);
}*/

void	check_dead(void)
{
	t_data		*data;

	data = _data();
	while (get_status_philo_is_dead() == FALSE
		&& check_all_have_eaten(data) == FALSE)
		usleep(100);
	if (get_status_philo_is_dead() == TRUE)
		stop_routine_dead(data);
	return ;
}
