/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sorting_prep.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybong <ybong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/21 03:06:48 by ybong             #+#    #+#             */
/*   Updated: 2021/06/21 21:43:38 by ybong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	set_pivot(t_stack *stack)
{
	int n;

	stack->pivot[0] = stack->sorted_arr[0];
	n = 1;
	while (n < GROUPS)
	{
		stack->pivot[n] = stack->sorted_arr[(stack->sortedlen / GROUPS) * n];
		n++;
	}
}

void	sort_arg(t_stack *stack, int size)
{
	int	*arr;
	int	temp;
	int	i;

	i = 0;
	if (!(arr = malloc(sizeof(int) * size)) || \
	!ft_memcpy(arr, stack->a, sizeof(int) * size))
		error_exit(stack);
	while (i < size - 1)
	{
		if (arr[i] > arr[i + 1])
		{
			temp = arr[i];
			arr[i] = arr[i + 1];
			arr[i + 1] = temp;
		}
		if (i == 0 || arr[i - 1] <= arr[i])
			i++;
		else
			i--;
	}
	stack->sorted_arr = arr;
	stack->sortedlen = stack->alen;
}

void	div_in_half(char topb, t_stack *stack, int halfpivot)
{
	if (topb != NONE)
		totop_if(topb, stack, 'a');
	pb(stack);
	if (1 < stack->blen && stack->b[0] < halfpivot)
		rb(stack);
}

void	move_to_stackb(t_stack *stack)
{
	int	n;

	n = 2;
	while (n < GROUPS)
	{
		while ((n % 2) == 0 && stack->blen < (stack->sortedlen / GROUPS) * n)
		{
			if (stack->a[0] < stack->pivot[n])
				div_in_half(NONE, stack, stack->pivot[n - 1]);
			else
				ra(stack);
		}
		n++;
	}
	while (0 < stack->alen)
		div_in_half(NONE, stack, \
		stack->sorted_arr[stack->sortedlen \
			- ((stack->sortedlen / GROUPS) / 2)]);
}
