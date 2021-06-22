/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sorting_small.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybong <ybong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/21 03:10:20 by ybong             #+#    #+#             */
/*   Updated: 2021/06/22 19:00:22 by ybong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_stack *stack)
{
	if (stack->sortedlen < 3)
	{
		totop_if(SMALLER, stack, 'a');
		free_all(stack);
		exit(EXIT_SUCCESS);
	}
	if (stack->a[0] == stack->sorted_arr[stack->sortedlen - 1])
		ra(stack);
	else if (stack->a[1] == stack->sorted_arr[stack->sortedlen - 1])
		rra(stack);
	totop_if(SMALLER, stack, 'a');
}

void	sort_five(t_stack *stack, int n)
{
	while (3 < stack->alen)
	{
		if (stack->a[0] == stack->sorted_arr[n]\
		|| stack->a[1] == stack->sorted_arr[n]\
		|| stack->a[0] == stack->sorted_arr[n + 1]\
		|| stack->a[1] == stack->sorted_arr[n + 1])
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

	pivot = stack->sortedlen - stack->groups;
	while (stack->groups < stack->alen)
	{
		if (stack->a[0] < stack->sorted_arr[pivot])
			pb(stack);
		else
			ra(stack);
	}
	sort_five(stack, pivot);
	pivot--;
	while (stack->blen)
	{
		if (stack->b[0] == stack->sorted_arr[pivot])
		{
			pa(stack);
			pivot--;
		}
		else
			rb(stack);
	}
}
