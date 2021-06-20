/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_pre_sorting.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybong <ybong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/21 04:59:29 by ybong             #+#    #+#             */
/*   Updated: 2021/06/21 05:55:27 by ybong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

void	set_tools(t_sorting *tool)
{
	if (tool->fromtop < 0 || tool->frombottom < 0)
	{
		tool->tempidx = tool->frombottom < 0 \
			? tool->fromtop : tool->frombottom + 1;
		tool->till_tofind = tool->frombottom < 0 ? rb : rrb;
	}
	else
	{
		tool->frombottom++;
		tool->tempidx = tool->fromtop <= tool->frombottom \
			? tool->fromtop : tool->frombottom;
		tool->till_tofind = tool->fromtop <= tool->frombottom ? rb : rrb;
	}
	tool->fromtop = 0;
	tool->frombottom = 0;
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
