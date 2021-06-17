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

		if(1){	// INPUT 출력
			printf("^^^^^^^^^^Firt_Input^^^^^^^ㅣ\n");
			for(int z = 0; z < (stack->alen); z++)
				printf("stack a의 %d번째 숫자: %d\n", z, (stack->a)[z]);
			printf("vvvvvvvvvvFirt_Inputvvvvvvvv\n\n");
		}

		if(1){  // SORTING TEST
			sort_arg(stack, stack->alen);
			set_pivot(stack);
			group1_to_stackb(stack);
			group2_to_stackb(stack);
			printf("*********FIN_SORT_IN_STACK B**********\n");
		}





		int tofind = 497;
	printf("TOFIND FIN : %d\n", tofind = search_from_top(stack, 3, tofind));
			printf("^^^^^^^^^^stack a^^^^^^^ㅣ\n");
			for(int z = 0; z < (stack->alen); z++)
				printf("stack a의 %d번째 숫자: %d\n", z, (stack->a)[z]);
			printf("vvvvvvvvvvstack avvvvvvvv\n\n");

			printf("^^^^^^^^^^stack b^^^^^^^ㅣ\n");
			for(int z = 0; z < (stack->blen); z++)
				printf("stack b의 %d번째 숫자: %d\n", z, (stack->b)[z]);
			printf("vvvvvvvvvvstack bvvvvvvvv\n\n");

			printf("0000000000000000000000000\n0000[ COUNT IS : %d ]0000\n0000000000000000000000000\n", stack->count);
		
	free_all(stack);
	system("leaks a.out > leaks_result_temp; cat leaks_result_temp | grep leaked && rm -rf leaks_result_temp");
	// system("leaks a.out");
	return 0;
}