NAME = pipex

SRC = pipex.c \
	childs.c \
	ft_split.c \
	ft_strjoin.c \
	ft_strncmp.c 

OBJ = $(SRC:.c=.o)

CC = gcc

CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME):
	$(CC) $(SRC) -o $(NAME)
	
clean:
	rm -f $(OBJ) $(BONUS_OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

bonus : $(OBJS) $(BONUS_OBJS)
				ar rcs $(NAME) $(OBJS) $(BONUS_OBJS)

.PHONY : clean fclean bonus re all