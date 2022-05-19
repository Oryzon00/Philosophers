/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajung <ajung@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 19:23:45 by ajung             #+#    #+#             */
/*   Updated: 2022/05/19 18:16:04 by ajung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int main(int argc, char **argv)
{
	if (check_input(argc, argv) == FAILURE)
		return (FAILURE);
	dprintf(2, "Params are okay\n");
	if (init_data(argc, argv) == FAILURE)
		return (FAILURE);
	init_thread();
	check_dead();
	join_thread();
	free_data();
	return (SUCCESS);

}
