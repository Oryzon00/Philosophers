/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajung <ajung@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 19:23:45 by ajung             #+#    #+#             */
/*   Updated: 2022/04/19 20:31:02 by ajung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(void)
{
	t_timeval test;
	
	gettimeofday(&test, NULL);
	printf("%ld secondes depuis 1/1/1970\n",
		test.tv_sec);
	
	return (0);
}
