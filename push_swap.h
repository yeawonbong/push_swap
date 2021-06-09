#ifndef __PUSH_SWAP_H__
# define __PUSH_SWAP_H__

#include <stdio.h>

#include "./libft_ps/libft.h"
#include <stdlib.h>
#include <stdarg.h>
#include <unistd.h>

# define ERROR 	0



typedef struct			s_stack
{
	int	*a;
	int alen;
	int	*b;
	int blen;
}						t_stack;


int   		push_swap(int argc, char *argv[]);
t_stack		*get_arg(int argc, char *argv[], t_stack *stack);
char		**ft_split(char const *s, char c);
void    	free_all(t_stack *stack);
t_list		*pa(t_list *stack_a, t_list *stack_b);
t_stack		*add_back(t_stack *stack, int new);


// typedef struct	t_arr
// {
// 	int			*arr[MAX];
// 	int			top;
// 	int			bottom;
// }				s_arr;


# endif