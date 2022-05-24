SRC =	src/main.c \
		src/singleton.c \
		src/routine.c \
		src/check_input.c \
		src/init_data/init_data.c \
		src/init_data/init_data2.c \
		src/free_data.c \
		src/thread.c \
		src/time_utils/time_utils.c \
		src/time_utils/time_utils2.c \
		src/not_libft/ft_atoi.c \
		src/not_libft/ft_strlen.c \
		src/not_libft/ft_putstr.c \
		src/not_libft/ft_bzero.c \
		src/philo_action/philo_printf.c \
		src/philo_action/philo_died.c \
		src/philo_action/philo_thinking.c \
		src/philo_action/philo_take_fork.c \
		src/philo_action/philo_sleeping.c \
		src/philo_action/philo_eating.c \
		src/check_dead.c \
		src/mutex/philo_is_dead.c \
		src/mutex/philo_who_died.c \
		src/mutex/time_last_meal.c \
		src/mutex/finish_eating.c \

OBJ = $(SRC:.c=.o)

CC = clang

DEBUG = -fsanitize=thread 

CFLAGS = -Wall -Wextra -Werror -g3 

THREAD = -pthread

OPTI = -O3 -flto

NAME = philo

INC_DIR = inc

ARG_PHILO = 5 610 200 200 20

%.o: %.c
		$(CC) $(CFLAGS) -I ${INC_DIR} ${THREAD} -c $< -o $@

all: $(NAME)

$(NAME):	$(OBJ)
			$(CC) $(CFLAGS) ${THREAD} $(OBJ) -o $(NAME) $(DEBUG)

clean:
		rm -f $(OBJ)

fclean:	clean
		rm -f $(NAME)

re:		fclean $(NAME)

test:
		./$(NAME) $(ARG_PHILO)

test_mutex:
		valgrind --tool=helgrind ./$(NAME) $(ARG_PHILO)

test_leaks:
		valgrind ./$(NAME) $(ARG_PHILO)
	

.PHONY:		all clean fclean re test test_mutex test_leaks
