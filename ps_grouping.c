#include "push_swap.h"

void	set_pivot(t_stack *stack)
{
	int n;

	n = 0;
	while (n < 3)
	{
		stack->pivot[n] = stack->sorted_arr[(stack->sortedlen / 4) * (n + 1)];
		n++;
	}
}

void	post_pb(t_stack *stack, int n) 
{
	//-----pb 후처리----bottom보다 작으면 밑으로 보내고, top2 더 큰 수가 위에 있도록
		pb(stack);
		if (1 < stack->blen && B_TOP < stack->pivot[n])
			rb(stack);
		totop_if(BIGGER, stack, 'b');
}

void	pb_if(char topb, t_stack *stack, int n)
{
	totop_if(topb, stack, 'a');
	post_pb(stack);
}

void	group1_to_stackb(t_stack *stack) //group1을 stack_b로 보냄
{
	int n;

	n = 0;
	while (stack->blen < stack->sortedlen / 2)
	{
		// if ((stack->a[0] == SORTED_TOP || stack->a[1] == SORTED_TOP) && stack->blen < stack->blen / 4) // SORTED_TOP 있으면 아닌 수로 처리
		// {
		// 	totop_if(BIGGER, stack, 'a');
		// 	if (A_TOP < stack->pivot[n]) //해당이면 pb
		// 		post_pb(stack);
		// 	else
		// 		ra(stack);
		// }  //더 줄이려거든 추가하기. -- 정확히 똑같네. 지울것임
		if (stack->a[0] < HALF || stack->a[1] < HALF)
		{
			if (stack->a[0] < HALF && stack->a[1] < HALF ) // 둘 다 group1 이면, 더 큰 수를 위로 보내
				pb_if(BIGGER, stack);
			else//하나만 해당인 경우
				pb_if(SMALLER, stack); // 더 작은 수 (group1)
		}
		else
			tobottom_if(SMALLER, stack, 'a'); // 더 작은 수를 to bottom
	}
}

void	group2_to_stackb(t_stack *stack)
{
	while (2 < stack->alen)
	{
		if ((stack->a[0] == SORTED_BOTTOM || stack->a[1] == SORTED_BOTTOM)) // SORTED_BOTTOM 있으면 아닌 수로 처리
		{
			totop_if(SMALLER, stack, 'a');
			if (A_BOTTOM < A_TOP)
				ra(stack);
			else
				post_pb(stack);
		}
		else if (A_BOTTOM < stack->a[0] || A_BOTTOM < stack->a[1])
		{
			if (A_BOTTOM < stack->a[0] && A_BOTTOM < stack->a[1])
				tobottom_if(SMALLER, stack, 'a');
			else //하나만 클 경우
				tobottom_if(BIGGER, stack, 'a');
		}
		else
			pb_if(BIGGER, stack);
	}
	totop_if(SMALLER, stack, 'a');
}