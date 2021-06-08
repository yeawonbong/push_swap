#include "push_swap.h"

int main(int argc, char *argv[])
{
	static	t_list *stack_a;
	static	t_list *stack_b;
	// t_stack	stack;
	if ((stack_a = get_arg(argc, argv, stack_a)) == ERROR)
		error(stack_a, stack_b);
	

	

		t_list	*p;
	if(1) //연결리스트 출력
	{
	
		p = stack_a;
		while (p)
		{
			printf("stack content : %d\n", p->content);
			p = p->next;
		}
	//	printf("stack content : %d\n", p->content); // tail
	}
	stack_a = pa(stack_a, stack_b);
		if(1) //연결리스트 출력
	{
		p = stack_a;
		while (p)
		{
			printf("stack content : %d\n", p->content);
			p = p->next;
		}
	//	printf("stack content : %d\n", p->content); // tail
	}
    return 0;
}