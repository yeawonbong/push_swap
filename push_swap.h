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

# define SORTED_TOP stack->sorted_arr[0]
# define SORTED_BOTTOM stack->sorted_arr[stack->sortedlen - 1]
# define HALF stack->sortedlen / 2



# define SMALLER 's'
# define BIGGER 'b'
# define NONE 'n'
# define FROM_TOP 0
# define FROM_BOTTOM 1

typedef struct			s_stack
{
	int	*a;
	int	*b;
	int	alen;
	int	blen;
	int	*sorted_arr;
	int sortedlen;
	int	pivot[4];
	int count;
}						t_stack;


int		push_swap(t_stack *stack);
t_stack	*get_arg(int argc, char *argv[], t_stack *stack);
void	free_all(t_stack *stack);
void	error_exit(t_stack *stack);

int		*add_back(int *arr, int len, int new);
int		*add_front(int *arr, int len, int new);
int		*del_front(int *arr, int len);


void    totop_if(char toswap, t_stack *stack, char stacknum);
void	tobottom_if(char tobottom, t_stack *stack, char stacknum);
/*
** ps_grouping.c
*/
void	set_pivot(t_stack *stack);
void	post_pb(t_stack *stack, int n);
void	move_to_stackb(t_stack *stack);



/*
** ps_sort_in_row.c
*/
int		search_from_top(t_stack *stack, int n, int tofind);
int		search_from_bottom(t_stack *stack, int n, int tofind);
void	sort_stack(t_stack *stack);

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