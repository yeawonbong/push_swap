SRCS = push_swap.c

CC = gcc
CFLAGES = -Wall -Wextra -Werror
AR = ar rcs
NAME = push_swap.a
OBJS = $(SRCS:.c=.o)
LIBS = libft.a
LIBS_DIR = ./libft_ps

all : $(NAME)

$(NAME) : $(OBJS)
	$(AR) $@ $(OBJS)

$(OBJS) : $(SRCS) $(LIBS)
	$(CC) $(CFLAGES) -c $(SRCS) -L$(LIBS_DIR) -lft

$(LIBS) : 
	@make -C $(LIBS_DIR)	
	@cp $(LIBS_DIR)/$(LIBS) .
	make -C $(LIBS_DIR) fclean

clean :
	rm -f $(OBJS)

fclean : clean
	rm -f $(NAME)
	rm -f  $(LIBS)

re : fclean all

.PHONY: all clean fclean re libft