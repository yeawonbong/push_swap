#include "push_swap.h"

void    free_all(t_stack *stack)
{
	free(stack->a);
	free(stack->b);
	free(stack->sorted_arr);
	free(stack);
}

void    error_exit(t_stack *stack)
{
	free_all(stack);
	write(1, "Error\n", 6);
	exit(EXIT_FAILURE);
}

t_stack		*get_arg(int argc, char *argv[], t_stack *stack)
{
	int		i = 1;
	int 	j = 0;
	char 	**temp=0;
	int 	atoied;
	char	*itoaed;

	if (argc < 2)
		return ERROR;
	while(i < argc)
	{
		temp = ft_split(argv[i++], ' '); //"1 23 4 이럴 경우를 염두, split"
		while (temp[j])
		{
			atoied = ft_atoi(temp[j]);
			if (ft_strlen(itoaed = ft_itoa(atoied)) != ft_strlen(temp[j]))
			{
				free(itoaed);
				return ERROR;
			}
			free(itoaed);
			stack->a = add_back(stack->a, stack->alen, atoied);
			(stack->alen)++;
			free(temp[j]);
			j++;
	 	}
		j = 0;
		free(temp);
	}
	return(stack);
}

void   push_swap(t_stack *stack)
{
	sort_arg(stack, stack->alen);
	set_pivot(stack);
	move_to_stackb(stack);

		printf("*********FIN_SORT_IN_STACK B**********\n");

	sort_stacks(stack, GROUPS - 1, SORTED_BOTTOM - 2);

}

int main(int argc, char *argv[])
{
	static	t_stack	*stack;

	stack = malloc(sizeof(t_stack));
	if(((stack = get_arg(argc, argv, stack))) == ERROR)
		error_exit(stack);

		// if(1){	// INPUT 출력
		// 	printf("^^^^^^^^^^Firt_Input^^^^^^^ㅣ\n");
		// 	for(int z = 0; z < (stack->alen); z++)
		// 		printf("stack a의 %d번째 숫자: %d\n", z, (stack->a)[z]);
		// 	printf("vvvvvvvvvvFirt_Inputvvvvvvvv\n\n");
		// }

	// sort_arg(stack, stack->alen);
	// set_pivot(stack);
	// move_to_stackb(stack);
	
	// 	printf("*********FIN_SORT_IN_STACK B**********\n");

	// sort_stacks(stack, GROUPS - 1, SORTED_BOTTOM - 2);
	push_swap(stack);

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