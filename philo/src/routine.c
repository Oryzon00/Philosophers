/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajung <ajung@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 17:16:06 by ajung             #+#    #+#             */
/*   Updated: 2022/05/10 17:23:12 by ajung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*ft_routine(void *philo_ptr)
{
	t_data	*data;
	t_philo *philo;

	data = _data();
	philo = philo_ptr;
	printf_mutex(philo->nb, data->compteur);
	compteur_mutex();
	return (NULL);
}
