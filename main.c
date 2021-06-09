#include "push_swap.h"

int main(int argc, char *argv[])
{
	static t_stack	*stack;

	stack = malloc(sizeof(t_stack));
	if(((stack = get_arg(argc, argv, stack))) == ERROR)
		error_exit(stack);
	push_swap(stack);
	
	
	
	

																		if(1){	// 출력test
																			printf("^^^^^^^^^^Firt_Input^^^^^^^\n");
																			for(int z = 0; z < (stack->alen); z++)
																				printf("stack a의 %d번째 숫자: %d\n", z, (stack->a)[z]);
																			printf("vvvvvvvvvvFirt_Inputvvvvvvvv\n\n");

																			rrr(stack);
																			
																			printf("================AFTER_===========\n");
																			for(int z = 0; z < (stack->alen); z++)
																				printf("stack a의 %d번째 숫자: %d\n", z, (stack->a)[z]);
																		}
	free_all(stack);
	system("leaks a.out > leaks_result_temp; cat leaks_result_temp | grep leaked && rm -rf leaks_result_temp");
	// system("leaks a.out");
	return 0;
}