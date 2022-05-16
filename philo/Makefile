SRC =	src/main.c \
		src/singleton.c \
		src/routine.c \
		src/check_input.c \
		src/init_data.c \
		src/free_data.c \
		src/thread.c \
		src/time_utils.c \
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

OBJ = $(SRC:.c=.o)

CC = clang

DEBUG = -fsanitize=address 

CFLAGS = -Wall -Wextra -Werror -g3 

THREAD = -pthread

OPTI = -O3 -flto

NAME = philo

INC_DIR = inc

%.o: %.c
		$(CC) $(CFLAGS) -I ${INC_DIR} ${THREAD} -c $< -o $@

all: $(NAME)

$(NAME):	$(OBJ)
			$(CC) $(CFLAGS) ${THREAD} $(OBJ) -o $(NAME)

clean:
		rm -f $(OBJ)

fclean:	clean
		rm -f $(NAME)

re:		fclean $(NAME)

test:
		valgrind --tool=helgrind ./$(NAME) 10 60 60 60

test_leaks:
		valgrind ./$(NAME) 10 60 60 60

.PHONY:		all clean fclean re test
