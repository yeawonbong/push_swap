/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sorting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybong <ybong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/21 03:06:48 by ybong             #+#    #+#             */
/*   Updated: 2021/06/21 05:39:09 by ybong            ###   ########.fr       */
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

void	sort_stacks(t_stack *stack, int tofind, int n)
{
	t_sorting	*tool;

	tool = malloc(sizeof(t_sorting));
	while (1 < stack->blen)
	{
		while (tofind && (stack->pivot[n] <= B_TOP \
		|| stack->pivot[n] <= B_BOTTOM))
		{
			tool->frombottom = B_BOTTOM < stack->pivot[n] ? -1 : 0;
			tool->fromtop = \
				search_fromtop(tool->fromtop, stack, tofind, n);
			tool->frombottom = \
				search_frombottom(tool->frombottom, stack, tofind, n);
			set_tools(tool);
			tofind = \
				find_tofind(tool->tempidx, stack, tofind, tool->till_tofind);
		}
		n--;
	}
	pa(stack);
}
