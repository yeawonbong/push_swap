#include "push_swap.h"

void    free_all(t_stack *stack)
{
	free(stack->a);
	free(stack->b);
	free(stack);
}

void    error_exit(t_stack *stack)
{
	free_all(stack);
	write(1, "Error\n", 6);
	exit(EXIT_FAILURE);
}

void	a_to_b_if(char to_b, t_stack *stack)
{
		if (stack->a[0] < PIVOT && stack->a[1] < PIVOT)
			totop_if(to_b, stack, 'a'); // 더 큰 수를 위로 보내
		else //하나만 group 1인 경우
			totop_if(SMALLER, stack, 'a'); // 더 작은 수 (group1)
		pb(stack);
		//-----pb 후처리----bottom보다 작으면 밑으로 보내고, top2 더 큰 수가 위에 있도록
		if (2 <= stack->blen && B_TOP < B_BOTTOM) 
			rb(stack);
		totop_if(BIGGER, stack, 'b');
}

void    totop_if(char toswap, t_stack *stack, char stacknum)
{
	int		**st;
	void 	(*swap)(t_stack *stack);

	st = stacknum == 'a' ? &stack->a : &stack->b;
	swap = stacknum == 'a' ? sa : sb;

	if (BIGGER == toswap && (*st)[0] < (*st)[1])
		swap(stack);
	if (SMALLER == toswap && (*st)[0] > (*st)[1])
		swap(stack);
}

void	tobottom_if(char tobottom, t_stack *stack, char stacknum)
{
	int		**st;
	int		bottom;
	// char	opp_tobottom;
	void 	(*rotate)(t_stack *stack);

	st = stacknum == 'a' ? &stack->a : &stack->b;
	bottom = stacknum == 'a' ? A_BOTTOM : B_BOTTOM;
	// opp_tobottom = tobottom == SMALLER ? BIGGER : SMALLER;
	rotate = stacknum == 'a' ? ra : rb;

	// if (bottom < *st[0] && bottom < *st[1])
	// 	totop_if(opp_tobottom, stack, stacknum);
	// else
	totop_if(tobottom, stack, stacknum);
	rotate(stack);
	// }
	// if (SMALLER == tobottom && (bottom > st[0] || bottom > st[1]))
	// {
	// 	totop_if(SMALLER, stack, stacknum);
	// 	rotate(stack);
	// }
}

int   push_swap(t_stack *stack)
{
//    while (A_BOTTOM )

	if (A_BOTTOM < stack->a[0] || A_BOTTOM < stack->a[1])
		tobottom_if(BIGGER, stack, 'a');
	else
	{// 더 작은 수를 b로 보낸다. 
		if (stack->a[0] > stack->a[1])
			sa(stack);
		pb(stack);
		if (B_BOTTOM < stack->b[0] || B_BOTTOM < stack->b[1])
		{
			if (stack->b[0] < stack->b[1])
			sa(stack);
			ra(stack);//추가
		}

	}
	return 0;
}
