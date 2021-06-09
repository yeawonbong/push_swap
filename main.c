#include "push_swap.h"

int main(int argc, char *argv[])
{
	static t_stack	*stack;

	stack = malloc(sizeof(t_stack));
	if(((stack = get_arg(argc, argv, stack))) == ERROR)
		free_all(stack);
	// printf("stack->a 뽑기: %p\n", stack->a);
	for(int z = 0; z < (stack->alen); z++)
		printf("stack a의 %d번째 숫자: %d\n", z, (stack->a)[z]);
	free_all(stack);


	// system("leaks a.out > leaks_result_temp; cat leaks_result_temp | grep leaked && rm -rf leaks_result_temp");
	system("leaks a.out");
    return 0;
}