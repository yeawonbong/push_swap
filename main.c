#include "push_swap.h"

int main(int argc, char *argv[])
{
	static t_stack	*stack;
	// if((stack->a = get_arg(argc, argv, stack->a)) == ERROR)
	// 	error(stack->a, stack_b);
	
	
	stack = get_arg(argc, argv, stack);
	for(int z = 0; z < (sizeof(stack->a) / sizeof(int)); z++)
		printf("stack a의 %d번째 숫자: %d\n", z, stack->a[z]);

	// 	t_list	*p;
	// if(1) //연결리스트 출력
	// {
	
	// 	p = stack_a;
	// 	while (p)
	// 	{
	// 		printf("stack content : %d\n", p->content);
	// 		p = p->next;
	// 	}
	// //	printf("stack content : %d\n", p->content); // tail
	// }
	// stack_a = pa(stack_a, stack_b);
	// 	if(1) //연결리스트 출력
	// {
	// 	p = stack_a;
	// 	while (p)
	// 	{
	// 		printf("stack content : %d\n", p->content);
	// 		p = p->next;
	// 	}
	// //	printf("stack content : %d\n", p->content); // tail
	// }
    return 0;
}