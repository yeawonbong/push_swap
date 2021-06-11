#ifndef __PUSH_SWAP_H__
# define __PUSH_SWAP_H__

#include <stdio.h>

#include "./libft_ps/libft.h"
#include <stdlib.h>
#include <stdarg.h>
#include <unistd.h>

# define ERROR 	0
# define A_TOP stack->a[0]
# define B_TOP stack->b[0]
# define A_BOTTOM stack->a[stack->alen - 1]
# define B_BOTTOM stack->b[stack->blen - 1]

# define PIVOT stack->sorted_arr[stack->sortedlen / 2] //가운데 숫자 (group 나누는 기준)

# define A_TOPTWO 

# define SMALLER 's'
# define BIGGER 'b'

typedef struct			s_stack
{
	int	*a;
	int	*b;
	int	alen;
	int	blen;
	int	*sorted_arr;
	int sortedlen;
}						t_stack;


int		push_swap(t_stack *stack);
t_stack	*get_arg(int argc, char *argv[], t_stack *stack);
void	free_all(t_stack *stack);
void	error_exit(t_stack *stack);

int		*add_back(int *arr, int len, int new);
int		*add_front(int *arr, int len, int new);
int		*del_front(int *arr, int len);

void	group1_to_stackb(t_stack *stack);

void	a_to_b_if(char to_b, t_stack *stack);
void    totop_if(char toswap, t_stack *stack, char stacknum);
void	tobottom_if(char tobottom, t_stack *stack, char stacknum);


/*
** push_swap_functions
*/
void	pa(t_stack *stack);
void	pb(t_stack *stack);

void 	sa(t_stack *stack);
void	sb(t_stack *stack);
void	ss(t_stack *stack);

void    ra(t_stack *stack);
void    rb(t_stack *stack);
void	rr(t_stack *stack);
void    rra(t_stack *stack);
void	rrb(t_stack *stack);
void	rrr(t_stack *stack);




# endif