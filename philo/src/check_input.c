/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajung <ajung@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 17:32:21 by ajung             #+#    #+#             */
/*   Updated: 2022/05/09 20:03:41 by ajung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_input(int argc, char ** argv)
{
	(void) argv;
	if (argc != 2)
	{
		ft_putstr("Erreur nb parametres :/ \n");
		return (FAILURE);
	}
	
	return (SUCCESS);
}
