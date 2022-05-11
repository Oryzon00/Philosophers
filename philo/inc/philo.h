/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajung <ajung@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 19:24:51 by ajung             #+#    #+#             */
/*   Updated: 2022/05/11 21:08:24 by ajung            ###   ########.fr       */
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
# define ATOI_FAILURE -1
# define TRUE 1
# define FALSE 0

typedef struct s_philo
{
	int				nb;
	pthread_t		id;
	int				have_eaten;
}	t_philo;

typedef struct s_mutex
{
	pthread_mutex_t	printf;
	pthread_mutex_t	compteur;
}	t_mutex;

typedef struct s_data
{
	t_philo			*philo;
	t_mutex			mutex;
	int				philo_is_dead;
	int				nb_philo;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				max_eat;
	int				argc;
}	t_data;

//SINGLETON
t_data	*_data(void);
t_philo	*_philo(int i);

//UTILS
int	printf_mutex(int philo_nb);


//CHECK INPUT
int		check_input(int argc, char ** argv);

//INIT_DATA
int	init_data(int argc, char **argv);

//ROUTINE
void	*ft_routine(void *philo_ptr);

//NOT_LIBFT
int		ft_putstr(char *str);
int		ft_strlen(const char *str);
int		ft_atoi(const char *nptr);
void	ft_bzero(void *s, size_t n);

//FREE DATA
void	free_data(void);

//THREAD
int	init_thread(void);
int	join_thread(void);

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
