#include "push_swap.h"

void	set_pivot(t_stack *stack)
{
	int n;

	stack->pivot[0] = SORTED_TOP;
	n = 1;
	while (n < 4)
	{
		stack->pivot[n] = stack->sorted_arr[(stack->sortedlen / 4) * n];
		n++;
	}
	printf("{{{{{{{{{PRINT PIVOT: %d, %d, %d, %d\n", stack->pivot[0],stack->pivot[1],stack->pivot[2],stack->pivot[3]);
}

// void	post_pb(t_stack *stack, int n) 
// {
// 	//-----pb 후처리----pivot보다 작으면 밑으로 보내고, top2 더 큰 수가 위에 있도록
// 		pb(stack);
// 		printf("----pivot now is : %d\n", stack->pivot[n]);
// 		if (1 < stack->blen && B_TOP < stack->pivot[n])
// 			rb(stack);
// 		totop_if(BIGGER, stack, 'b');
// }

void	pb_if(char topb, t_stack *stack, int n)
{
	if (topb != NONE)
		totop_if(topb, stack, 'a');
									// post_pb(stack, n);
	//-----pb 후처리----pivot보다 작으면 밑으로 보내고, top2 더 큰 수가 위에 있도록
	pb(stack);
	printf("----pivot now is : %d\n", stack->pivot[n]);
	if (1 < stack->blen && B_TOP < stack->pivot[n])
		rb(stack);
	totop_if(BIGGER, stack, 'b');
}

void	group1_to_stackb(t_stack *stack) //group1을 stack_b로 보냄
{
	int n;

	n = 0;
	while (stack->blen < HALF)
	{
		if (stack->a[0] < HALF || stack->a[1] < HALF)
		{
			if (!(stack->a[0] < HALF && stack->a[1] < HALF)) // 둘 다 group1 아니면, 더 작은 수 - less than HALF해당하는 수를 b로 보내
				pb_if(SMALLER, stack, n);
				// totop_if(SMALLER, stack, 'a');
			else
				pb_if(NONE, stack, n);
		}
		else
			tobottom_if(SMALLER, stack, 'a'); // 더 작은 수를 to bottom
	}
}

void	group2_to_stackb(t_stack *stack)
{
	int n;

	n = 2; //75
	while (2 < stack->alen)
	{
		// if ((stack->a[0] == SORTED_BOTTOM || stack->a[1] == SORTED_BOTTOM)) // SORTED_BOTTOM 있으면 아닌 수로 처리
		// {
		// 	totop_if(SMALLER, stack, 'a');
		// 	if (A_BOTTOM < A_TOP)
		// 		ra(stack);
		// 	else
		// 		post_pb(stack, n);
		// }
		// if (stack->pivot[n] < stack->a[0] || stack->pivot[n] < stack->a[1]) //3번째 그룹 (50~75)
		// {
		// 	if (stack->pivot[n] < stack->a[0] && stack->pivot[n] < stack->a[1])
		// 		pb_if(SMALLER, stack, 'a');
		// 	else //하나만 클 경우
		// 		pb_if(BIGGER, stack, 'a');
		// }
		// else
		// 	pb_if(BIGGER, stack, n);

		if (A_TOP == SORTED_BOTTOM || A_TOP == stack->sorted_arr[stack->sortedlen - 2])
			ra(stack);
		else
			pb_if(NONE, stack, n);

	}
	totop_if(SMALLER, stack, 'a');
}
