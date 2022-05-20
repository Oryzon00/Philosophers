/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajung <ajung@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 19:03:46 by ajung             #+#    #+#             */
/*   Updated: 2022/05/20 18:49:47 by ajung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>



int	init_time_last_meal(void)
{
	t_philo		*philo;
	int			i;
	t_data		*data;

	i = 0;
	data = _data();
	while (i < data->nb_philo)
	{
		philo = _philo(i);
		change_status_time_last_meal(philo);
		i++;
	}
	return (SUCCESS);
}

int	init_start_time(void)
{
	t_timeval		time_now;
	t_data			*data;

	data = _data();
	gettimeofday(&time_now, NULL);
	data->time.start_sec = time_now.tv_sec;
	data->time.start_ms = time_now.tv_usec / 1000;
	init_time_last_meal();
	return (SUCCESS);
}

int	get_timestamp(void)
{
	int			timestamp;
	t_timeval	time;
	t_data		*data;

	data = _data();
	gettimeofday(&time, NULL);
	timestamp = (time.tv_sec - data->time.start_sec) * 1000
				 + (time.tv_usec / 1000 - data->time.start_ms);

	return (timestamp);
}

int	time_since_last_meal(t_philo *philo)
{
	t_timeval	time_now;
	t_timeval	time_last_meal;
	t_data		*data;

	data = _data();	
	gettimeofday(&time_now, NULL);
	time_last_meal = get_status_time_last_meal(philo);
	return ((time_now.tv_sec - time_last_meal.tv_sec) * 1000
		+ (time_now.tv_usec - time_last_meal.tv_usec) / 1000);
}

int	calculate_if_philo_dead(t_philo *philo)
{
	t_data		*data;

	data = _data();
	if (time_since_last_meal(philo) >= data->time_to_die)
		return (DEAD);
	else
		return (NOT_DEAD);
}


int	check_if_philo_dead(t_philo *philo)
{
	t_data		*data;

	data = _data();
	if (calculate_if_philo_dead(philo) == DEAD)
	{
		change_status_philo_is_dead(TRUE);
		change_status_philo_who_died(philo->nb);
	}
	if (get_status_philo_is_dead() == TRUE)
		return (DEAD);
	else
		return (NOT_DEAD);
}

int	diff_time(t_timeval t1, t_timeval t2)
{
	return ((t1.tv_sec - t2.tv_sec) * 1000 + (t1.tv_usec - t2.tv_usec) / 1000);
}

int    ft_usleep(t_philo *philo, int msec)
{
    t_timeval   t1;
    t_timeval   t2;
	t_data		*data;

	data = _data();
	(void) philo;
    if (msec < 0)
        return (FAILURE);

    gettimeofday(&t1, NULL);
    gettimeofday(&t2, NULL);
	
    while (diff_time(t1, t2) < msec + 1)
    {
		if (check_if_philo_dead(philo) == DEAD)
			break ;
        usleep (500);
        gettimeofday(&t1, NULL);
    }
	return (SUCCESS);
}
