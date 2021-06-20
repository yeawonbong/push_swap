/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sorting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybong <ybong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/21 03:06:48 by ybong             #+#    #+#             */
/*   Updated: 2021/06/21 03:07:58 by ybong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_stack *stack)
{
	if (A_TOP == SORTED_BOTTOM)
		ra(stack);
	else if (stack->a[1] == SORTED_BOTTOM)
		rra(stack);
	totop_if(SMALLER, stack, 'a');	
}

void	sort_five(t_stack *stack, int n)
{
	while (3 < stack->alen)
	{
		if (A_TOP == stack->sorted_arr[n] || stack->a[1] == stack->sorted_arr[n]\
		|| A_TOP == stack->sorted_arr[n + 1] || stack->a[1] == stack->sorted_arr[n + 1])
		{
			totop_if(SMALLER, stack, 'a');
			pb(stack);
		}
		else
			ra(stack);					
	}
	totop_if(BIGGER, stack, 'b');
	sort_three(stack);
	pa(stack);
	pa(stack);
}

void	sort_small_args(t_stack *stack)
{
	int pivot;

	if (stack->sortedlen < 3)
		error_exit(stack);
	if (stack->sortedlen == 3)
		sort_three(stack);
	else
	{
		pivot = stack->sortedlen - GROUPS;
		while (GROUPS < stack->alen)
		{
			if (A_TOP < stack->sorted_arr[pivot])
				pb(stack);
			else
				ra(stack);
		}
		sort_five(stack, pivot);
		pivot--;
		while (stack->blen)
		{
			if (B_TOP == stack->sorted_arr[pivot])
			{
				pa(stack);
				pivot--;
			}
			else
				rb(stack);
		}
	}
}

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
		div_in_half(NONE, stack, stack->sorted_arr[stack->sortedlen - (PERGROUP / 2)]);
}

// int		find_tofind(t_stack *stack, int fromtop, int frombottom, int tofind)
// {
// 	int 	tempidx;
// 	void	(*till_tofind)(t_stack *stack);

// 	if (fromtop < 0 || frombottom < 0) // -1일 때 
// 	{
// 		tempidx = frombottom < 0 ? fromtop : frombottom + 1;
// 		till_tofind = frombottom < 0 ? rb : rrb;
// 	}
// 	else
// 	{
// 		frombottom++;
// 		tempidx = fromtop < frombottom ? fromtop : frombottom;
// 		till_tofind = fromtop < frombottom ? rb : rrb;
// 	}
// 	while (0 < tempidx--)
// 		till_tofind(stack);
// 	if (B_TOP == stack->sorted_arr[tofind])
// 	{
// 		pa(stack);
// 		tofind--;
// 	}
// 	return (tofind);
// }

void		sort_stacks(t_stack *stack, int tofind, int n)
{
	int		fromtop;
	int		frombottom;
	int 	tempidx;
	void	(*till_tofind)(t_stack *stack);

	while (1 < stack->blen)
	{
		while (tofind &&(stack->pivot[n] <= B_TOP || stack->pivot[n] <= B_BOTTOM))
		{
			fromtop = B_TOP < stack->pivot[n] ? -1 : 0;
			frombottom = B_BOTTOM < stack->pivot[n] ? -1 : 0;
			printf("자 TOFIND 시작한다 %d--%d\n", tofind, stack->sorted_arr[tofind]);
			while (0 <= fromtop && stack->pivot[n] <= stack->b[fromtop])
			{
				if (stack->b[fromtop] == stack->sorted_arr[tofind])
					break ;
				else
					fromtop++;
			}
			while (0 <= frombottom && stack->pivot[n] <= stack->b[stack->blen - 1 - frombottom])
			{
				if (stack->b[stack->blen - 1 - frombottom] == stack->sorted_arr[tofind])
					break ;
				else
					frombottom++;
				if (0 <= fromtop && fromtop < frombottom)
					break ;
			}
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
			while (0 < tempidx--)
			{
				till_tofind(stack);
				printf("처리중 tempidx-- %d\n", tempidx);
			}
			printf("TOFIND는 %d인데\nBTOP 뭔데 %d\n", stack->sorted_arr[tofind], B_TOP);
			if (B_TOP == stack->sorted_arr[tofind])
			{
				pa(stack);
				printf("PA한 숫자 %d\n", A_TOP);
				tofind--;
			}
			if (tofind == 0)
				break ;
		}
		n--;
	}
	pa(stack);
}
