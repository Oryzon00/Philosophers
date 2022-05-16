/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajung <ajung@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 19:24:51 by ajung             #+#    #+#             */
/*   Updated: 2022/05/16 21:08:38 by ajung            ###   ########.fr       */
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

typedef struct timeval t_timeval;

typedef struct s_time_start
{
	unsigned long	start_sec;
	unsigned long	start_ms;
}	t_time_start;

typedef struct s_philo
{
	int				nb;
	pthread_t		id;
	int				have_eaten;
	int				time_last_meal;

}	t_philo;

typedef struct s_mutex
{
	pthread_mutex_t	printf;
	pthread_mutex_t	time_last_meal;
}	t_mutex;

typedef struct s_data
{
	t_philo			*philo;
	t_mutex			mutex;
	t_time_start	time;
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

//PHILO ACTION
int	philo_sleeping(int philo_nb);
int	philo_eating(int philo_nb);
int	philo_take_fork(int philo_nb);
int	philo_thinking(int philo_nb);
int	philo_died(int philo_nb);

//PHILO PRINTF
int	philo_printf_sleeping(int philo_nb);
int	philo_printf_eating(int philo_nb);
int	philo_printf_take_fork(int philo_nb);
int	philo_printf_thinking(int philo_nb);
int	philo_printf_died(int philo_nb);

// TIME UTILS
int	init_start_time(void);
int	get_timestamp(void);

//CHECK INPUT
int	check_input(int argc, char ** argv);

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
