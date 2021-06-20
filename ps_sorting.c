/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sorting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybong <ybong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/21 03:06:48 by ybong             #+#    #+#             */
/*   Updated: 2021/06/21 04:23:43 by ybong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	set_pivot(t_stack *stack)
{
	int n;

	stack->pivot[0] = SORTED_TOP;
	n = 1;
	while (n < GROUPS)
	{
		stack->pivot[n] = stack->sorted_arr[(PERGROUP) * n];
		n++;
	}
}

void	div_in_half(char topb, t_stack *stack, int halfpivot)
{
	if (topb != NONE)
		totop_if(topb, stack, 'a');
	pb(stack);
	if (1 < stack->blen && B_TOP < halfpivot)
		rb(stack);
}

void	move_to_stackb(t_stack *stack)
{
	int	n;

	n = 2;
	while (n < GROUPS)
	{
		while ((n % 2) == 0 && stack->blen < PERGROUP * n)
		{
			if (A_TOP < stack->pivot[n])
				div_in_half(NONE, stack, stack->pivot[n - 1]);
			else
				ra(stack);
		}
		n++;
	}
	while (0 < stack->alen)
		div_in_half(NONE, stack, \
		stack->sorted_arr[stack->sortedlen - (PERGROUP / 2)]);
}

int		search_fromtop(int fromtop, t_stack *stack, int tofind, int n)
{
	if (B_TOP < stack->pivot[n])
		return (-1);
	while (stack->pivot[n] <= stack->b[fromtop])
	{
		if (stack->b[fromtop] == stack->sorted_arr[tofind])
			break ;
		else
			fromtop++;
	}
	return (fromtop);
}

int		search_frombottom(int frombottom, t_stack *stack, int tofind, int n)
{
	if (B_BOTTOM < stack->pivot[n])
		return (-1);
	while (stack->pivot[n] <= stack->b[stack->blen - 1 - frombottom])
	{
		if (stack->b[stack->blen - 1 - frombottom] == stack->sorted_arr[tofind])
			break ;
		else
			frombottom++;
	}
	return (frombottom);
}

int		find_tofind(int tempidx, t_stack *stack, int tofind, \
void (*till_tofind)(t_stack *stack))
{
	while (0 < tempidx--)
		till_tofind(stack);
	if (B_TOP == stack->sorted_arr[tofind])
	{
		pa(stack);
		tofind--;
	}
	return (tofind);
}

void	sort_stacks(t_stack *stack, int tofind, int n)
{
	int		fromtop;
	int		frombottom;
	int		tempidx;
	void	(*till_tofind)(t_stack *stack);

	while (1 < stack->blen)
	{
		while (tofind && (stack->pivot[n] <= B_TOP \
		|| stack->pivot[n] <= B_BOTTOM))
		{
			frombottom = B_BOTTOM < stack->pivot[n] ? -1 : 0;
			fromtop = search_fromtop(fromtop, stack, tofind, n);
			frombottom = search_frombottom(frombottom, stack, tofind, n);
			if (fromtop < 0 || frombottom < 0)
			{
				tempidx = frombottom < 0 ? fromtop : frombottom + 1;
				till_tofind = frombottom < 0 ? rb : rrb;
			}
			else
			{
				frombottom++;
				tempidx = fromtop <= frombottom ? fromtop : frombottom;
				till_tofind = fromtop <= frombottom ? rb : rrb;
			}
			fromtop = 0;
			frombottom = 0;
			tofind = find_tofind(tempidx, stack, tofind, till_tofind);
		}
		n--;
	}
	pa(stack);
}
