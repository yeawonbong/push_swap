/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybong <ybong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/21 21:23:21 by ybong             #+#    #+#             */
/*   Updated: 2021/06/22 23:48:09 by ybong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "./libft_ps/libft.h"
# include <stdlib.h>
# include <stdarg.h>
# include <unistd.h>

# define ERROR 0
# define SMALLER 's'
# define BIGGER 'b'
# define NONE 'n'

typedef struct	s_stack
{
	int		*a;
	int		*b;
	int		alen;
	int		blen;
	int		*sorted_arr;
	int		sortedlen;
	int		groups;
	int		*pivot;
}				t_stack;

typedef struct	s_sorting
{
	int		fromtop;
	int		frombottom;
	int		tempidx;
	void	(*till_tofind)(t_stack *stack);
}				t_sorting;

/*
** ps_get_arg.c
*/
void			duplicates(t_stack *stack);
void			non_int(char **temp, int j);
void			atoi_error(int atoied, char *temp);
int				cmp_arr(t_stack *stack);
void			get_arg(int argc, char *argv[], t_stack *stack);

/*
**	push_swap.c
*/
void			free_all(t_stack *stack);
void			error_exit();
void			push_swap(t_stack *stack);
int				main(int argc, char *argv[]);

/*
** ps_stack_tools.c
*/
int				*add_front(int *arr, int len, int new);
int				*add_back(int *arr, int len, int new);
int				*del_front(int *arr, int len);
void			totop_if(char toswap, t_stack *stack, char stacknum);
void			tobottom_if(char tobottom, t_stack *stack, char stacknum);

/*
** ps_sorting_prep.c
*/
void			set_pivot(t_stack *stack);
void			sort_arg(t_stack *stack, int size);
void			div_in_half(char topb, t_stack *stack, int halfpivot);
void			move_to_stackb(t_stack *stack);

/*
**	ps_sorting_small.c
*/
void			sort_five(t_stack *stack, int n);
void			sort_three(t_stack *stack);
void			sort_small_args(t_stack *stack);

/*
**	ps_sorting_stacks.c
*/
int				search_fromtop(int fromtop, t_stack *stack, int tofind, int n);
int				search_frombottom(int frombottom, t_stack *stack, \
					int tofind, int n);
int				find_tofind(int tempidx, t_stack *stack, int tofind, \
					void (*till_tofind)(t_stack *stack));
void			set_tools(t_sorting *tool);
void			sort_stacks(t_stack *stack, int tofind, int n);

/*
** push_swap_functions (push, swap, rotate)
*/
void			pa(t_stack *stack);
void			pb(t_stack *stack);

void			sa(t_stack *stack);
void			sb(t_stack *stack);
void			ss(t_stack *stack);

void			ra(t_stack *stack);
void			rb(t_stack *stack);
void			rr(t_stack *stack);
void			rra(t_stack *stack);
void			rrb(t_stack *stack);
void			rrr(t_stack *stack);

#endif
