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

int main(int argc, char *argv[])
{
	static t_stack	*stack;

	stack = malloc(sizeof(t_stack));
	if(((stack = get_arg(argc, argv, stack))) == ERROR)
		error_exit(stack);
	

	

		if(1){	// 출력test
			printf("^^^^^^^^^^Firt_Input^^^^^^^ㅣ\n");
			for(int z = 0; z < (stack->alen); z++)
				printf("stack a의 %d번째 숫자: %d\n", z, (stack->a)[z]);
			printf("vvvvvvvvvvFirt_Inputvvvvvvvv\n\n");
			
			// group1_to_stackb(stack);
			// push_swap(stack);
			sort_arg(stack, stack->alen);
	// printf("================SORTED_===========\n");
	// for(int z = 0; z < (stack->alen); z++)
	// 	printf("sorted_arr의 %d번째 숫자: %d\n", z, (stack->sorted_arr)[z]);
			group1_to_stackb(stack);
			// group2_to_stackb(stack);
			// sort(stack);
			printf("^^^^^^^^^^group 1 in stack a^^^^^^^ㅣ\n");
			for(int z = 0; z < (stack->alen); z++)
				printf("stack a의 %d번째 숫자: %d\n", z, (stack->a)[z]);
			printf("vvvvvvvvvvgroup 1 in stack avvvvvvvv\n\n");

			printf("^^^^^^^^^^group 2 in stack b^^^^^^^ㅣ\n");
			for(int z = 0; z < (stack->blen); z++)
				printf("stack b의 %d번째 숫자: %d\n", z, (stack->b)[z]);
			printf("vvvvvvvvvvgroup 2 in stack bvvvvvvvv\n\n");
	
			// rb(stack);
			// printf("^^^^^^^^^^AFTER RP stack b^^^^^^^ㅣ\n");
			// for(int z = 0; z < (stack->blen); z++)
			// 	printf("stack b의 %d번째 숫자: %d\n", z, (stack->b)[z]);
			// printf("vvvvvvvvvvAFTER RP stack bvvvvvvvv\n\n");
			printf("0000000000000000000000000\n0000[ COUNT IS : %d ]0000\n0000000000000000000000000\n", stack->count);
	printf("SORTED_BOTTOM IS : %d\n", SORTED_BOTTOM);
		}
	free_all(stack);
	system("leaks a.out > leaks_result_temp; cat leaks_result_temp | grep leaked && rm -rf leaks_result_temp");
	// system("leaks a.out");
	return 0;
}