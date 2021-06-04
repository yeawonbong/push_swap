SRC = push_swap.c


CC = gcc
CFLAGES = -Wall -Wextra -Werror
AR = ar rcs
NAME = push_swap.a
OBJ = $(SRC:.c=.o)
LIB = llibft
LIB_DIR = -L./libft

all : $(NAME)

$(NAME) : $(OBJ)
	$(AR) $@ $(OBJ)

$(OBJ) : $(SRC)
	$(CC) $(CFLAGES) -c $(SRC)

clean :
	rm -f $(OBJ)

fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY: all clean fclean re