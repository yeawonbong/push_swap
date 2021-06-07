#ifndef __PUSH_SWAP_H__
# define __PUSH_SWAP_H__

#include <stdio.h>

#include "./libft_ps/libft.h"
#include <stdlib.h>
#include <stdarg.h>
#include <unistd.h>

# define ERROR 	0;

// typedef struct	s_stack
// {
// 	t_list		**a;
// 	t_list		**b;
// }				t_stack;


// typedef struct			s_list
// {
// 	struct s_list		*next;
// 	int					*content;
// 	int					size;
// }						t_list;


int   		push_swap(int argc, char *argv[]);
t_list		*get_arg(int argc, char *argv[]);
char		**ft_split(char const *s, char c);


// typedef struct	t_arr
// {
// 	int			*arr[MAX];
// 	int			top;
// 	int			bottom;
// }				s_arr;


# endif