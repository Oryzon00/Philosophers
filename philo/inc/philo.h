/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajung <ajung@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 19:24:51 by ajung             #+#    #+#             */
/*   Updated: 2022/04/20 17:55:52 by ajung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <sys/time.h>
# include <pthread.h>



typedef	struct timeval t_timeval;

# define SUCCESS 0
# define FAILURE (!SUCCESS)

/* 
struct timeval {
    time_t      tv_sec;  --> secondes
    suseconds_t tv_usec; --> microsecondes
}; 


int gettimeofday(struct timeval *tv, NULL);

int pthread_create(pthread_t *restrict thread,
                          const pthread_attr_t *restrict attr,
                          void *(*start_routine)(void *),
                          void *restrict arg);

*/
#endif
