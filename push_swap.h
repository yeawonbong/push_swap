#ifndef __PUSH_SWAP_H__
# define __PUSH_SWAP_H__

#include <stdio.h>

#include "./libft_ps/libft.h"
#include <stdlib.h>
#include <stdarg.h>
#include <unistd.h>

# define ERROR 	0
# define A_BOTTOM stack->a[stack->alen - 1]
# define B_BOTTOM stack->b[stack->blen - 1]



typedef struct			s_stack
{
	int	*a;
	int	*b;
	int alen;
	int blen;
}						t_stack;


int   	push_swap(int argc, char *argv[]);
t_stack	*get_arg(int argc, char *argv[], t_stack *stack);
void    free_all(t_stack *stack);
void    error_exit(t_stack *stack);

int		*add_back(int *arr, int len, int new);
int		*add_front(int *arr, int len, int new);
int		*del_front(int *arr, int len);

void	pa(t_stack *stack);
void	pb(t_stack *stack);

void 	sa(t_stack *stack);
void	sb(t_stack *stack);
void	ss(t_stack *stack);

void    ra(t_stack *stack);
void    rb(t_stack *stack);
void	rr(t_stack *stack);
void    rra(t_stack *stack);
void    rrb(t_stack *stack);
void	rrr(t_stack *stack);




# endif