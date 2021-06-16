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

// void	sort(t_stack *stack)
// {
// 	int i;
// 	int	temp;

// 	temp = 0;
// 	i = stack->sortedlen - 3; //뒤에서 세번째부터 채우기 시작
// 	while (i)
// 	{
// 		if (1 < stack->blen && B_TOP == SORTED_TOP)
// 			rb(stack);
// 		while ((stack->a[stack->alen - 1 - temp] != SORTED_BOTTOM) //A 밑의 temp group 탐색
// 		{
// 			if (stack->a[stack->alen - 1 - temp] == stack->sorted_arr[i]) //A_BOTTOM부터 탐색
// 			{
// 				while (temp--)
// 					rra(stack);
// 				pb(stack);
// 				while (A_TOP != stack->sorted_arr[i + 1]) //마지막으로 채운 sorted arr
// 					ra(stack);
// 				pa(stack);
// 				i--;
// 				break ;
// 			}
// 			temp++;
// 		}
	
// 		}
// 		else if (stack->b[0] == stack->sorted_arr[i] || stack->b[1] == stack->sorted_arr[i])
// 		{ // B TOP 2에 해당 수사가 있을 때 
// 			if (stack->b[1] == stack->sorted_arr[i])
// 				sb(stack);
// 			pa(stack);
// 			i--;
// 		}
// 		else
// 		{
// 			totop_if(BIGGER, stack, 'b');
// 			pa(stack);
// 			ra(stack);////////////////// 네 숫자에 없으면, A밑으로 보내 - 카운트
// 		}
// 	}
// 	pa(stack); // sorted_arr[0], 즉 SORTED_TOP, 마지막 수만 남아있고, 이것을 pa
// }

// void	sort(t_stack *stack)
// {
// 	int tofind;
// 	int	tempgroup;

// 	tempgroup = 0;
// 	tofind = stack->sortedlen - 3; //뒤에서 세번째부터 채우기 시작
// 	while (tofind)
// 	{
// 		if (1 < stack->blen && B_TOP == SORTED_TOP)
// 			rb(stack);
// 		if (stack->b[0] == stack->sorted_arr[tofind] || stack->b[1] == stack->sorted_arr[tofind])
// 		{ // B TOP 2에 해당 숫자가 있을 때 
// 			if (stack->b[1] == stack->sorted_arr[tofind])
// 				sb(stack);
// 			pa(stack);
// 			tofind--;
// 		}
// 		else
// 		{
// 			while ((stack->a[stack->alen - 1 - tempgroup] != SORTED_BOTTOM) //A 밑의 tempgroup group 탐색
// 			{
// 				if (stack->a[stack->alen - 1 - tempgroup] == stack->sorted_arr[tofind]) //A_BOTTOM부터 탐색
// 				{
// 					while (tempgroup--)
// 						rra(stack);
// 					pb(stack);
// 					while (A_TOP != stack->sorted_arr[tofind + 1]) //마지막으로 채운 sorted arr
// 						ra(stack);
// 					pa(stack);
// 					tofind--;
// 					break ;
// 				}
// 				tempgroup++;
// 			}
// 		}
// 		else
// 		{
// 			totop_if(BIGGER, stack, 'b');
// 			pa(stack);
// 			ra(stack);////////////////// 네 숫자에 없으면, A밑으로 보내 - 카운트
// 		}
// 	}
// 	pa(stack); // sorted_arr[0], 즉 SORTED_TOP, 마지막 수만 남아있고, 이것을 pa
// }

// void	search_temp_group(t_stack stack, int tempgroup, int tofind)
// {
// 	// while ((stack->a[stack->alen - 1 - tempgroup] != SORTED_BOTTOM) //A 밑의 tempgroup group 탐색
// 	// {
// 	// 	if (stack->a[stack->alen - 1 - tempgroup] == stack->sorted_arr[tofind]) //A_BOTTOM부터 탐색
// 	// 	{
// 	// 		while (tempgroup--)
// 	// 			rra(stack);
// 	// 		pb(stack);
// 	// 		while (A_TOP != stack->sorted_arr[tofind + 1]) //마지막으로 채운 sorted arr
// 	// 			ra(stack);
// 	// 		pa(stack);
// 	// 		tofind--;
// 	// 		break ;
// 	// 	}
// 	// 	tempgroup++;
// 	// }
// /*수정후*/
// 	while ()

// }

int		search_from_top(t_stack *stack, int n, int tofind)
{
	int tempidx;
	int		fromtop;
	int		frombottom;
	void 	(*till_tofind)(t_stack *stack);

	fromtop = -1;
	frombottom = -1;
	while (0 <= n)
	{
		while (stack->pivot[n] <= B_TOP || stack->pivot[n] <= B_BOTTOM) // 해당 그룹이 stack->b에 남아있을 때까지
		{
			printf("{{{{{{{{{{{{{{{{{{{{{여기WHILE_____IN}}}}}}}}}}}}}}\n");

			while (stack->pivot[n] <= stack->b[fromtop]) // TOP 탐색 tofind인덱스 찾기
			{printf("{{{{{{{{{{{{{{{{{{{{{TOP_____IN}}}}}}}}}}}}}}\n");
				if (stack->b[fromtop] == stack->sorted_arr[tofind])
				{printf("TOP찾았다찾았다\n");
					break ;
				}
				else{
					fromtop++; printf("fromtop ++ ing in TOP :: %d\n", fromtop);
				}
			}
			while (stack->pivot[n] <= stack->b[stack->blen - 1 - frombottom]) // B_BOTTOM 탐색
			{printf("{{{{{{{{{{{{{{{{{{{{{BOTTOM_____IN}}}}}}}}}}}}}}\n");
				if (stack->b[stack->blen - 1 - frombottom] == stack->sorted_arr[tofind]) //B_BOTTOM부터 탐색
				{printf("BOTTOM찾았다찾았다\n");
					break;
				}
				else{
					frombottom++; printf("frombottom ++ ing in BOTTOM :: %d\n", frombottom);
				}
			}
			printf("-----TOP AND BOTTOM IDX : %d AND %d\n" ,fromtop, frombottom);
			if (0 < fromtop && 0 <frombottom)
			{
				frombottom++;
				tempidx = fromtop <= frombottom ? fromtop : frombottom;
				till_tofind = fromtop <= frombottom ? rb : rrb;
			}
			else
			{
				tempidx = frombottom == -1 ? fromtop : frombottom + 1;
				till_tofind = frombottom == -1 ? rb : rrb;

			}
			fromtop = -1;
			frombottom = -1;
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

// int		search_from_bottom(t_stack *stack, int n, int tofind)
// {
// 	int tempidx;

// 	tempidx = 0;
// 	while (stack->pivot[n] <= B_TOP || stack->pivot[n] <= B_BOTTOM) // 해당 그룹이 stack->b에 남아있을 때까지
// 	{
// 		if (B_BOTTOM == stack->sorted_arr[tofind] || stack->b[stack->blen - 2] == stack->sorted_arr[tofind])
// 		{
// 			rrb(stack);
// 			if (B_BOTTOM == stack->sorted_arr[tofind])
// 				rrb(stack);
// 			pa(stack);
// 			tofind--;
// 		}
// 		else if (stack->pivot[n] <= B_TOP)
// 		{
// 			while (stack->pivot[n] <= stack->b[tempidx]) // TOP부터 tempgroup 탐색
// 			{
// 				if (stack->b[tempidx] == stack->sorted_arr[tofind]) //B_BOTTOM부터 탐색
// 				{
// 					while (tempidx--)
// 						rb(stack);
// 					pa(stack);
// 					tofind--;
// 					tempidx = 0;
// 					return (tofind);
// 				}
// 				tempidx++;
// 			}
// 		}
// 		else
// 			rrb(stack);
// 	}
// 	return (tofind);
// }

// void	sort_stack(t_stack *stack)
// {
// 	int tofind;
// 	int n;

// 	tofind = stack->sortedlen - 3;
// 	n = 3;
// 	while (0 <= n) //조건 다른 거 줘도 됨 
// 	{
// 		tofind = search_from_top(stack, n, tofind);
// 	}
// 	pa(stack);
// }