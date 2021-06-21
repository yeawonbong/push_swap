SRCS = push_swap.c\
ps_get_arg.c\
ps_stack_tools.c\
ps_sorting_prep.c\
ps_sorting_small.c\
ps_sorting_stacks.c\
psf_push.c\
psf_swap.c\
psf_rotate.c\
psf_reverse_rotate.c

CC = gcc
CFLAGES = -Wall -Wextra -Werror
AR = ar rcs
NAME = push_swap.a
OBJS = $(SRCS:.c=.o)
LIBS = libft.a
LIBS_DIR = ./libft_ps
OUT = push_swap

all : $(NAME)

$(NAME) : $(OBJS) 
	make all -C $(LIBS_DIR)	
	@cp $(LIBS_DIR)/$(LIBS) $(NAME)
	$(AR) $@ $(OBJS)
	gcc $(CFLAGS) $(NAME) -o $(OUT)

$(OBJS) : $(SRCS)
	$(CC) $(CFLAGES) -c $(SRCS) -I libft_ps

clean :
	rm -f $(OBJS)
	make clean -C $(LIBS_DIR)

fclean : clean
	rm -f $(NAME)
	rm -f $(OBJS)
	rm -f *.out
	make fclean -C $(LIBS_DIR)

re : fclean all

.PHONY: all clean fclean re libft