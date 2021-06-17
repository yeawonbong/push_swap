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

int		search_from_top(t_stack *stack, int n, int tofind)
{
	int tempidx;
	int		fromtop;
	int		frombottom;
	void 	(*till_tofind)(t_stack *stack);

	while (0 <= n)
	{
		while (stack->pivot[n] <= B_TOP || stack->pivot[n] <= B_BOTTOM) // 해당 그룹이 stack->b에 남아있을 때까지
		{
			printf("{{{{{{{{{{{{{{{{{{{{{여기WHILE_____IN}}}}}}}}}}}}}}\n");
			fromtop = B_TOP < stack->pivot[n] ? -1 : 0;
			frombottom = B_BOTTOM < stack->pivot[n] ? -1 : 0;
			while (0 <= fromtop && stack->pivot[n] <= stack->b[fromtop] && fromtop < stack->alen) // TOP 탐색 tofind인덱스 찾기
			{printf("{{{{{{{{{{{{{{{{{{{{{TOP_____IN}}}}}}}}}}}}}}\n");
				if (stack->b[fromtop] == stack->sorted_arr[tofind])
				{printf("TOP찾았다찾았다\n");
					break ;
				}
				else{
					fromtop++; printf("fromtop ++ ing in TOP :: %d\n", fromtop);
				}
			}
			while (0 <= frombottom && stack->pivot[n] <= stack->b[stack->blen - 1 - frombottom] && fromtop < stack->blen) // B_BOTTOM 탐색
			{printf("{{{{{{{{{{{{{{{{{{{{{BOTTOM_____IN}}}}}}}}}}}}}}\n");
				if (stack->b[stack->blen - 1 - frombottom] == stack->sorted_arr[tofind]) //B_BOTTOM부터 탐색
				{printf("BOTTOM찾았다찾았다\n");
					break;
				}
				else{
					frombottom++; printf("frombottom ++ ing in BOTTOM :: %d\n", frombottom);
				}
				if (0 <= fromtop && fromtop < frombottom)
					break; //더 빨리 뽑으려고.. 
			}
			printf("-----TOP AND BOTTOM IDX : %d AND %d\n" ,fromtop, frombottom);
			if (fromtop < 0 || frombottom < 0)
			{
				tempidx = frombottom < 0 ? fromtop : frombottom + 1;
				till_tofind = frombottom < 0 ? rb : rrb;
			}
			else
			{
				frombottom++;
				tempidx = fromtop < frombottom ? fromtop : frombottom;
				till_tofind = fromtop < frombottom ? rb : rrb;
			}
			fromtop = 0;
			frombottom = 0;
			while (0 < tempidx--)
			{
				till_tofind(stack);
				// printf("TEMPIDX IS : %d\n", tempidx);
			}
			printf("지금 B_TOP은 %d\n", B_TOP);
			if (B_TOP == stack->sorted_arr[tofind])
			{
				pa(stack);
				printf("pa한 숫자는 : %d\n", A_TOP);
				tofind--; printf("TO FIND -- : %d\n", stack->sorted_arr[tofind]);
			}
			if (!tofind)
				break ;
		}
		n--; 
			// if (1)
			// {
			// 	printf("NNNNNNNNNNNNNNNNNNN (PIVOT) IDX IS : %d\n", n);
			// 	printf("NNNNNNNNNNNNNNNNNNN (PIVOT) NUM IS : %d\n", stack->pivot[n]);

			// 	printf("^^^^^^^^^^stack a^^^^^^^ㅣ\n");
			// 	for(int z = 0; z < (stack->alen); z++)
			// 		printf("stack a의 %d번째 숫자: %d\n", z, (stack->a)[z]);
			// 	printf("vvvvvvvvvvstack avvvvvvvv\n\n");

			// 	printf("^^^^^^^^^^stack b^^^^^^^ㅣ\n");
			// 	for(int z = 0; z < (stack->blen); z++)
			// 		printf("stack b의 %d번째 숫자: %d\n", z, (stack->b)[z]);
			// 	printf("vvvvvvvvvvstack bvvvvvvvv\n\n");
			// }
	}
	pa(stack);
	return (tofind);
}

