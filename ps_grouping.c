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

// void	temptest(t_stack *stack)
// {
// 	int		fromtop;
// 	int		frombottom;
// 	int 	tempidx;
// 	void 	(*ft)(t_stack *stack);

// 	while (stack->blen < HALF)
// 	{
// 		fromtop = 0;
// 		frombottom = 0;
// 		while (!(stack->a[frombottom] < HALF))
// 			fromtop++;
// 		while (!(stack->a[stack->alen - 1 - frombottom] < HALF))
// 			frombottom++;

// 		frombottom++;
// 		tempidx = fromtop < frombottom ? fromtop : frombottom;
// 		ft = fromtop < frombottom ? rb : rrb;
// 		while (0 < tempidx--)
// 			ft(stack);
// 		pb_if(NONE, stack, 1);
// 		printf("pb한 숫자는 : %d\n", B_TOP);
		
// 	}
// }



void	move_to_stackb(t_stack *stack) //group1을 stack_b로 보냄
{
	int n;

	n = 1; // 25
	while (stack->blen < HALF)
	{
		if (A_TOP < HALF)
			pb_if(NONE, stack, n);
		else
			tobottom_if(NONE, stack, 'a');
	}
	n = 3; // 75
	while (2 < stack->alen)
	{
		if (A_TOP == SORTED_BOTTOM || A_TOP == stack->sorted_arr[stack->sortedlen - 2])
			ra(stack);
		else
			pb_if(NONE, stack, n);
	}
	totop_if(SMALLER, stack, 'a'); //sort 완료 후 마지막 두 수 세팅
}
