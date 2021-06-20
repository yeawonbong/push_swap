/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sorting_prep.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybong <ybong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/21 03:06:48 by ybong             #+#    #+#             */
/*   Updated: 2021/06/21 05:56:21 by ybong            ###   ########.fr       */
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
