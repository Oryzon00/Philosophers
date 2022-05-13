/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajung <ajung@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 19:23:45 by ajung             #+#    #+#             */
/*   Updated: 2022/05/13 19:29:47 by ajung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int main(int argc, char **argv)
{
	if (check_input(argc, argv) == FAILURE)
		return (FAILURE);
	ft_putstr("Params are okay\n");
	if (init_data(argc, argv) == FAILURE)
		return (FAILURE);
	init_thread();
	join_thread();
	free_data();
	return (SUCCESS);

}


