#ifndef __PUSH_SWAP_H__
# define __PUSH_SWAP_H__

#include <stdio.h>
#include <stdlib.h>

#include <stdarg.h>
#include <unistd.h>

// typedef struct	s_stack
// {
// 	t_list		**a;
// 	t_list		**b;
// }				t_stack;

#define ERROR 	0;

typedef struct			s_list
{
	struct s_list		*next;
	int					content;
	int					size;
}						t_list;


void	ft_lstadd_back(t_list **lst, t_list *new);
t_list	*ft_lstnew(int content);
int		ft_lstsize(t_list *lst);
int   push_swap(int argc, char *argv[]);
t_list		*get_arg(int argc, char *argv[]);
char		**ft_split(char const *s, char c);


// typedef struct	t_arr
// {
// 	int			*arr[MAX];
// 	int			top;
// 	int			bottom;
// }				s_arr;


# endif