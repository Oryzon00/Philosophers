/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajung <ajung@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 19:24:51 by ajung             #+#    #+#             */
/*   Updated: 2022/05/09 20:24:10 by ajung            ###   ########.fr       */
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

# define SUCCESS 0
# define FAILURE 1

typedef struct s_philo
{
	int				nb;
	pthread_t		id;
}	t_philo;

typedef struct s_data
{
	t_philo			*philo;
	int				*compteur;
	pthread_mutex_t	*mutex;
	int				nb_philo;
}	t_data;

//SINGLETON
t_data	*_data(void);
t_philo	*_philo(int i);

//UTILS
int	init_data(int argc, char **argv, pthread_mutex_t *mutex, int *compteur);

//CHECK INPUT
int	check_input(int argc, char ** argv);


//ROUTINE
void	*ft_routine(void *philo_ptr);

//NOT_LIBFT
int	ft_putstr(char *str);
int	ft_strlen(char *str);
int	ft_atoi(const char *nptr);
void	ft_bzero(void *s, size_t n);

#endif
//typedef	struct timeval t_timeval;

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
/* int	main(void)
{
	t_timeval test;
	
	gettimeofday(&test, NULL);
	printf("%ld secondes depuis 1/1/1970\n",
		test.tv_sec);
	printf("%ld micro sec depuis derniere seconde\n",test.tv_usec);
	
	return (0);
} */
