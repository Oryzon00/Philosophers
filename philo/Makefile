SRC = src/main.c \


#src/multi_pipex.c \ 

OBJ = $(SRC:.c=.o)

CC = clang

DEBUG = -fsanitize=address 

CFLAGS = -Wall -Wextra -Werror -g3 

OPTI = -O3 -flto

NAME = philo

INC_DIR = inc

PATH_LIBFT = ./libft

%.o: %.c
		$(CC) $(CFLAGS) -I ${INC_DIR} -c $< -o $@

all: $(NAME)

$(NAME):	$(OBJ)
			$(CC)  $(CFLAGS) $(OBJ) -o $(NAME)

clean:
		rm -f $(OBJ)

fclean:	clean
		rm -f $(NAME)

re:		fclean $(NAME)

.PHONY:		all clean fclean re 
