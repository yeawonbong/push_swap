#include "push_swap.h"

void	sort_arg(t_stack *stack, int size)
{
	int *arr;
	int	temp;
	int	i;

	i = 0;
	if (!(arr = malloc(sizeof(int) * size)))
		error_exit(stack);
	ft_memcpy(arr, stack->a, sizeof(int) * size);
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
	printf("{{{{{{{{{PRINT PIVOT: %d, %d, %d, %d\n", stack->pivot[0],stack->pivot[1],stack->pivot[2],stack->pivot[3]);
}

void	pb_if(char topb, t_stack *stack, int n)
{
	if (topb != NONE)
		totop_if(topb, stack, 'a');
	//-----pb 후처리----pivot보다 작으면 밑으로 보내
	pb(stack);
	printf("----pivot now is : %d\n", stack->pivot[n]);
	if (1 < stack->blen && B_TOP < stack->pivot[n])
		rb(stack);
}

void	move_to_stackb(t_stack *stack) //group1을 stack_b로 보냄
{
	int n;

	n = 2; 
	while (n < GROUPS)
	{
		while (!(n % 2) && stack->blen < PERGROUP * n)
		{
			if (A_TOP <= stack->pivot[n])
				pb_if(NONE, stack, n - 1);
			else
				ra(stack);
		}
		n++;
	}
	while (0 < stack->alen)
			pb_if(NONE, stack, PERGROUP / 2);
}

int		sort_stacks(t_stack *stack, int tofind)
{
	int 	tempidx;
	int		fromtop;
	int		frombottom;
	void 	(*till_tofind)(t_stack *stack);
	int		n;
	
	n = GROUPS - 1;
	while (0 <= n)
	{
		while (stack->pivot[n] <= B_TOP || stack->pivot[n] <= B_BOTTOM) // 해당 그룹이 stack->b에 남아있을 때까지
		{
			printf("{{{{{{{{{{{{{{{{{{{{{여기WHILE_____IN}}}}}}}}}}}}}}\n");
			fromtop = B_TOP < stack->pivot[n] ? -1 : 0;
			frombottom = B_BOTTOM < stack->pivot[n] ? -1 : 0;
			while (0 <= fromtop && stack->pivot[n] <= stack->b[fromtop] && fromtop < stack->blen) // TOP 탐색 tofind인덱스 찾기
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
			if (fromtop < 0 || frombottom < 0) // -1일 때 
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
				till_tofind(stack);
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
	}
	pa(stack);
	return (tofind);
}
