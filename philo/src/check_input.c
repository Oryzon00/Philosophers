/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajung <ajung@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 17:32:21 by ajung             #+#    #+#             */
/*   Updated: 2022/05/11 16:53:50 by ajung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_nb_param(int argc)
{
	if (argc != 5 && argc != 6)
	{
		ft_putstr("Error: nb of parameters required is  5 or 6\n");
		return (FAILURE);
	}
	return (SUCCESS);
}

int	check_param_is_positive_int(char **argv, int argc)
{
	if (ft_atoi(argv[1]) == ATOI_FAILURE
		| ft_atoi(argv[2]) == ATOI_FAILURE
		| ft_atoi(argv[3]) == ATOI_FAILURE
		| ft_atoi(argv[4]) == ATOI_FAILURE)
	{
		ft_putstr("Error: Parameters are not positive int\n");
		return (FAILURE);
	}
	if (argc == 6
		&& ft_atoi(argv[5]) == ATOI_FAILURE)
		{
			ft_putstr("Error: Parameters are not positive int\n");
			return (FAILURE);
		}
	return (SUCCESS);
}

int	check_value_param(char **argv)
{
	if (ft_atoi(argv[1]) > 200)
	{
		ft_putstr("Error: number of philosopher can't be above 200\n");
		return (FAILURE);
	}
	if (ft_atoi(argv[2]) < 60
		| ft_atoi(argv[3]) < 60
		| ft_atoi(argv[4]) < 60)
	{
		ft_putstr("Error: time to die, eat or sleep must be above 60\n");
		return (FAILURE);	
	}
	return (SUCCESS);
}

int	check_input(int argc, char ** argv)
{
	(void) argv;
	if (check_nb_param(argc) == FAILURE)
		return (FAILURE);
	if (check_param_is_positive_int(argv, argc) == FAILURE)
		return (FAILURE);
	if (check_value_param(argv) == FAILURE)
		return (FAILURE);
	return (SUCCESS);
}
