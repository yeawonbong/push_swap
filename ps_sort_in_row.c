/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sort_in_row.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybong <ybong@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/12 06:12:50 by ybong             #+#    #+#             */
/*   Updated: 2021/06/12 06:12:50 by ybong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort(t_stack *stack)
{
	int i;

	i = stack->sortedlen - 3; //뒤에서 세번째부터 채우기 시작
	while (i)
	{
		if (B_TOP == SORTED_TOP)
			rb(stack);
		if (stack->b[0] == stack->sorted_arr[i] || stack->b[1] == stack->sorted_arr[i])
		{
			if (stack->b[1] == stack->sorted_arr[i])
				sb(stack);
			pa(stack);
			i--;
		}
		else
			tobottom_if(BIGGER, stack, 'b');
	}
	pa(stack); // sorted_arr[0], 즉 SORTED_TOP, 마지막 수만 남아있고, 이것을 pa
}
