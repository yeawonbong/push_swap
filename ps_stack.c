#include "push_swap.h"
int		*arr_cpy(int *dst, int *src, int n)
{
	int i;

	i = 0;
	while (i < n)
	{
		dst[i] = src[i];
		i++;
	}
	return (dst);
}

t_stack		*add_back(t_stack *stack, int new)
{
	int		*temp;

	temp = NULL;
	if(!(stack->a))
	{
		printf("first\n");
		temp = malloc(sizeof(int));
		*temp = new;
	}
	else
	{
		temp = malloc(sizeof(int) * (stack->alen + 1));
		temp = arr_cpy(temp, stack->a, stack->alen);
		free(stack->a);
		// temp = ft_memcpy(temp, stack->a, sizeof(int) * stack->alen);
		temp[stack->alen] = new;
		
		for(int z = 0; z < (stack->alen); z++)
			printf("stack temp의 %d번째 숫자: %d\n", z, temp[z]);

	}
	stack->a = temp;
	(stack->alen)++;
	printf("SIZECHECK: %d\n", (stack->alen));
	return (stack);
}