# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ybong <ybong@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/12/28 00:12:32 by ybong             #+#    #+#              #
#    Updated: 2021/06/08 20:31:39 by ybong            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = ft_atoi.c\
ft_bzero.c\
ft_isalnum.c\
ft_isalpha.c\
ft_isascii.c\
ft_isdigit.c\
ft_isprint.c\
ft_memccpy.c\
ft_memcpy.c\
ft_memset.c\
ft_memmove.c\
ft_memchr.c\
ft_memcmp.c\
ft_tolower.c\
ft_toupper.c\
ft_strlen.c\
ft_strlcpy.c\
ft_strlcat.c\
ft_strchr.c\
ft_strrchr.c\
ft_strnstr.c\
ft_strncmp.c\
ft_calloc.c\
ft_strdup.c\
ft_substr.c\
ft_strjoin.c\
ft_strtrim.c\
ft_split.c\
ft_itoa.c\
ft_strmapi.c\
ft_putchar_fd.c\
ft_putstr_fd.c\
ft_putendl_fd.c\
ft_putnbr_fd.c\
ft_lstnew.c\
ft_lstsize.c\
ft_lstadd_back.c\
ft_lstclear.c\
ft_lstlast.c


SRC_BONUS = ft_lstadd_front.c\
ft_lstdelone.c\
ft_lstiter.c\
ft_lstmap.c

CC = gcc
CFLAGES = -Wall -Wextra -Werror
AR = ar rcs
NAME = libft.a
OBJ = $(SRC:.c=.o)
OBJ_BONUS = $(SRC_BONUS:.c=.o)

all : $(NAME)

$(NAME) : $(OBJ)
	$(AR) $@ $(OBJ)

bonus : $(OBJ) $(OBJ_BONUS)
	$(AR) $(NAME) $(OBJ) $(OBJ_BONUS)

%.o:%.c
	$(CC) $(CFLAGES) -c $< -o $@

clean :
	rm -f *.o

fclean : clean
	rm -f $(NAME)

re : fclean all
