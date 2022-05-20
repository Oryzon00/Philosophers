/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajung <ajung@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 19:24:51 by ajung             #+#    #+#             */
/*   Updated: 2022/05/20 19:10:17 by ajung            ###   ########.fr       */
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
# define DEAD 1
# define NOT_DEAD 0
# define CAN_WAIT 1
# define CAN_NOT_WAIT 0

typedef struct timeval t_timeval;

typedef struct s_time_start
{
	unsigned long	start_sec;
	unsigned long	start_ms;
}	t_time_start;

typedef struct s_philo
{
	int				nb;
	int				index;
	pthread_t		id;
	int				have_eaten;
	t_timeval		time_last_meal; 
	int				finish_eating;
}	t_philo;

typedef struct s_mutex
{
	pthread_mutex_t	printf;
	pthread_mutex_t	time_last_meal;
	pthread_mutex_t	philo_is_dead;
	pthread_mutex_t	philo_who_died;
	pthread_mutex_t	finish_eating;
	pthread_mutex_t	*fork;
}	t_mutex;

typedef struct s_data
{
	t_philo			*philo;
	t_mutex			mutex;
	t_time_start	time;
	int				philo_is_dead;
	int				philo_who_died;
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
int	philo_sleeping(t_philo *philo);
int	philo_eating(t_philo *philo);
int	philo_take_fork(t_philo *philo);
int	philo_thinking(t_philo *philo);
int	philo_died(t_philo *philo);

//PHILO PRINTF
int	philo_printf_sleeping(t_philo *philo);
int	philo_printf_eating(t_philo *philo);
int	philo_printf_take_fork(t_philo *philo);
int	philo_printf_thinking(t_philo *philo);
int	philo_printf_died(int philo_who_died);

// TIME UTILS
int	init_start_time(void);
int	get_timestamp(void);
int	calculate_if_philo_dead(t_philo *philo);
int	time_since_last_meal(t_philo *philo);
int   ft_usleep(t_philo *philo, int msec);
int	diff_time(t_timeval t1, t_timeval t2);
int	check_if_philo_dead(t_philo *philo);

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

//CHECK DEAD
void	check_dead(void);

//MUTEX
//PHILO_IS_DEAD
int 		get_status_philo_is_dead(void);
int			change_status_philo_is_dead(int status);
//PHILO_WHO_DIED
int 		get_status_philo_who_died(void);
int			change_status_philo_who_died(int status);
//TIME_LAST_MEAL
t_timeval	get_status_time_last_meal(t_philo *philo);
int			change_status_time_last_meal(t_philo *philo);
//FINISH EATING
int get_status_finish_eating(t_philo *philo);
int	change_status_finish_eating(t_philo *philo, int status);






#endif
