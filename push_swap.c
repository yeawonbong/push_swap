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

void    to_bottom_if_bigger(t_stack *stack, char c)
{
	int		bottom=0;
	int		**st=0;
	int		**len=0;
	void 	(*swap)();
	void	(*roatate)();

	bottom = c == 'a' ? stack->a[stack->alen - 1] : stack->b[stack->blen - 1];
	*st = 'a' ? stack->a : stack->b;
	*len = 'a' ? &stack->alen : &stack->blen;
	swap = 'a' ? 

	if (bottom < *st[0] || bottom < *st[1])
	{
		if (*st[0] < *st[1])
			sa(stack);
		ra;//추가
	}
}

int   push_swap(t_stack *stack)
{
//    while (A_BOTTOM )
	if (A_BOTTOM < stack->a[0] || A_BOTTOM < stack->a[1])
	{
		if (stack->a[0] < stack->a[1])
			sa(stack);
		ra;//추가
	}
	else
	{// 더 작은 수를 b로 보낸다. 
		if (stack->a[0] > stack->a[1])
			sa(stack);
		pb(stack);
		if (B_BOTTOM < stack->b[0] || B_BOTTOM < stack->b[1])
		{
			if (stack->b[0] < stack->b[1])
			sa(stack);
			ra;//추가
		}

	}
	return 0;
}


